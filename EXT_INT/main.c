/*
 * main.c
 *
 *  Created on: Mar 29, 2016
 *      Author: Home
 */
#include "types.h"
#include "EXINT_config.h"
#include "EXINT_interface.h"
#include "DIO_interface.h"
#include "delay.h"
#include "KP_interface.h"


void shit0(void)
{
	static volatile u8 count = 0;
		DIO_u8WritePinVal(19,DIO_u8LOW);
		count++;
		if(count == 5)
			{
			DIO_u8WritePinVal(19,DIO_u8HIGH);
			DELAY_MS(10);
			count = 0;
			}
}

void shit1(void)
{
	static volatile u8 count = 0;
		DIO_u8WritePinVal(16,DIO_u8LOW);
		count++;
		if(count == 5)
			{
			DIO_u8WritePinVal(16,DIO_u8HIGH);
			DELAY_MS(10);
			count = 0;
			}
}



int main()
{
	DIO_u8WritePinDir(19,DIO_u8OUTPUT); // led for interrupt 1
	DIO_u8WritePinDir(16,DIO_u8OUTPUT);  // led for interrupt 0
	DIO_u8WritePinDir(6,DIO_u8OUTPUT);	// pwm
	DIO_u8WritePinDir(26,DIO_u8INPUT);	//interrupt 0
	DIO_u8WritePinDir(27,DIO_u8INPUT); //interrupt 1
	EXINT_init();
	callback_INT0_Assign(shit0);
	callback_INT1_Assign(shit1);
	while(1)
	{
		DIO_u8WritePinVal(6,DIO_u8HIGH);
		DELAY_MS(10);
		DIO_u8WritePinVal(6,DIO_u8LOW);
		DELAY_MS(10);
	}
return 0;
}

































