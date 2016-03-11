// cc -o compass compass.c -lwiringPi -lm
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <math.h>

int main() {
	int fd;
	short dat,x,y,z;
	double angle,mag;
	
	fd = wiringPiI2CSetup(0x1e);	// HMC5883L
	wiringPiI2CWriteReg8(fd,0,0xe0);	// Config A = 0xE0
	wiringPiI2CWriteReg8(fd,2,0x00);	// Continuous Mode

	delay(500);
	dat=wiringPiI2CReadReg8(fd,9);	// Status
	printf("%x\n",dat);

	x=(wiringPiI2CReadReg8(fd,3)<<8) | wiringPiI2CReadReg8(fd,4);
	printf("%d\n",x);

        y=(wiringPiI2CReadReg8(fd,7)<<8) | wiringPiI2CReadReg8(fd,8);
        printf("%d\n",y);

        z=(wiringPiI2CReadReg8(fd,5)<<8) | wiringPiI2CReadReg8(fd,6);
        printf("%d\n",z);

	angle=atan2((short)y,(short)x)*180/3.141592;
	mag=sqrt(x*x+y*y+z*z);

        printf("%f %f\n",angle,mag);

	return(0);
}
