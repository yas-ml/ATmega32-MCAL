/*
 * main.c
 *
 *  Created on: Feb 25, 2016
 *      Author: Yaser
 */

#include  "types.h"
#include  "DIO_interface.h"
#include  "TSW_config.h"
#include  "TSW_interface.h"
#include  "KP_config.h"
#include "KP_interface.h"
#define S1 10
#define S2 11
#define S3 12
#define S4 13


#define   Data               26
#define   Shift              24
#define   Start              25
#define   False               0
#define   True                1
#define motorPin1  		      8
#define motorPin2  	          9
#define SwtichMotor           4

#define  Motor_u8LEFT         0
#define  Motor_u8RIGHT        1
#define  Motor_u8OFF          0
#define  Motor_u8ON           1
#define  THREESECONDS       250
#define DISPNUM               2
static const u8 ROW[3][8] = {{0b00111111,0b00111111,0b00111111,0b00111111,0b00111111,0b00111111,0b00000000,0b00000000},{0b00000001,0b01111110,0b00000001,0b00111111,0b01011111,0b01101111,0b01101111,0b01110011},{0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111}};

void MotorToggle(u8 local_u8MotorState,u8 local_u8MotorDirection)
{
	switch(local_u8MotorState)
	{
		case Motor_u8OFF:
			DIO_u8WritePinVal(motorPin1,0);
			DIO_u8WritePinVal(motorPin2,0);
			break;
		case Motor_u8ON:
			switch(local_u8MotorDirection)
			{
			case Motor_u8LEFT:
				DIO_u8WritePinVal(motorPin1,1);
				DIO_u8WritePinVal(motorPin2,0);
				break;
			case Motor_u8RIGHT:
				DIO_u8WritePinVal(motorPin1,0);
				DIO_u8WritePinVal(motorPin2,1);
				break;
			default:break;
			}
			break;

		default:break;

	}
}

int main(void)
{

//	DIO_u8WritePinVal(KP_SWINPUT1,DIO_u8HIGH);
//	DIO_u8WritePinVal(KP_SWINPUT2,DIO_u8HIGH);
//	DIO_u8WritePinVal(KP_SWINPUT3,DIO_u8HIGH);
//	DIO_u8WritePinVal(KP_SWINPUT4,DIO_u8HIGH);
	///////////////////////////////////////////////////////////////////////
	static u8  local_u8MotorState = Motor_u8OFF;
	u16 local_u8threeSecCount   =     0;
	u8  local_u8MotorDirection = Motor_u8LEFT;
	u8  local_readValue = 0;
	u8 u8Motorflag = 0;
	DIO_u8WritePinDir(SwtichMotor,0);
	DIO_u8WritePinDir(motorPin1,1);
	DIO_u8WritePinDir(motorPin2,1);
	/////////////////////////////////////////////////////////////////////
	u8 col;u8 Column;u8 i;
	DIO_u8WritePinDir(Shift,1);
	DIO_u8WritePinDir(Data,1);
	DIO_u8WritePinDir(Start,1);
	////////////////////////////////////////////////////////////////////
	KeypadInit();
	DIO_u8WritePinDir(S1,DIO_u8OUTPUT);
	DIO_u8WritePinDir(S2,DIO_u8OUTPUT);
	DIO_u8WritePinDir(S3,DIO_u8OUTPUT);
	DIO_u8WritePinDir(S4,DIO_u8OUTPUT);


	while(1)
	{	if(local_u8MotorState == Motor_u8ON)
		{
		col = 1;
			for (i = 0; i < 8; i++) {

				for (Column = 0; Column < 8; Column++) {
					DIO_u8WritePinVal(Data,
							GetBit(ROW[local_u8MotorDirection][i], Column));
					DIO_u8WritePinVal(Shift, 1);
					//DELAY_MS(1);
					DIO_u8WritePinVal(Shift, 0);
					//DELAY_MS(1);
				}
				for (Column = 0; Column < 8; Column++) {
					DIO_u8WritePinVal(Data, GetBit(col, Column));
					DIO_u8WritePinVal(Shift, 1);
					//DELAY_MS(1);
					DIO_u8WritePinVal(Shift, 0);
					//DELAY_MS(1);
				}

				if (i != 7)
					col = col << 1;

				DIO_u8WritePinVal(Start, 1);

				//	DELAY_MS(3);
				DIO_u8WritePinVal(Start, 0);
			}
		}
	else
	{
		col = 1;
					for (i = 0; i < 8; i++) {

						for (Column = 0; Column < 8; Column++) {
							DIO_u8WritePinVal(Data,
									GetBit(ROW[2][i], Column));
							DIO_u8WritePinVal(Shift, 1);
							//DELAY_MS(1);
							DIO_u8WritePinVal(Shift, 0);
							//DELAY_MS(1);
						}
						for (Column = 0; Column < 8; Column++) {
							DIO_u8WritePinVal(Data, GetBit(col, Column));
							DIO_u8WritePinVal(Shift, 1);
							//DELAY_MS(1);
							DIO_u8WritePinVal(Shift, 0);
							//DELAY_MS(1);
						}

						if (i != 7)
							col = col << 1;

						DIO_u8WritePinVal(Start, 1);

						//	DELAY_MS(3);
						DIO_u8WritePinVal(Start, 0);
										}
	}
	/*************************************************************************************/
		TSW_u8CheckSW(SwtichMotor,&local_readValue);
		if(local_readValue == TSW_Pressed && u8Motorflag == 0)
		{
			local_u8MotorState =! local_u8MotorState; //on
			MotorToggle(local_u8MotorState,local_u8MotorDirection);
			u8Motorflag = 1;
		}
		local_u8threeSecCount++;
		TSW_u8CheckSW(SwtichMotor,&local_readValue);
		if(local_u8threeSecCount >= THREESECONDS && local_readValue == TSW_Released && local_u8MotorState == Motor_u8ON)
		{
			local_u8MotorState =! local_u8MotorState;
			MotorToggle(local_u8MotorState,local_u8MotorDirection);//off
			local_u8MotorDirection =! local_u8MotorDirection;
			local_u8threeSecCount = 0;
			u8Motorflag = 0;
		}
		else if(local_readValue == TSW_Released)
		{
			local_u8threeSecCount = 0;
			u8Motorflag = 0;
		}
		/*******************************************************************************/

	}


return 0;
}

