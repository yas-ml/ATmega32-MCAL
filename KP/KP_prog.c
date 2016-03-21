/*
 * KP_prog.c
 *
 *  Created on: Feb 29, 2016
 *      Author: Home
 *
 */
#include "types.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "KP_config.h"
#include "KP_interface.h"
#include "KP_private.h"

static u8 KP_SwitchPins[16] = {KP_PIN1,KP_PIN2,KP_PIN3,KP_PIN4,KP_PIN5,KP_PIN6,KP_PIN7,KP_PIN8,KP_PIN9,\
							  KP_PIN10,KP_PIN11,KP_PIN12,KP_PIN13,KP_PIN14,KP_PIN15,KP_PIN16};

static u16 KP_u8SwitchParams [4][16] =  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
										 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
										 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

static u16 KP_Switches;

const u8 KP_Pins_Input [NO_OF_KP_PINS] = {KP_SWINPUT1,KP_SWINPUT2,KP_SWINPUT3,KP_SWINPUT4};
const u8 KP_Pins_Output [NO_OF_KP_PINS] = {KP_SWOUTPUT1,KP_SWOUTPUT2,KP_SWOUTPUT3,KP_SWOUTPUT4};

extern void KP_Init(void)
{
	DIO_u8WritePinDir(KP_SWINPUT1,DIO_u8INPUT);
	DIO_u8WritePinDir(KP_SWINPUT2,DIO_u8INPUT);
	DIO_u8WritePinDir(KP_SWINPUT3,DIO_u8INPUT);
	DIO_u8WritePinDir(KP_SWINPUT4,DIO_u8INPUT);

	DIO_u8WritePinDir(KP_SWOUTPUT1,DIO_u8OUTPUT);
	DIO_u8WritePinDir(KP_SWOUTPUT2,DIO_u8OUTPUT);
	DIO_u8WritePinDir(KP_SWOUTPUT3,DIO_u8OUTPUT);
	DIO_u8WritePinDir(KP_SWOUTPUT4,DIO_u8OUTPUT);
}

//extern void KP_Read(u16 * KP_ptr)
//{ 	u8 local_u8Read;
//	u8 local_u8count;
//	for(local_u8count = 0;local_u8count<NO_OF_KP_PINS;local_u8count++)
//	{	/*write pin values*/
//		DIO_u8WritePinVal(KP_Pins[local_u8count], DIO_u8HIGH);
//		if(local_u8count)/*make the last pin value = 0*/
//			DIO_u8WritePinVal(KP_Pins[local_u8count - 1], DIO_u8LOW);
//
//		/*read pin values*/
//		DIO_u8ReadPinVal(KP_SWINPUT1,(KP_ptr+(local_u8count*4)));
//		DIO_u8ReadPinVal(KP_SWINPUT2,(KP_ptr+(local_u8count*4)+1));
//		DIO_u8ReadPinVal(KP_SWINPUT3,(KP_ptr+(local_u8count*4)+2));
//		DIO_u8ReadPinVal(KP_SWINPUT4,(KP_ptr+(local_u8count*4)+3));
//	}/*make the last pin value = 0*/
//	DIO_u8WritePinVal(KP_Pins[local_u8count - 1], DIO_u8LOW);
//	KP_Switches = *KP_ptr;
//
//}

//extern Keypad KP_Read()
//{	u8 local_u8ReadVals;
//
//
//		DIO_u8WritePinVal(KP_SWOUTPUT1,DIO_u8HIGH);
//		DIO_u8WritePinVal(KP_SWOUTPUT2,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT3,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT4,DIO_u8LOW);
//
//		KP_u8CheckSW(0,&local_u8ReadVals);
//		KP.KP_SW1 = local_u8ReadVals;
//		KP_u8CheckSW(1,&local_u8ReadVals);
//		KP.KP_SW2 = local_u8ReadVals;
//		KP_u8CheckSW(2,&local_u8ReadVals);
//		KP.KP_SW3 = local_u8ReadVals;
//		KP_u8CheckSW(3,&local_u8ReadVals);
//		KP.KP_SW4 = local_u8ReadVals;
//		/**************************************************************/
//		DIO_u8WritePinVal(KP_SWOUTPUT1,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT2,DIO_u8HIGH);
//		DIO_u8WritePinVal(KP_SWOUTPUT3,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT4,DIO_u8LOW);
//
//		KP_u8CheckSW(4,&local_u8ReadVals);
//		KP.KP_SW5 = local_u8ReadVals;
//		KP_u8CheckSW(5,&local_u8ReadVals);
//		KP.KP_SW6 = local_u8ReadVals;
//		KP_u8CheckSW(6,&local_u8ReadVals);
//		KP.KP_SW7 = local_u8ReadVals;
//		KP_u8CheckSW(7,&local_u8ReadVals);
//		KP.KP_SW8 = local_u8ReadVals;
//		/**************************************************************/
//		DIO_u8WritePinVal(KP_SWOUTPUT1,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT2,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT3,DIO_u8HIGH);
//		DIO_u8WritePinVal(KP_SWOUTPUT4,DIO_u8LOW);
//
//		KP_u8CheckSW(8,&local_u8ReadVals);
//		KP.KP_SW9 = local_u8ReadVals;
//		KP_u8CheckSW(9,&local_u8ReadVals);
//		KP.KP_SW10 = local_u8ReadVals;
//		KP_u8CheckSW(10,&local_u8ReadVals);
//		KP.KP_SW11 = local_u8ReadVals;
//		KP_u8CheckSW(11,&local_u8ReadVals);
//		KP.KP_SW12 = local_u8ReadVals;
//		/**************************************************************/
//		DIO_u8WritePinVal(KP_SWOUTPUT1,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT2,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT3,DIO_u8LOW);
//		DIO_u8WritePinVal(KP_SWOUTPUT4,DIO_u8HIGH);
//
//		KP_u8CheckSW(12,&local_u8ReadVals);
//		KP.KP_SW13 = local_u8ReadVals;
//		KP_u8CheckSW(13,&local_u8ReadVals);
//		KP.KP_SW14 = local_u8ReadVals;
//		KP_u8CheckSW(14,&local_u8ReadVals);
//		KP.KP_SW15 = local_u8ReadVals;
//		KP_u8CheckSW(15,&local_u8ReadVals);
//		KP.KP_SW16 = local_u8ReadVals;
//
//
//	return KP;
//}
extern void KP_Read(u16 * KP_ptr)
{ 	u8 local_u8countRead;u8 local_u8countWrite;

	for(local_u8countWrite = 0;local_u8countWrite<NO_OF_KP_PINS;local_u8countWrite++)
	{	/*write pin values*/
		DIO_u8WritePinVal(KP_Pins_Output[local_u8countWrite], DIO_u8HIGH);
		/*read pin values*/
		for(local_u8countRead = 0;local_u8countRead<NO_OF_KP_PINS;local_u8countRead++)
		KP_u8CheckSW(local_u8countRead+(4*local_u8countWrite),KP_ptr);

		DIO_u8WritePinVal(KP_Pins_Output[local_u8countWrite], DIO_u8LOW);
	}/*make the last pin value = 0*/

	KP_Switches = *KP_ptr;

}
extern u8 KP_ReadSW(u8 Copy_u8idx, u8 *Copy_Val)
{	u8 local_u8returnStatus = okay;

	if(Copy_u8idx<16)
	*Copy_Val = GetBit(KP_Switches,Copy_u8idx);

	else
		local_u8returnStatus = error;

	return local_u8returnStatus;
}

extern u8 KP_u8CheckSW(u8 CopyIdx,u16 *Copy_u8PtrVal)
{	static u16 ExternalState = 0;
	u8 local_returnStatus = error;
	u8 local_u8readPin;
				DIO_u8ReadPinVal(KP_SwitchPins[CopyIdx],&local_u8readPin);
				if(GetBit(KP_MODE,CopyIdx) == ACTIVELOW){local_u8readPin = !local_u8readPin;}

	switch(KP_u8SwitchParams[INTERNAL_STATES][CopyIdx])
	{
		case KP_Released:

				switch(local_u8readPin)
				{
				case KP_HIGH:
								KP_u8SwitchParams[INTERNAL_STATES][CopyIdx] = KP_Bouncing;
								 *Copy_u8PtrVal= ExternalState;
								 local_returnStatus = okay;
								 break;

				case KP_LOW:
								KP_u8SwitchParams[INTERNAL_STATES][CopyIdx] = KP_Released;
								ClrBit(ExternalState,CopyIdx);
								 *Copy_u8PtrVal = ExternalState;
								 local_returnStatus = okay;
								 break;

				default: local_returnStatus = error;
						 break;
				}
			break;

		case KP_Bouncing:

				switch(local_u8readPin)
				{
				case KP_HIGH: KP_u8SwitchParams[LOW_COUNTER][CopyIdx] = 0;
								 KP_u8SwitchParams[HIGH_COUNTER][CopyIdx]++;
								 local_returnStatus = okay;
								 if ( KP_u8SwitchParams[HIGH_COUNTER][CopyIdx] == NO_OF_TICKS){KP_u8SwitchParams[INTERNAL_STATES][CopyIdx] = KP_Pressed;}
								 break;
				case KP_LOW: KP_u8SwitchParams[LOW_COUNTER][CopyIdx]++;
								KP_u8SwitchParams[HIGH_COUNTER][CopyIdx] = 0;
								local_returnStatus = okay;
								if(KP_u8SwitchParams[LOW_COUNTER][CopyIdx] == NO_OF_TICKS){KP_u8SwitchParams[INTERNAL_STATES][CopyIdx] = KP_Released;}
								break;
				default: local_returnStatus = error;
						 break;
				}
				break;

		case KP_Pressed:
			switch(local_u8readPin)
				{
				case KP_HIGH:
					KP_u8SwitchParams[INTERNAL_STATES][CopyIdx] = KP_Pressed;
					SetBit(ExternalState,CopyIdx);
						*Copy_u8PtrVal= ExternalState;
						local_returnStatus = okay;
						break;
				case KP_LOW:
					KP_u8SwitchParams[INTERNAL_STATES][CopyIdx] = KP_Bouncing;
							*Copy_u8PtrVal = ExternalState;
							local_returnStatus = okay;
							break;

				default:local_returnStatus = error; break;
				}
			break;

		default:local_returnStatus = error; break;
	}
	return local_returnStatus;
}

