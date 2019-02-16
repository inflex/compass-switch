default: compass-switch

compass-switch: compass-switch.c
	gcc -Wall -O1 compass-switch.c -o compass-switch -lm 
