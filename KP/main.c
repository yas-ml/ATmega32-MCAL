/*
 * main.c
 *
 *  Created on: Mar 2, 2016
 *      Author: Home
 */

#include "types.h"
#include "DIO_interface.h"
#include "KP_interface.h"
#include "KP_config.h"

#define S1 20
#define S2 21
#define S3 22
#define S4 23

int main()
{
	KP_Init();
	u16 SwVals;
	u16 copyCount;
	u16 SpeedCounter;
	u8 stepperDrive=1;
	u8 StopFlag;
	u8 ChDirFlag;
	u8 copySwVals;
	DIO_u8WritePinDir(S1,DIO_u8OUTPUT);
	DIO_u8WritePinDir(S2,DIO_u8OUTPUT);
	DIO_u8WritePinDir(S3,DIO_u8OUTPUT);
	DIO_u8WritePinDir(S4,DIO_u8OUTPUT);
//	DIO_u8WritePinVal(KP_SWINPUT1,DIO_u8HIGH);
//	DIO_u8WritePinVal(KP_SWINPUT2,DIO_u8HIGH);
//	DIO_u8WritePinVal(KP_SWINPUT3,DIO_u8HIGH);
//	DIO_u8WritePinVal(KP_SWINPUT4,DIO_u8HIGH);

	while(1)
	{	/*****Read_Keypad******/
		KP_Read(&SwVals);
		/*****check if another input exists******/
		if(copySwVals != SwVals && SwVals != 0)
		{	copySwVals = SwVals;
			KP_Read(&SwVals);
			if(GetBit(SwVals,15) != 0){StopFlag = 1;}else{StopFlag = 0;}/*stops motor*/
			if(GetBit(SwVals,14) != 0){ChDirFlag = 1;}else{ChDirFlag = 0;}/*motor changes direction*/
			if(ChDirFlag != 1 && StopFlag != 1)
			{
				SpeedCounter = SwVals;/***save value from keypad to speed counter***/
				while(SpeedCounter >= 100)
					SpeedCounter = SpeedCounter/100;/***Divide speed counter until it becomes less than 100 as a way to make speeds faster***/
				/****save copy in count****/
				copyCount = SpeedCounter;/***saves the speed counter in variable  to retain it when the speed counter is zero***/
			}
		}
		/*****Decrement******/

		SpeedCounter--;
		/*****Drive******/
		if(SpeedCounter == 0 && StopFlag == 0)/***if the keypad input != to the stop command and speed counter is zero>>> drive the motor one step***/
		{
			SpeedCounter = copyCount;/***retain the value of the speed counter to drive the next step***/
			/***put 1,2,4  or 8 on the pins of the motor to drive it one step***/
			DIO_u8WritePinVal(S1, GetBit(stepperDrive, 0));
			DIO_u8WritePinVal(S2, GetBit(stepperDrive, 1));
			DIO_u8WritePinVal(S3, GetBit(stepperDrive, 2));
			DIO_u8WritePinVal(S4, GetBit(stepperDrive, 3));
			if(ChDirFlag != 1)/***if the keypad input is != change direction then shift the stepperDrive to the left***/
			{

				if(stepperDrive ==0b1000) {stepperDrive = 0b0001;}/***if the stepperDrive is 8 make its value 1 in order for it not to overflow***/
				else{stepperDrive = stepperDrive << 1;}
			}
			else/***if the keypad input is = change direction then shift the stepperDrive to the right***/
			{

				if(stepperDrive == 0b0001){stepperDrive = 0b1000;}/***if the stepperDrive is 1 make its value 8 in order for it not to overflow***/
				else{stepperDrive = stepperDrive >> 1;}
			}
		}
	}
	return 0;
}
