/*
 * Compass switch (for linux)
 *
 * Uses a compass IC to help us switch Open Broadcaster
 * between scenes so that we do not get left with the
 * dreaded failure of doing a bunch of work under the 
 * microscope that isn't being recorded (I need to work
 * on one for sound recording too!)
 *
 * We're using the HMC5833L compass IC which uses i2c
 * to communicate.  Normally this is a walk in the park
 * for when you're dealing with AVR/uC/RPi sysetms that
 * have a nice exposed API and clean ways of talking i2c
 * but in linux/PCs... it's a little bit more fun.
 *
 * A few things learned doing this project, which is
 * always a great outcome!
 *
 * February 14, 2019
 *		0.0.1 - Happy Valentine's
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <arpa/inet.h>
#include <linux/i2c-dev.h>
#include <linux/limits.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

#define SCENE_INACTIVE 0
#define SCENE_ACTIVE 1

#define VERBOSE if (g->verbose)
#define DBG if (gdebug)
#define QUIET if (g->quiet)

#define HMC5883L_ID 0x1e
#define HMC5833L_FRAME_SLEEP 80000 // a little more than the 67ms suggested by datasheet

struct glb {
	int debug; // debugging *duh*
	int verbose;
	int quiet;

	int ubus; // user defined bus

	int scene_state;

	int start_angle;
	int end_angle;

	Display *display;
	int kmods; // 0:ctrl, 1:alt, 2:shift
	int key; // key scan code
};

static int gdebug = 0;

XKeyEvent createKeyEvent(Display *display, Window win, Window winRoot, int press, int keycode, int modifiers) {
	XKeyEvent event;

	event.display     = display;
	event.window      = win;
	event.root        = winRoot;
	event.subwindow   = None;
	event.time        = CurrentTime;
	event.x           = 1;
	event.y           = 1;
	event.x_root      = 1;
	event.y_root      = 1;
	event.same_screen = True;
//	event.same_screen = False;
	event.keycode     = XKeysymToKeycode(display, keycode);
	event.state       = modifiers;

	if(press)
		event.type = KeyPress;
	else
		event.type = KeyRelease;

	return event;
}

void keypress( struct glb *g, int keycode, int state ) {
	XKeyEvent event;
	Window winFocus;
	int modifiers = ShiftMask;
	int revert;

	Window winRoot = XDefaultRootWindow(g->display);
	XGetInputFocus(g->display, &winFocus, &revert);

	event = createKeyEvent(g->display, winFocus, winRoot, state, keycode, modifiers);
	XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
}

void keypress_simulate(struct glb *g, int keycode ) {

//	keypress(g, XK_Shift_L, 1);
	keypress(g, keycode, 1);
	XFlush(g->display);
	usleep(100000);
	keypress(g, keycode, 0);
//	keypress(g, XK_Shift_L, 0);
	XFlush(g->display);

}


static int i2c_open_bus( int bus ) {
	int file;
	char filename[PATH_MAX];
	snprintf(filename, sizeof(filename), "/dev/i2c-%d", bus);
	if ((file = open(filename, O_RDWR)) < 0) {
		DBG fprintf(stderr,"Failed to open the i2c bus (%s)\n", strerror(errno));
	}

	return file;
}

int i2c_close_bus( int bus ) {
	return close(bus);
}


static int i2c_set_device(int busfd, int addr) {
	int ret = ioctl(busfd, I2C_SLAVE, addr);
	if (ret < 0) {
		DBG fprintf(stderr,"Failed to acquire bus access and/or talk to slave. (%s)\n", strerror(errno));
	}

	return ret;
}

static int i2c_read_bus(int busfd, unsigned char *buf, int bufsize) {
	return read(busfd, buf, bufsize);
}

static int i2c_write_bus(int busfd, unsigned char *buf, int bufsize) {
	return write(busfd, buf, bufsize);
}

static int i2c_read_register(int busfd, uint8_t reg, unsigned char *buf, int bufsize) {
	int ret;

	ret = i2c_write_bus(busfd, &reg, 1);
	if (ret < 0) {
		DBG fprintf(stderr,"Failed to write register address %02x (%s)\n", reg, strerror(errno));
		return ret;
	}

	return i2c_read_bus(busfd, buf, bufsize);
}

int16_t twos2dec_16( unsigned char *raw ) {

	/*
	 * Convert 2's complement big-endian 16-bit integer
	 * in to a 16-bit int (intel)
	 *
	 * We have to first see if the high bit is set to 
	 * indicate a negative number, if it is, we need
	 * to invert the bits in both bytes, assemble in to
	 * a little-endian integer, and *then* add 1 to the
	 * result and cast back in to a 16-bit integer.
	 *
	 * For non-negative numbers, we can just assemble 
	 * the two bytes in to  little-endian form and 
	 * cast to 16-bit int.
	 *
	 */

	uint32_t tmp = 0;
	int16_t result = 0;

	if ((raw[0] & 0x80) == 0x80) {
		// high bit is set, negative number
		raw[0] = ~(raw[0]);
		raw[1] = ~(raw[1]);
		tmp = (raw[0] << 8) | raw[1];
		result = (int16_t)(tmp +1);
		result = -result;

	} else {
		// no high bit set, just assemble normally
		result = (int16_t)((raw[0] << 8) | raw[1]);
	}

	return result;
}

int i2c_write_register_byte( int fh, uint8_t reg, uint8_t data ) {
	/*
	 * Write a byte value to a register with an 8-bit address
	 *
	 */
	unsigned char buf[2];
	ssize_t ws = 0;

	buf[0] = reg;
	buf[1] = data;
	ws = i2c_write_bus(fh, buf, 2);
	if (ws != 2) {
		DBG fprintf(stderr,"Couldn't write register address [ %x ] (%s)\n", reg, strerror(errno)); 
	}

	return ws;
}


int is_hmc5883( int file ) {
	/*
	 * ID check the device to see if it is 
	 * the HMC5883 compass device
	 *
	 * It should have H43 as the ID starting
	 * at register 0x0A.
	 *
	 */
	uint8_t buf[3];
	int rc = 0;

	rc = i2c_read_register(file, 0x0A, buf, 3); // A, B and C contain our ID
	DBG fprintf(stderr,"%c %c %c\n", buf[0], buf[1], buf[2]);
	if (rc != 3) return 0;

	return (buf[0] == 'H' && buf[1] == '4' && buf[2] == '3');
}

void show_help(void) {
}

int parse_parameters( struct glb *g, int argc, char **argv ) {
	int i;

	for (i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			/* parameter */
			switch (argv[i][1]) {

				case 'h':
					show_help();
					exit(1);
					break;

				case 'b':
					/*
					 * com port can be multiple things in linux
					 * such as /dev/ttySx or /dev/ttyUSBxx
					 */
					i++;
					if (i < argc) {
						g->ubus = atoi(argv[i]);
					} else {
						fprintf(stdout,"Insufficient parameters; -b <bus number>\n");
						exit(1);
					}
					break;

				case 's':
					/* 
					 * output file where this program will put the text
					 * line containing the information FlexBV will want 
					 *
					 */
					i++;
					if (i < argc) {
						g->start_angle = atoi(argv[i]);
					} else {
						fprintf(stdout,"Insufficient parameters; -s <start angle (0:360)>\n");
						exit(1);
					}
					break;

				case 'e':
					i++;
					if (i < argc) {
						g->end_angle = atoi(argv[i]);
					} else {
						fprintf(stdout,"Insufficient parameters; -e <end angle (0:360)>\n");
						exit(1);
					}
					break;

				case 'k':
					i++;
					if (i < argc) {
						g->key = atoi(argv[i]);
					} else {
						fprintf(stdout,"Insufficient parameters; -k <keyboard code (dec)>\n");
						exit(1);
					}
					break;


				case 'd': g->debug = 1; g->verbose = 1; break;

				case 'q': g->quiet = 1; break;

				case 'v': g->verbose = 1; break;

				default: break;
			} // switch
		}
	}


	return 0;
}

int main(int argc, char **argv) {

	int file;
	int bid = 0;
	int found = 0;
	struct glb gg;
	struct glb *g = &gg;

	g->debug = 0;
	g->verbose = 0;
	g->quiet = 0;
	g->ubus = -1;
	g->start_angle = -1;
	g->end_angle = -1;
	g->scene_state = SCENE_INACTIVE;
	g->display = XOpenDisplay(0);
	if (!g->display) {
		fprintf(stderr,"Could not get X display (%s)\n", strerror(errno));
		return 1;
	}

	parse_parameters(g, argc, argv);

	gdebug = g->debug;

	// If the user has requested a specific bus
	if (g->ubus) bid = g->ubus;

	do {
		VERBOSE fprintf(stderr,"Trying i2c bus ID %d...", bid);
		file = i2c_open_bus(bid);
		if (file > 0) {
			if (i2c_set_device(file, HMC5883L_ID) >= 0) {
				if (is_hmc5883(file)) {
					VERBOSE fprintf(stderr,"Success\n");
					found = 1;
					break;
				}
			}
			i2c_close_bus(file);
		}
		VERBOSE fprintf(stderr,"fail\n");
		if (g->ubus >= 0) break;
		bid++;
	} while ((bid < 16) && (!found));

	if (!found) {
		VERBOSE fprintf(stderr,"Could not find the compass chip.\n");
		exit(1);
	}

	{
		unsigned char buf[512];
		int32_t x, y; // z isn't used in planar compass setup

		DBG {
			i2c_read_register(file, 0, buf, 3);
			for (x = 0; x < 3; x++) {
				fprintf(stdout, "%02x ", buf[x]);
			}
			fprintf(stdout, "\r\n"); fflush(stdout);
		}

		i2c_write_register_byte(file, 0x00, 0x70);
		i2c_write_register_byte(file, 0x01, 0xA0);
		i2c_write_register_byte(file, 0x02, 0x00);

		DBG {
			i2c_read_register(file, 0, buf, 3);
			for (x = 0; x < 3; x++) {
				fprintf(stdout, "%02x ", buf[x]);
			}

			fprintf(stdout, "\r\n"); fflush(stdout);
		}

		while (1) { 
			double heading;

			i2c_read_register(file, 0x03, buf, 6);
			x = twos2dec_16(buf);
			//z = twos2dec_16(buf +2); // Z isn't used in our setup
			y = twos2dec_16(buf +4);

			heading = atan2(x, y) *(180.0 / M_PI);
			if (heading < 0) heading += 360;
			heading = 360 -heading;

			VERBOSE {
				fprintf(stdout,"\r%03.1f ", heading);
				fflush(stdout);
			}

			if ((heading > g->start_angle) && (heading < g->end_angle)) {
				if (g->scene_state == SCENE_INACTIVE) {
					g->scene_state = SCENE_ACTIVE;
					/* One shot, hit the key */
					fprintf(stderr,"\nACTIVE\n");
				//	keypress_simulate(g, XK_F5);
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_Shift_L), True, CurrentTime);
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_F5), True, CurrentTime);
					XFlush(g->display);
					usleep(100000);
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_F5), False, CurrentTime);  
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_Shift_L), False, CurrentTime);
					XFlush(g->display);
				}
			} else {
				if (g->scene_state == SCENE_ACTIVE) {
					g->scene_state = SCENE_INACTIVE;
					/* One shot, hit the key */
					fprintf(stderr,"\nIN-ACTIVE\n");
				//	keypress_simulate(g, XK_F6);
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_Shift_L), True, CurrentTime);
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_F6), True, CurrentTime);
					XFlush(g->display);
					usleep(100000);
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_F6), False, CurrentTime);  
					XTestFakeKeyEvent(g->display, XKeysymToKeycode(g->display, XK_Shift_L), False, CurrentTime);
					XFlush(g->display);
				}
			}

			usleep(HMC5833L_FRAME_SLEEP);
		}
	}


	return 0;
}
