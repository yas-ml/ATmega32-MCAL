/*
 * ADC_prog.c
 *
 *  Created on: Mar 9, 2016
 *      Author: Home
 */
#include "types.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
const u8 ADC_MUX[8] = {0b00000000,0b00000001,0b00000010,0b00000011,0b00000100,0b00000101,0b00000110,0b00000111};
static u8 ADC_EnableState = INITIAL_STATE;
extern void ADC_INIT()
{
	/*************Enable ADC******************/
		#if INITIAL_STATE == ENABLED
		SetBit(ADCSRA,ADEN);
		#elif INITIAL_STATE==DISABLED
		ClrBit(ADCSRA,ADEN);
		#endif
	/*************Check if ADCx is ON or OFF from config and set pin direction******************/
	#if ADC0 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN0,DIO_u8INPUT);
	#endif
	#if ADC1 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN1,DIO_u8INPUT);
	#endif
	#if ADC2 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN2,DIO_u8INPUT);
	#endif
	#if ADC3 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN3,DIO_u8INPUT);
	#endif
	#if ADC4 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN4,DIO_u8INPUT);
	#endif
	#if ADC5 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN5,DIO_u8INPUT);
	#endif
	#if ADC6 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN6,DIO_u8INPUT);
	#endif
	#if ADC7 == CH_ON
	DIO_u8WritePinDir(DIO_u8PIN7,DIO_u8INPUT);
	#endif

	/*************Set left or right adjustment******************/
	SetBit(ADMUX,ADLAR);

	/*****************************set free running mode*************/
	SFIOR = SFIOR & 00011111;
	/*************Set type of VREFSELECTION******************/
	#if VREFSELECTION==AREF
	ClrBit(ADMUX,REFS1);
	ClrBit(ADMUX,REFS0);
	#elif VREFSELECTION==AVCC
	ClrBit(ADMUX,REFS1);
	SetBit(ADMUX,REFS0);
	#elif VREFSELECTION==INTERNAL
	SetBit(ADMUX,REFS1);
	SetBit(ADMUX,REFS0);
	#endif
	/*************Enable Auto-conversion as well as start conversion******************/
	#if INITIAL_STATE == ENABLED && TRIGGERMODE == AUTOMODE
	SetBit(ADCSRA,ADSC);
	SetBit(ADCSRA,ADATE);
	#endif

	/*************Set Prescalar******************/
	#if PRESCALAR == RANGE1
		ClrBit(ADCSRA,ADPS2);
		ClrBit(ADCSRA,ADPS1);
		ClrBit(ADCSRA,ADPS0);
	#elif PRESCALAR == RANGE2
		ClrBit(ADCSRA,ADPS2);
		SetBit(ADCSRA,ADPS1);
		ClrBit(ADCSRA,ADPS0);
	#elif PRESCALAR == RANGE3
		ClrBit(ADCSRA,ADPS2);
		SetBit(ADCSRA,ADPS1);
		SetBit(ADCSRA,ADPS0);
	#elif PRESCALAR == RANGE4
		SetBit(ADCSRA,ADPS2);
		ClrBit(ADCSRA,ADPS1);
		ClrBit(ADCSRA,ADPS0);
	#elif PRESCALAR == RANGE5
		SetBit(ADCSRA,ADPS2);
		ClrBit(ADCSRA,ADPS1);
		SetBit(ADCSRA,ADPS0);
	#elif PRESCALAR == RANGE6
		SetBit(ADCSRA,ADPS2);
		SetBit(ADCSRA,ADPS1);
		ClrBit(ADCSRA,ADPS0);
	#elif PRESCALAR == RANGE7
		SetBit(ADCSRA,ADPS2);
		SetBit(ADCSRA,ADPS1);
		SetBit(ADCSRA,ADPS0);
	#else
	#error "Pre-scalar  out of range"
	#endif

}

extern u8 ADC_ReadCh(u8 Copy_u8ChNo, u16 *Copy_u8PtrToVal,u8 Resolution_u8Flag,u8 Precision_u8flag)
{
	u8 local_u8status = error;u8 precision_u8counter = 0;u16 storage_u16value = 0;*Copy_u8PtrToVal = 0;
	if(ADC_EnableState != DISABLED  &&  Copy_u8ChNo<8)//check for channel
	{	//SetBit(ADCSRA,ADIF);
		//Select channel
		ADMUX = ADMUX & 11100000;
		ADMUX = ADMUX | ADC_MUX[Copy_u8ChNo];
		#if TRIGGERMODE == SINGLEMODE
		/*****************Start conversion****************/
		SetBit(ADCSRA,ADSC);
		#endif

		/***********read the data conversion data      read the High reg only if res is 8 bits*********/
		switch(Resolution_u8Flag)
		{
			case ADC_EIGHT_RES: while(precision_u8counter < Precision_u8flag)
								{
										/**************Wait until conversion is on********/
										while(GetBit(ADCSRA,ADIF) != DIO_u8HIGH);
										storage_u16value = ADCH;
										storage_u16value = storage_u16value<<2;
									//	storage_u16value = ((storage_u16value/1024)*2.56);
										precision_u8counter++;
										//SetBit(ADCSRA,ADIF);/***turn off End of conversion Flag***/
										#if TRIGGERMODE == SINGLEMODE
										/*****************Start conversion****************/
										SetBit(ADCSRA,ADSC);
										#endif
										*Copy_u8PtrToVal = *Copy_u8PtrToVal + storage_u16value;
								}
								*Copy_u8PtrToVal = (u16)(*Copy_u8PtrToVal/Precision_u8flag);
								local_u8status = okay;
								break;
			case ADC_TEN_RES  :  while(precision_u8counter != Precision_u8flag)
								{SetBit(ADCSRA,ADSC);
										/**************Wait until conversion is on********/
										while(GetBit(ADCSRA,ADIF) != DIO_u8HIGH);
										storage_u16value = ADCH;
										storage_u16value = storage_u16value<<2;
										storage_u16value = storage_u16value |(ADCL>>6);
										//storage_u16value = (storage_u16value/1024)*2.56;
										precision_u8counter++;
										//SetBit(ADCSRA,ADIF);/***turn off End of conversion Flag***/
										#if TRIGGERMODE == SINGLEMODE
										/*****************Start conversion****************/
										SetBit(ADCSRA,ADSC);
										#endif
										*Copy_u8PtrToVal = *Copy_u8PtrToVal + storage_u16value;
								}
								*Copy_u8PtrToVal = *Copy_u8PtrToVal/Precision_u8flag;
								local_u8status = okay;
								break;
			default:			local_u8status = error;
								break;
		}
	}
	else{local_u8status = error;}

	return local_u8status;
}


extern void ADC_Enable(void)
{
	SetBit(ADCSRA,ADEN);ADC_EnableState = ENABLED;
	#if TRIGGERMODE == AUTOMODE
	SetBit(ADCSRA,ADSC);
	//SetBit(ADCSRA,ADATE);
	#endif
}
extern void ADC_Disable()
{
	ClrBit(ADCSRA,ADEN);ADC_EnableState = DISABLED;
}

