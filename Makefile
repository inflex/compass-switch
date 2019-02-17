default: compass-switch

i2c.o: i2c.c i2c.h
	gcc -Wall -O1 i2c.c -c

clean:
	rm *.o compass-switch

compass-switch: compass-switch.c i2c.o
	gcc -Wall -O1 compass-switch.c i2c.o -o compass-switch -lm 

