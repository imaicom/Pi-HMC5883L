// cc -o compassTest compassTest -lwiringPi
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main() {
	int fd , dat;
	
	fd = wiringPiI2CSetup(0x1e);
	wiringPiI2CWrite(fd,0x0a);
	dat = wiringPiI2CRead(fd);
	printf("%x\n",dat);

        wiringPiI2CWrite(fd,0x0b);
        dat = wiringPiI2CRead(fd);
        printf("%x\n",dat);

        wiringPiI2CWrite(fd,0x0c);
        dat = wiringPiI2CRead(fd);
        printf("%x\n",dat);

	return(0);
}
