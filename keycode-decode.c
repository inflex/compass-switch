#include <stdlib.h>
#include <string.h>
#include <linux/uinput.h>

#include "keycode-decode.h"

// --key-active KEY_LEFTCTRL:KEY_LEFTALT:KEY_F5
//

int is_match( char *a, char *b ) {
	int result;

	result = strcmp(a,b);
	
	if (result == 0) return 1;
	else return 0;
}

int keycode_decode( char *input ) {
	int keyvalue = -1;

	if (is_match(input,"KEY_RESERVED")) keyvalue = 0; 
	if (is_match(input,"KEY_ESC")) keyvalue = 1; 
	if (is_match(input,"KEY_1")) keyvalue = 2; 
	if (is_match(input,"KEY_2")) keyvalue = 3; 
	if (is_match(input,"KEY_3")) keyvalue = 4; 
	if (is_match(input,"KEY_4")) keyvalue = 5; 
	if (is_match(input,"KEY_5")) keyvalue = 6; 
	if (is_match(input,"KEY_6")) keyvalue = 7; 
	if (is_match(input,"KEY_7")) keyvalue = 8; 
	if (is_match(input,"KEY_8")) keyvalue = 9; 
	if (is_match(input,"KEY_9")) keyvalue = 10; 
	if (is_match(input,"KEY_0")) keyvalue = 11; 
	if (is_match(input,"KEY_MINUS")) keyvalue = 12; 
	if (is_match(input,"KEY_EQUAL")) keyvalue = 13; 
	if (is_match(input,"KEY_BACKSPACE")) keyvalue = 14; 
	if (is_match(input,"KEY_TAB")) keyvalue = 15; 
	if (is_match(input,"KEY_Q")) keyvalue = 16; 
	if (is_match(input,"KEY_W")) keyvalue = 17; 
	if (is_match(input,"KEY_E")) keyvalue = 18; 
	if (is_match(input,"KEY_R")) keyvalue = 19; 
	if (is_match(input,"KEY_T")) keyvalue = 20; 
	if (is_match(input,"KEY_Y")) keyvalue = 21; 
	if (is_match(input,"KEY_U")) keyvalue = 22; 
	if (is_match(input,"KEY_I")) keyvalue = 23; 
	if (is_match(input,"KEY_O")) keyvalue = 24; 
	if (is_match(input,"KEY_P")) keyvalue = 25; 
	if (is_match(input,"KEY_LEFTBRACE")) keyvalue = 26; 
	if (is_match(input,"KEY_RIGHTBRACE")) keyvalue = 27; 
	if (is_match(input,"KEY_ENTER")) keyvalue = 28; 
	if (is_match(input,"KEY_LEFTCTRL")) keyvalue = 29; 
	if (is_match(input,"KEY_A")) keyvalue = 30; 
	if (is_match(input,"KEY_S")) keyvalue = 31; 
	if (is_match(input,"KEY_D")) keyvalue = 32; 
	if (is_match(input,"KEY_F")) keyvalue = 33; 
	if (is_match(input,"KEY_G")) keyvalue = 34; 
	if (is_match(input,"KEY_H")) keyvalue = 35; 
	if (is_match(input,"KEY_J")) keyvalue = 36; 
	if (is_match(input,"KEY_K")) keyvalue = 37; 
	if (is_match(input,"KEY_L")) keyvalue = 38; 
	if (is_match(input,"KEY_SEMICOLON")) keyvalue = 39; 
	if (is_match(input,"KEY_APOSTROPHE")) keyvalue = 40; 
	if (is_match(input,"KEY_GRAVE")) keyvalue = 41; 
	if (is_match(input,"KEY_LEFTSHIFT")) keyvalue = 42; 
	if (is_match(input,"KEY_BACKSLASH")) keyvalue = 43; 
	if (is_match(input,"KEY_Z")) keyvalue = 44; 
	if (is_match(input,"KEY_X")) keyvalue = 45; 
	if (is_match(input,"KEY_C")) keyvalue = 46; 
	if (is_match(input,"KEY_V")) keyvalue = 47; 
	if (is_match(input,"KEY_B")) keyvalue = 48; 
	if (is_match(input,"KEY_N")) keyvalue = 49; 
	if (is_match(input,"KEY_M")) keyvalue = 50; 
	if (is_match(input,"KEY_COMMA")) keyvalue = 51; 
	if (is_match(input,"KEY_DOT")) keyvalue = 52; 
	if (is_match(input,"KEY_SLASH")) keyvalue = 53; 
	if (is_match(input,"KEY_RIGHTSHIFT")) keyvalue = 54; 
	if (is_match(input,"KEY_KPASTERISK")) keyvalue = 55; 
	if (is_match(input,"KEY_LEFTALT")) keyvalue = 56; 
	if (is_match(input,"KEY_SPACE")) keyvalue = 57; 
	if (is_match(input,"KEY_CAPSLOCK")) keyvalue = 58; 
	if (is_match(input,"KEY_F1")) keyvalue = 59; 
	if (is_match(input,"KEY_F2")) keyvalue = 60; 
	if (is_match(input,"KEY_F3")) keyvalue = 61; 
	if (is_match(input,"KEY_F4")) keyvalue = 62; 
	if (is_match(input,"KEY_F5")) keyvalue = 63; 
	if (is_match(input,"KEY_F6")) keyvalue = 64; 
	if (is_match(input,"KEY_F7")) keyvalue = 65; 
	if (is_match(input,"KEY_F8")) keyvalue = 66; 
	if (is_match(input,"KEY_F9")) keyvalue = 67; 
	if (is_match(input,"KEY_F10")) keyvalue = 68; 
	if (is_match(input,"KEY_NUMLOCK")) keyvalue = 69; 
	if (is_match(input,"KEY_SCROLLLOCK")) keyvalue = 70; 
	if (is_match(input,"KEY_KP7")) keyvalue = 71; 
	if (is_match(input,"KEY_KP8")) keyvalue = 72; 
	if (is_match(input,"KEY_KP9")) keyvalue = 73; 
	if (is_match(input,"KEY_KPMINUS")) keyvalue = 74; 
	if (is_match(input,"KEY_KP4")) keyvalue = 75; 
	if (is_match(input,"KEY_KP5")) keyvalue = 76; 
	if (is_match(input,"KEY_KP6")) keyvalue = 77; 
	if (is_match(input,"KEY_KPPLUS")) keyvalue = 78; 
	if (is_match(input,"KEY_KP1")) keyvalue = 79; 
	if (is_match(input,"KEY_KP2")) keyvalue = 80; 
	if (is_match(input,"KEY_KP3")) keyvalue = 81; 
	if (is_match(input,"KEY_KP0")) keyvalue = 82; 
	if (is_match(input,"KEY_KPDOT")) keyvalue = 83; 

	if (is_match(input,"KEY_ZENKAKUHANKAKU")) keyvalue = 85; 
	if (is_match(input,"KEY_102ND")) keyvalue = 86; 
	if (is_match(input,"KEY_F11")) keyvalue = 87; 
	if (is_match(input,"KEY_F12")) keyvalue = 88; 
	if (is_match(input,"KEY_RO")) keyvalue = 89; 
	if (is_match(input,"KEY_KATAKANA")) keyvalue = 90; 
	if (is_match(input,"KEY_HIRAGANA")) keyvalue = 91; 
	if (is_match(input,"KEY_HENKAN")) keyvalue = 92; 
	if (is_match(input,"KEY_KATAKANAHIRAGANA")) keyvalue = 93; 
	if (is_match(input,"KEY_MUHENKAN")) keyvalue = 94; 
	if (is_match(input,"KEY_KPJPCOMMA")) keyvalue = 95; 
	if (is_match(input,"KEY_KPENTER")) keyvalue = 96; 
	if (is_match(input,"KEY_RIGHTCTRL")) keyvalue = 97; 
	if (is_match(input,"KEY_KPSLASH")) keyvalue = 98; 
	if (is_match(input,"KEY_SYSRQ")) keyvalue = 99; 
	if (is_match(input,"KEY_RIGHTALT")) keyvalue = 100; 
	if (is_match(input,"KEY_LINEFEED")) keyvalue = 101; 
	if (is_match(input,"KEY_HOME")) keyvalue = 102; 
	if (is_match(input,"KEY_UP")) keyvalue = 103; 
	if (is_match(input,"KEY_PAGEUP")) keyvalue = 104; 
	if (is_match(input,"KEY_LEFT")) keyvalue = 105; 
	if (is_match(input,"KEY_RIGHT")) keyvalue = 106; 
	if (is_match(input,"KEY_END")) keyvalue = 107; 
	if (is_match(input,"KEY_DOWN")) keyvalue = 108; 
	if (is_match(input,"KEY_PAGEDOWN")) keyvalue = 109; 
	if (is_match(input,"KEY_INSERT")) keyvalue = 110; 
	if (is_match(input,"KEY_DELETE")) keyvalue = 111; 
	if (is_match(input,"KEY_MACRO")) keyvalue = 112; 
	if (is_match(input,"KEY_MUTE")) keyvalue = 113; 
	if (is_match(input,"KEY_VOLUMEDOWN")) keyvalue = 114; 
	if (is_match(input,"KEY_VOLUMEUP")) keyvalue = 115; 
	if (is_match(input,"KEY_POWER")) keyvalue = 116; 
	if (is_match(input,"KEY_KPEQUAL")) keyvalue = 117; 
	if (is_match(input,"KEY_KPPLUSMINUS")) keyvalue = 118; 
	if (is_match(input,"KEY_PAUSE")) keyvalue = 119; 
	if (is_match(input,"KEY_SCALE")) keyvalue = 120; 

	if (is_match(input,"KEY_KPCOMMA")) keyvalue = 121; 
	if (is_match(input,"KEY_HANGEUL")) keyvalue = 122; 
	if (is_match(input,"KEY_HANGUEL")) keyvalue = KEY_HANGEUL; 
	if (is_match(input,"KEY_HANJA")) keyvalue = 123; 
	if (is_match(input,"KEY_YEN")) keyvalue = 124; 
	if (is_match(input,"KEY_LEFTMETA")) keyvalue = 125; 
	if (is_match(input,"KEY_RIGHTMETA")) keyvalue = 126; 
	if (is_match(input,"KEY_COMPOSE")) keyvalue = 127; 

	if (is_match(input,"KEY_STOP")) keyvalue = 128; 
	if (is_match(input,"KEY_AGAIN")) keyvalue = 129; 
	if (is_match(input,"KEY_PROPS")) keyvalue = 130; 
	if (is_match(input,"KEY_UNDO")) keyvalue = 131; 
	if (is_match(input,"KEY_FRONT")) keyvalue = 132; 
	if (is_match(input,"KEY_COPY")) keyvalue = 133; 
	if (is_match(input,"KEY_OPEN")) keyvalue = 134; 
	if (is_match(input,"KEY_PASTE")) keyvalue = 135; 
	if (is_match(input,"KEY_FIND")) keyvalue = 136; 
	if (is_match(input,"KEY_CUT")) keyvalue = 137; 
	if (is_match(input,"KEY_HELP")) keyvalue = 138; 
	if (is_match(input,"KEY_MENU")) keyvalue = 139; 
	if (is_match(input,"KEY_CALC")) keyvalue = 140; 
	if (is_match(input,"KEY_SETUP")) keyvalue = 141; 
	if (is_match(input,"KEY_SLEEP")) keyvalue = 142; 
	if (is_match(input,"KEY_WAKEUP")) keyvalue = 143; 
	if (is_match(input,"KEY_FILE")) keyvalue = 144; 
	if (is_match(input,"KEY_SENDFILE")) keyvalue = 145; 
	if (is_match(input,"KEY_DELETEFILE")) keyvalue = 146; 
	if (is_match(input,"KEY_XFER")) keyvalue = 147; 
	if (is_match(input,"KEY_PROG1")) keyvalue = 148; 
	if (is_match(input,"KEY_PROG2")) keyvalue = 149; 
	if (is_match(input,"KEY_WWW")) keyvalue = 150; 
	if (is_match(input,"KEY_MSDOS")) keyvalue = 151; 
	if (is_match(input,"KEY_COFFEE")) keyvalue = 152; 
	if (is_match(input,"KEY_SCREENLOCK")) keyvalue = KEY_COFFEE; 
	if (is_match(input,"KEY_ROTATE_DISPLAY")) keyvalue = 153; 
	if (is_match(input,"KEY_DIRECTION")) keyvalue = KEY_ROTATE_DISPLAY; 
	if (is_match(input,"KEY_CYCLEWINDOWS")) keyvalue = 154; 
	if (is_match(input,"KEY_MAIL")) keyvalue = 155; 
	if (is_match(input,"KEY_BOOKMARKS")) keyvalue = 156; 
	if (is_match(input,"KEY_COMPUTER")) keyvalue = 157; 
	if (is_match(input,"KEY_BACK")) keyvalue = 158; 
	if (is_match(input,"KEY_FORWARD")) keyvalue = 159; 
	if (is_match(input,"KEY_CLOSECD")) keyvalue = 160; 
	if (is_match(input,"KEY_EJECTCD")) keyvalue = 161; 
	if (is_match(input,"KEY_EJECTCLOSECD")) keyvalue = 162; 
	if (is_match(input,"KEY_NEXTSONG")) keyvalue = 163; 
	if (is_match(input,"KEY_PLAYPAUSE")) keyvalue = 164; 
	if (is_match(input,"KEY_PREVIOUSSONG")) keyvalue = 165; 
	if (is_match(input,"KEY_STOPCD")) keyvalue = 166; 
	if (is_match(input,"KEY_RECORD")) keyvalue = 167; 
	if (is_match(input,"KEY_REWIND")) keyvalue = 168; 
	if (is_match(input,"KEY_PHONE")) keyvalue = 169; 
	if (is_match(input,"KEY_ISO")) keyvalue = 170; 
	if (is_match(input,"KEY_CONFIG")) keyvalue = 171; 
	if (is_match(input,"KEY_HOMEPAGE")) keyvalue = 172; 
	if (is_match(input,"KEY_REFRESH")) keyvalue = 173; 
	if (is_match(input,"KEY_EXIT")) keyvalue = 174; 
	if (is_match(input,"KEY_MOVE")) keyvalue = 175; 
	if (is_match(input,"KEY_EDIT")) keyvalue = 176; 
	if (is_match(input,"KEY_SCROLLUP")) keyvalue = 177; 
	if (is_match(input,"KEY_SCROLLDOWN")) keyvalue = 178; 
	if (is_match(input,"KEY_KPLEFTPAREN")) keyvalue = 179; 
	if (is_match(input,"KEY_KPRIGHTPAREN")) keyvalue = 180; 
	if (is_match(input,"KEY_NEW")) keyvalue = 181; 
	if (is_match(input,"KEY_REDO")) keyvalue = 182; 

	if (is_match(input,"KEY_F13")) keyvalue = 183; 
	if (is_match(input,"KEY_F14")) keyvalue = 184; 
	if (is_match(input,"KEY_F15")) keyvalue = 185; 
	if (is_match(input,"KEY_F16")) keyvalue = 186; 
	if (is_match(input,"KEY_F17")) keyvalue = 187; 
	if (is_match(input,"KEY_F18")) keyvalue = 188; 
	if (is_match(input,"KEY_F19")) keyvalue = 189; 
	if (is_match(input,"KEY_F20")) keyvalue = 190; 
	if (is_match(input,"KEY_F21")) keyvalue = 191; 
	if (is_match(input,"KEY_F22")) keyvalue = 192; 
	if (is_match(input,"KEY_F23")) keyvalue = 193; 
	if (is_match(input,"KEY_F24")) keyvalue = 194; 

	if (is_match(input,"KEY_PLAYCD")) keyvalue = 200; 
	if (is_match(input,"KEY_PAUSECD")) keyvalue = 201; 
	if (is_match(input,"KEY_PROG3")) keyvalue = 202; 
	if (is_match(input,"KEY_PROG4")) keyvalue = 203; 
	if (is_match(input,"KEY_DASHBOARD")) keyvalue = 204; 
	if (is_match(input,"KEY_SUSPEND")) keyvalue = 205; 
	if (is_match(input,"KEY_CLOSE")) keyvalue = 206; 
	if (is_match(input,"KEY_PLAY")) keyvalue = 207; 
	if (is_match(input,"KEY_FASTFORWARD")) keyvalue = 208; 
	if (is_match(input,"KEY_BASSBOOST")) keyvalue = 209; 
	if (is_match(input,"KEY_PRINT")) keyvalue = 210; 
	if (is_match(input,"KEY_HP")) keyvalue = 211; 
	if (is_match(input,"KEY_CAMERA")) keyvalue = 212; 
	if (is_match(input,"KEY_SOUND")) keyvalue = 213; 
	if (is_match(input,"KEY_QUESTION")) keyvalue = 214; 
	if (is_match(input,"KEY_EMAIL")) keyvalue = 215; 
	if (is_match(input,"KEY_CHAT")) keyvalue = 216; 
	if (is_match(input,"KEY_SEARCH")) keyvalue = 217; 
	if (is_match(input,"KEY_CONNECT")) keyvalue = 218; 
	if (is_match(input,"KEY_FINANCE")) keyvalue = 219; 
	if (is_match(input,"KEY_SPORT")) keyvalue = 220; 
	if (is_match(input,"KEY_SHOP")) keyvalue = 221; 
	if (is_match(input,"KEY_ALTERASE")) keyvalue = 222; 
	if (is_match(input,"KEY_CANCEL")) keyvalue = 223; 
	if (is_match(input,"KEY_BRIGHTNESSDOWN")) keyvalue = 224; 
	if (is_match(input,"KEY_BRIGHTNESSUP")) keyvalue = 225; 
	if (is_match(input,"KEY_MEDIA")) keyvalue = 226; 

	if (is_match(input,"KEY_SWITCHVIDEOMODE")) keyvalue = 227; 
	if (is_match(input,"KEY_KBDILLUMTOGGLE")) keyvalue = 228; 
	if (is_match(input,"KEY_KBDILLUMDOWN")) keyvalue = 229; 
	if (is_match(input,"KEY_KBDILLUMUP")) keyvalue = 230; 

	if (is_match(input,"KEY_SEND")) keyvalue = 231; 
	if (is_match(input,"KEY_REPLY")) keyvalue = 232; 
	if (is_match(input,"KEY_FORWARDMAIL")) keyvalue = 233; 
	if (is_match(input,"KEY_SAVE")) keyvalue = 234; 
	if (is_match(input,"KEY_DOCUMENTS")) keyvalue = 235; 

	if (is_match(input,"KEY_BATTERY")) keyvalue = 236; 

	if (is_match(input,"KEY_BLUETOOTH")) keyvalue = 237; 
	if (is_match(input,"KEY_WLAN")) keyvalue = 238; 
	if (is_match(input,"KEY_UWB")) keyvalue = 239; 

	if (is_match(input,"KEY_UNKNOWN")) keyvalue = 240; 

	if (is_match(input,"KEY_VIDEO_NEXT")) keyvalue = 241; 
	if (is_match(input,"KEY_VIDEO_PREV")) keyvalue = 242; 
	if (is_match(input,"KEY_BRIGHTNESS_CYCLE")) keyvalue = 243; 
	if (is_match(input,"KEY_BRIGHTNESS_AUTO")) keyvalue = 244; 
	if (is_match(input,"KEY_BRIGHTNESS_ZERO")) keyvalue = KEY_BRIGHTNESS_AUTO; 
	if (is_match(input,"KEY_DISPLAY_OFF")) keyvalue = 245; 

	if (is_match(input,"KEY_WWAN")) keyvalue = 246; 
	if (is_match(input,"KEY_WIMAX")) keyvalue = KEY_WWAN; 
	if (is_match(input,"KEY_RFKILL")) keyvalue = 247; 

	if (is_match(input,"KEY_MICMUTE")) keyvalue = 248;

	return keyvalue;
}
