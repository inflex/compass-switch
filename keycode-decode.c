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

	if (is_match(input,"RESERVED")) keyvalue = 0; 
	if (is_match(input,"ESC")) keyvalue = 1; 
	if (is_match(input,"1")) keyvalue = 2; 
	if (is_match(input,"2")) keyvalue = 3; 
	if (is_match(input,"3")) keyvalue = 4; 
	if (is_match(input,"4")) keyvalue = 5; 
	if (is_match(input,"5")) keyvalue = 6; 
	if (is_match(input,"6")) keyvalue = 7; 
	if (is_match(input,"7")) keyvalue = 8; 
	if (is_match(input,"8")) keyvalue = 9; 
	if (is_match(input,"9")) keyvalue = 10; 
	if (is_match(input,"0")) keyvalue = 11; 
	if (is_match(input,"MINUS")) keyvalue = 12; 
	if (is_match(input,"EQUAL")) keyvalue = 13; 
	if (is_match(input,"BACKSPACE")) keyvalue = 14; 
	if (is_match(input,"TAB")) keyvalue = 15; 
	if (is_match(input,"Q")) keyvalue = 16; 
	if (is_match(input,"W")) keyvalue = 17; 
	if (is_match(input,"E")) keyvalue = 18; 
	if (is_match(input,"R")) keyvalue = 19; 
	if (is_match(input,"T")) keyvalue = 20; 
	if (is_match(input,"Y")) keyvalue = 21; 
	if (is_match(input,"U")) keyvalue = 22; 
	if (is_match(input,"I")) keyvalue = 23; 
	if (is_match(input,"O")) keyvalue = 24; 
	if (is_match(input,"P")) keyvalue = 25; 
	if (is_match(input,"LEFTBRACE")) keyvalue = 26; 
	if (is_match(input,"RIGHTBRACE")) keyvalue = 27; 
	if (is_match(input,"ENTER")) keyvalue = 28; 
	if (is_match(input,"LEFTCTRL")) keyvalue = 29; 
	if (is_match(input,"CTRL")) keyvalue = KEY_LEFTCTRL; 
	if (is_match(input,"A")) keyvalue = 30; 
	if (is_match(input,"S")) keyvalue = 31; 
	if (is_match(input,"D")) keyvalue = 32; 
	if (is_match(input,"F")) keyvalue = 33; 
	if (is_match(input,"G")) keyvalue = 34; 
	if (is_match(input,"H")) keyvalue = 35; 
	if (is_match(input,"J")) keyvalue = 36; 
	if (is_match(input,"K")) keyvalue = 37; 
	if (is_match(input,"L")) keyvalue = 38; 
	if (is_match(input,"SEMICOLON")) keyvalue = 39; 
	if (is_match(input,"APOSTROPHE")) keyvalue = 40; 
	if (is_match(input,"GRAVE")) keyvalue = 41; 
	if (is_match(input,"LEFTSHIFT")) keyvalue = 42; 
	if (is_match(input,"SHIFT")) keyvalue = KEY_LEFTSHIFT; 
	if (is_match(input,"BACKSLASH")) keyvalue = 43; 
	if (is_match(input,"Z")) keyvalue = 44; 
	if (is_match(input,"X")) keyvalue = 45; 
	if (is_match(input,"C")) keyvalue = 46; 
	if (is_match(input,"V")) keyvalue = 47; 
	if (is_match(input,"B")) keyvalue = 48; 
	if (is_match(input,"N")) keyvalue = 49; 
	if (is_match(input,"M")) keyvalue = 50; 
	if (is_match(input,"COMMA")) keyvalue = 51; 
	if (is_match(input,"DOT")) keyvalue = 52; 
	if (is_match(input,"SLASH")) keyvalue = 53; 
	if (is_match(input,"RIGHTSHIFT")) keyvalue = 54; 
	if (is_match(input,"KPASTERISK")) keyvalue = 55; 
	if (is_match(input,"LEFTALT")) keyvalue = 56; 
	if (is_match(input,"ALT")) keyvalue = KEY_LEFTALT; 
	if (is_match(input,"SPACE")) keyvalue = 57; 
	if (is_match(input,"CAPSLOCK")) keyvalue = 58; 
	if (is_match(input,"F1")) keyvalue = 59; 
	if (is_match(input,"F2")) keyvalue = 60; 
	if (is_match(input,"F3")) keyvalue = 61; 
	if (is_match(input,"F4")) keyvalue = 62; 
	if (is_match(input,"F5")) keyvalue = 63; 
	if (is_match(input,"F6")) keyvalue = 64; 
	if (is_match(input,"F7")) keyvalue = 65; 
	if (is_match(input,"F8")) keyvalue = 66; 
	if (is_match(input,"F9")) keyvalue = 67; 
	if (is_match(input,"F10")) keyvalue = 68; 
	if (is_match(input,"NUMLOCK")) keyvalue = 69; 
	if (is_match(input,"SCROLLLOCK")) keyvalue = 70; 
	if (is_match(input,"KP7")) keyvalue = 71; 
	if (is_match(input,"KP8")) keyvalue = 72; 
	if (is_match(input,"KP9")) keyvalue = 73; 
	if (is_match(input,"KPMINUS")) keyvalue = 74; 
	if (is_match(input,"KP4")) keyvalue = 75; 
	if (is_match(input,"KP5")) keyvalue = 76; 
	if (is_match(input,"KP6")) keyvalue = 77; 
	if (is_match(input,"KPPLUS")) keyvalue = 78; 
	if (is_match(input,"KP1")) keyvalue = 79; 
	if (is_match(input,"KP2")) keyvalue = 80; 
	if (is_match(input,"KP3")) keyvalue = 81; 
	if (is_match(input,"KP0")) keyvalue = 82; 
	if (is_match(input,"KPDOT")) keyvalue = 83; 

	if (is_match(input,"ZENKAKUHANKAKU")) keyvalue = 85; 
	if (is_match(input,"102ND")) keyvalue = 86; 
	if (is_match(input,"F11")) keyvalue = 87; 
	if (is_match(input,"F12")) keyvalue = 88; 
	if (is_match(input,"RO")) keyvalue = 89; 
	if (is_match(input,"KATAKANA")) keyvalue = 90; 
	if (is_match(input,"HIRAGANA")) keyvalue = 91; 
	if (is_match(input,"HENKAN")) keyvalue = 92; 
	if (is_match(input,"KATAKANAHIRAGANA")) keyvalue = 93; 
	if (is_match(input,"MUHENKAN")) keyvalue = 94; 
	if (is_match(input,"KPJPCOMMA")) keyvalue = 95; 
	if (is_match(input,"KPENTER")) keyvalue = 96; 
	if (is_match(input,"RIGHTCTRL")) keyvalue = 97; 
	if (is_match(input,"KPSLASH")) keyvalue = 98; 
	if (is_match(input,"SYSRQ")) keyvalue = 99; 
	if (is_match(input,"RIGHTALT")) keyvalue = 100; 
	if (is_match(input,"LINEFEED")) keyvalue = 101; 
	if (is_match(input,"HOME")) keyvalue = 102; 
	if (is_match(input,"UP")) keyvalue = 103; 
	if (is_match(input,"PAGEUP")) keyvalue = 104; 
	if (is_match(input,"LEFT")) keyvalue = 105; 
	if (is_match(input,"RIGHT")) keyvalue = 106; 
	if (is_match(input,"END")) keyvalue = 107; 
	if (is_match(input,"DOWN")) keyvalue = 108; 
	if (is_match(input,"PAGEDOWN")) keyvalue = 109; 
	if (is_match(input,"INSERT")) keyvalue = 110; 
	if (is_match(input,"DELETE")) keyvalue = 111; 
	if (is_match(input,"MACRO")) keyvalue = 112; 
	if (is_match(input,"MUTE")) keyvalue = 113; 
	if (is_match(input,"VOLUMEDOWN")) keyvalue = 114; 
	if (is_match(input,"VOLUMEUP")) keyvalue = 115; 
	if (is_match(input,"POWER")) keyvalue = 116; 
	if (is_match(input,"KPEQUAL")) keyvalue = 117; 
	if (is_match(input,"KPPLUSMINUS")) keyvalue = 118; 
	if (is_match(input,"PAUSE")) keyvalue = 119; 
	if (is_match(input,"SCALE")) keyvalue = 120; 

	if (is_match(input,"KPCOMMA")) keyvalue = 121; 
	if (is_match(input,"HANGEUL")) keyvalue = 122; 
	if (is_match(input,"HANGUEL")) keyvalue = KEY_HANGEUL; 
	if (is_match(input,"HANJA")) keyvalue = 123; 
	if (is_match(input,"YEN")) keyvalue = 124; 
	if (is_match(input,"LEFTMETA")) keyvalue = 125; 
	if (is_match(input,"RIGHTMETA")) keyvalue = 126; 
	if (is_match(input,"META")) keyvalue = KEY_LEFTMETA; 

	if (is_match(input,"COMPOSE")) keyvalue = 127; 

	if (is_match(input,"STOP")) keyvalue = 128; 
	if (is_match(input,"AGAIN")) keyvalue = 129; 
	if (is_match(input,"PROPS")) keyvalue = 130; 
	if (is_match(input,"UNDO")) keyvalue = 131; 
	if (is_match(input,"FRONT")) keyvalue = 132; 
	if (is_match(input,"COPY")) keyvalue = 133; 
	if (is_match(input,"OPEN")) keyvalue = 134; 
	if (is_match(input,"PASTE")) keyvalue = 135; 
	if (is_match(input,"FIND")) keyvalue = 136; 
	if (is_match(input,"CUT")) keyvalue = 137; 
	if (is_match(input,"HELP")) keyvalue = 138; 
	if (is_match(input,"MENU")) keyvalue = 139; 
	if (is_match(input,"CALC")) keyvalue = 140; 
	if (is_match(input,"SETUP")) keyvalue = 141; 
	if (is_match(input,"SLEEP")) keyvalue = 142; 
	if (is_match(input,"WAKEUP")) keyvalue = 143; 
	if (is_match(input,"FILE")) keyvalue = 144; 
	if (is_match(input,"SENDFILE")) keyvalue = 145; 
	if (is_match(input,"DELETEFILE")) keyvalue = 146; 
	if (is_match(input,"XFER")) keyvalue = 147; 
	if (is_match(input,"PROG1")) keyvalue = 148; 
	if (is_match(input,"PROG2")) keyvalue = 149; 
	if (is_match(input,"WWW")) keyvalue = 150; 
	if (is_match(input,"MSDOS")) keyvalue = 151; 
	if (is_match(input,"COFFEE")) keyvalue = 152; 
	if (is_match(input,"SCREENLOCK")) keyvalue = KEY_COFFEE; 
	if (is_match(input,"ROTATE_DISPLAY")) keyvalue = 153; 
	if (is_match(input,"DIRECTION")) keyvalue = KEY_ROTATE_DISPLAY; 
	if (is_match(input,"CYCLEWINDOWS")) keyvalue = 154; 
	if (is_match(input,"MAIL")) keyvalue = 155; 
	if (is_match(input,"BOOKMARKS")) keyvalue = 156; 
	if (is_match(input,"COMPUTER")) keyvalue = 157; 
	if (is_match(input,"BACK")) keyvalue = 158; 
	if (is_match(input,"FORWARD")) keyvalue = 159; 
	if (is_match(input,"CLOSECD")) keyvalue = 160; 
	if (is_match(input,"EJECTCD")) keyvalue = 161; 
	if (is_match(input,"EJECTCLOSECD")) keyvalue = 162; 
	if (is_match(input,"NEXTSONG")) keyvalue = 163; 
	if (is_match(input,"PLAYPAUSE")) keyvalue = 164; 
	if (is_match(input,"PREVIOUSSONG")) keyvalue = 165; 
	if (is_match(input,"STOPCD")) keyvalue = 166; 
	if (is_match(input,"RECORD")) keyvalue = 167; 
	if (is_match(input,"REWIND")) keyvalue = 168; 
	if (is_match(input,"PHONE")) keyvalue = 169; 
	if (is_match(input,"ISO")) keyvalue = 170; 
	if (is_match(input,"CONFIG")) keyvalue = 171; 
	if (is_match(input,"HOMEPAGE")) keyvalue = 172; 
	if (is_match(input,"REFRESH")) keyvalue = 173; 
	if (is_match(input,"EXIT")) keyvalue = 174; 
	if (is_match(input,"MOVE")) keyvalue = 175; 
	if (is_match(input,"EDIT")) keyvalue = 176; 
	if (is_match(input,"SCROLLUP")) keyvalue = 177; 
	if (is_match(input,"SCROLLDOWN")) keyvalue = 178; 
	if (is_match(input,"KPLEFTPAREN")) keyvalue = 179; 
	if (is_match(input,"KPRIGHTPAREN")) keyvalue = 180; 
	if (is_match(input,"NEW")) keyvalue = 181; 
	if (is_match(input,"REDO")) keyvalue = 182; 

	if (is_match(input,"F13")) keyvalue = 183; 
	if (is_match(input,"F14")) keyvalue = 184; 
	if (is_match(input,"F15")) keyvalue = 185; 
	if (is_match(input,"F16")) keyvalue = 186; 
	if (is_match(input,"F17")) keyvalue = 187; 
	if (is_match(input,"F18")) keyvalue = 188; 
	if (is_match(input,"F19")) keyvalue = 189; 
	if (is_match(input,"F20")) keyvalue = 190; 
	if (is_match(input,"F21")) keyvalue = 191; 
	if (is_match(input,"F22")) keyvalue = 192; 
	if (is_match(input,"F23")) keyvalue = 193; 
	if (is_match(input,"F24")) keyvalue = 194; 

	if (is_match(input,"PLAYCD")) keyvalue = 200; 
	if (is_match(input,"PAUSECD")) keyvalue = 201; 
	if (is_match(input,"PROG3")) keyvalue = 202; 
	if (is_match(input,"PROG4")) keyvalue = 203; 
	if (is_match(input,"DASHBOARD")) keyvalue = 204; 
	if (is_match(input,"SUSPEND")) keyvalue = 205; 
	if (is_match(input,"CLOSE")) keyvalue = 206; 
	if (is_match(input,"PLAY")) keyvalue = 207; 
	if (is_match(input,"FASTFORWARD")) keyvalue = 208; 
	if (is_match(input,"BASSBOOST")) keyvalue = 209; 
	if (is_match(input,"PRINT")) keyvalue = 210; 
	if (is_match(input,"HP")) keyvalue = 211; 
	if (is_match(input,"CAMERA")) keyvalue = 212; 
	if (is_match(input,"SOUND")) keyvalue = 213; 
	if (is_match(input,"QUESTION")) keyvalue = 214; 
	if (is_match(input,"EMAIL")) keyvalue = 215; 
	if (is_match(input,"CHAT")) keyvalue = 216; 
	if (is_match(input,"SEARCH")) keyvalue = 217; 
	if (is_match(input,"CONNECT")) keyvalue = 218; 
	if (is_match(input,"FINANCE")) keyvalue = 219; 
	if (is_match(input,"SPORT")) keyvalue = 220; 
	if (is_match(input,"SHOP")) keyvalue = 221; 
	if (is_match(input,"ALTERASE")) keyvalue = 222; 
	if (is_match(input,"CANCEL")) keyvalue = 223; 
	if (is_match(input,"BRIGHTNESSDOWN")) keyvalue = 224; 
	if (is_match(input,"BRIGHTNESSUP")) keyvalue = 225; 
	if (is_match(input,"MEDIA")) keyvalue = 226; 

	if (is_match(input,"SWITCHVIDEOMODE")) keyvalue = 227; 
	if (is_match(input,"KBDILLUMTOGGLE")) keyvalue = 228; 
	if (is_match(input,"KBDILLUMDOWN")) keyvalue = 229; 
	if (is_match(input,"KBDILLUMUP")) keyvalue = 230; 

	if (is_match(input,"SEND")) keyvalue = 231; 
	if (is_match(input,"REPLY")) keyvalue = 232; 
	if (is_match(input,"FORWARDMAIL")) keyvalue = 233; 
	if (is_match(input,"SAVE")) keyvalue = 234; 
	if (is_match(input,"DOCUMENTS")) keyvalue = 235; 

	if (is_match(input,"BATTERY")) keyvalue = 236; 

	if (is_match(input,"BLUETOOTH")) keyvalue = 237; 
	if (is_match(input,"WLAN")) keyvalue = 238; 
	if (is_match(input,"UWB")) keyvalue = 239; 

	if (is_match(input,"UNKNOWN")) keyvalue = 240; 

	if (is_match(input,"VIDEO_NEXT")) keyvalue = 241; 
	if (is_match(input,"VIDEO_PREV")) keyvalue = 242; 
	if (is_match(input,"BRIGHTNESS_CYCLE")) keyvalue = 243; 
	if (is_match(input,"BRIGHTNESS_AUTO")) keyvalue = 244; 
	if (is_match(input,"BRIGHTNESS_ZERO")) keyvalue = KEY_BRIGHTNESS_AUTO; 
	if (is_match(input,"DISPLAY_OFF")) keyvalue = 245; 

	if (is_match(input,"WWAN")) keyvalue = 246; 
	if (is_match(input,"WIMAX")) keyvalue = KEY_WWAN; 
	if (is_match(input,"RFKILL")) keyvalue = 247; 

	if (is_match(input,"MICMUTE")) keyvalue = 248;

	return keyvalue;
}
