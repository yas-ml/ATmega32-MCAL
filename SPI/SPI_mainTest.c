/*
 * SPI_mainTest.c
 *
 *  Created on: Apr 8, 2016
 *      Author: Home
 */

#include "types.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

#define SS			12
#define MOSI		13
#define MISO		14
#define SCK			15
#define INT			 0



void SPI_ISR_Main()
{
	static u8 toggle = 1;
	static u8 no_of_ints = 0;


	if(no_of_ints == 10)
	{
	DIO_u8WritePinVal(INT,toggle);
	toggle = !toggle;

	no_of_ints = 0;
	}
	no_of_ints++;
}



int main()
{	/********************Init Functions******************************/
	u8 local_u8count = 0;
	DIO_voidInit();
	SPI_voidInit();
	//__asm__("SEI");
	/***********************Assign Interrupt**********************/
	SPI_callBackFunc_Assign(SPI_ISR_Main);
	/*********************Set Master and Slave*******************/
	DIO_u8WritePinVal(SS,DIO_u8LOW);
	/***************Send continuous ones and zeros to blink********/
	while(1)
	{
		for(local_u8count = 0;local_u8count<8;local_u8count++)
			SPI_Send(0xff);

		for(local_u8count = 0;local_u8count<8;local_u8count++)
			SPI_Send(0);

	}

	return 0;
}
