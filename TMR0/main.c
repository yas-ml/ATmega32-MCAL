/*
 * main.c
 *
 *  Created on: Apr 1, 2016
 *      Author: Home
 */

#include "types.h"
#include "TMR0_interface.h"
#include "DIO_interface.h"

//void a7a()
//{
//	static volatile u8 OverFlowTimes =0;
//	if(OverFlowTimes %2 == 0)
//	{DIO_u8WritePinVal(1,DIO_u8HIGH);}
//	else
//	{DIO_u8WritePinVal(1,DIO_u8LOW);}
//	OverFlowTimes++;
//	if(OverFlowTimes == 10)
//		TMR0_Disable();
//}
//int main()
//{
//	u8 ticks;
//	TMR0_Init();
//	callback_TMR0_Assign(&a7a);
//	DIO_u8WritePinDir(1,DIO_u8OUTPUT);
//	DIO_u8WritePinDir(2,DIO_u8OUTPUT);
//
//	while(1)
//	{
//		TMR0_ReadCurrentTicks(&ticks);
//		if(ticks > 150)
//		{DIO_u8WritePinVal(2,DIO_u8HIGH);}
//		else
//		{DIO_u8WritePinVal(2,DIO_u8LOW);}
//	}
//return 0;
//}

void Timer()
{
	static u8 tog_timer = 0;
	DIO_u8WritePinVal(0,tog_timer);
	tog_timer = !tog_timer;
}

void OutComp()
{
		static u8 tog_OutComp = 0;
		DIO_u8WritePinVal(1,tog_OutComp);
		tog_OutComp = !tog_OutComp;
}

int main()
{
	DIO_voidInit();
	TMR0_Init();
	callback_OCR0_Assign(OutComp);
	callback_TMR0_Assign(Timer);
	TMR0_OCVal_Assign(1);
	OCR0_Enable();

	while(1);

}
