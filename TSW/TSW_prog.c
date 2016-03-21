/*
 * TSW_prog.c
 *
 *  Created on: Feb 13, 2016
 *      Author: Home
 */
#include "types.h"
#include "DIO_interface.h"
#include "TSW_config.h"
#include "TSW_private.h"
#include "TSW_interface.h"


static u8 TSW_SwitchPins[16] = {TSW_PIN0,TSW_PIN1,TSW_PIN2,TSW_PIN3,TSW_PIN4,TSW_PIN5,TSW_PIN6,TSW_PIN7,TSW_PIN8,TSW_PIN9,\
							  TSW_PIN10,TSW_PIN11,TSW_PIN12,TSW_PIN13,TSW_PIN14,TSW_PIN15};

static u8 TSW_u8SwitchParams [4][16] =  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
										 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
										 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
									     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};


extern u8 TSW_u8CheckSW(u8 CopyIdx,u8 *Copy_u8PtrVal)
{	u8 local_returnStatus;


	u8 local_u8readPin = 0;

	switch(TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx])
	{
		case TSW_Released:
			DIO_u8ReadPinVal(TSW_SwitchPins[CopyIdx],&local_u8readPin);
			if(GetBit(TSW_MODE,CopyIdx) == ACTIVELOW){local_u8readPin = !local_u8readPin;}
				switch(local_u8readPin)
				{
				case TSW_HIGH:
								TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Bouncing;
								 *Copy_u8PtrVal= TSW_u8SwitchParams[EXTERNAL_STATES][CopyIdx];
								 local_returnStatus = okay;
								 break;

				case TSW_LOW:
								TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Released;
								TSW_u8SwitchParams[EXTERNAL_STATES][CopyIdx] = TSW_Released;
								 *Copy_u8PtrVal = TSW_u8SwitchParams[EXTERNAL_STATES][CopyIdx];
								 local_returnStatus = okay;
								 break;

				default: local_returnStatus = error;
						 break;
				}
			break;

		case TSW_Bouncing:
				DIO_u8ReadPinVal(TSW_SwitchPins[CopyIdx],&local_u8readPin);
				if(GetBit(TSW_MODE,CopyIdx) == ACTIVELOW){local_u8readPin = !local_u8readPin;}
				switch(local_u8readPin)
				{
				case TSW_HIGH: TSW_u8SwitchParams[LOW_COUNTER][CopyIdx] = 0;
								 TSW_u8SwitchParams[HIGH_COUNTER][CopyIdx]++;
								 local_returnStatus = okay;
								 if ( TSW_u8SwitchParams[HIGH_COUNTER][CopyIdx] == 100){TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Pressed;}
								 break;
				case TSW_LOW: TSW_u8SwitchParams[LOW_COUNTER][CopyIdx]++;
								TSW_u8SwitchParams[HIGH_COUNTER][CopyIdx] = 0;
								local_returnStatus = okay;
								if(TSW_u8SwitchParams[LOW_COUNTER][CopyIdx] == 100){TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Released;}
								break;
				default: local_returnStatus = error;
						 break;
				}

				if( TSW_u8SwitchParams[HIGH_COUNTER][CopyIdx] == 100){TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Released;}
			break;
		case TSW_Pressed:
			DIO_u8ReadPinVal(TSW_PIN1,&local_u8readPin);
			if(GetBit(TSW_MODE,CopyIdx) == ACTIVELOW){local_u8readPin = !local_u8readPin;}
			switch(local_u8readPin)
				{
				case TSW_HIGH:
					TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Pressed;
					TSW_u8SwitchParams[EXTERNAL_STATES][CopyIdx] = TSW_Pressed;
						*Copy_u8PtrVal= TSW_u8SwitchParams[EXTERNAL_STATES][CopyIdx];
						local_returnStatus = okay;
						break;
				case TSW_LOW:
					TSW_u8SwitchParams[INTERNAL_STATES][CopyIdx] = TSW_Bouncing;
							*Copy_u8PtrVal = TSW_u8SwitchParams[EXTERNAL_STATES][CopyIdx];
							local_returnStatus = okay;
							break;

				default:local_returnStatus = error; break;
				}
			break;

		default:local_returnStatus = error; break;
	}
	return local_returnStatus;
}
extern void TSW_VoidInit(void)
{
	DIO_u8ReadPinDir(TSW_PIN1,DIO_u8INPUT);
	DIO_u8ReadPinDir(TSW_PIN2,DIO_u8INPUT);
	DIO_u8ReadPinDir(TSW_PIN3,DIO_u8INPUT);
	DIO_u8ReadPinDir(TSW_PIN4,DIO_u8INPUT);
}
