/*
 * main.c
 *
 *  Created on: Mar 2, 2016
 *      Author: Home
 */
#include "types.h"

#include "DIO_interface.h"
#include "BIST_interface.h"

int main()
{
	u8 checkPattern;
	BIST_Init();
	while(1)
	{
		DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8HIGH);
		DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8LOW);
		//delay
		checkPattern = BIST_CheckPattern(1);
		if(checkPattern != okay)
			break;
		DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8LOW);
		DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8HIGH);
		checkPattern = BIST_CheckPattern(2);
		if(checkPattern != okay)
			break;
	}
	return 0;
}
