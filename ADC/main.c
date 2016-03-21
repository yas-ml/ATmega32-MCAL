/*
 * main.c
 *  Created on: Mar 18, 2016
 *      Author: Home
 */
#include "types.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

int main()
{
	ADC_INIT();
	ADC_Enable();
	u16 copyPtr = 0;
	DIO_u8WritePortDir(1,0b11111111);
	//DIO_u8WritePortVal(1,0b11111111);
	while(1)
	{
		ADC_ReadCh(0, &copyPtr,1,1);

		if(copyPtr <= (u16)0b1000000000)
			DIO_u8WritePortVal(1,0x03);
		else if(copyPtr > (u16)0b1000000000)
			DIO_u8WritePortVal(1,0x0f);
	}
	return 0;
}

