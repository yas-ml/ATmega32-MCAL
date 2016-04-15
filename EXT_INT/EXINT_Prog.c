/*
 * INT_Prog.c
 *
 *  Created on: Mar 28, 2016
 *      Author: Home
 */

#include "types.h"
#include "EXINT_interface.h"
#include "EXINT_private.h"
#include "EXINT_config.h"


/**********************Callback functions**********************************************/
static void (*Ptr_To_EXTI0) (void);
static void (*Ptr_To_EXTI1) (void);
static void (*Ptr_To_EXTI2) (void);

static u8 EXINT_u8FlagPins [] = {INT1_FLAG_PIN,INT0_FLAG_PIN,INT2_FLAG_PIN};
static u8 EXINT_u8EnablePins [] = {INT1_PIN_ENABLE,INT0_PIN_ENABLE,INT2_PIN_ENABLE};

extern void callback_INT0_Assign(void(*Ptr_to_Int0)(void))
{
	/*********************assign ptr to function to EXT pointer*************************/
	Ptr_To_EXTI0 = Ptr_to_Int0;
}
extern void callback_INT1_Assign(void(*Ptr_to_Int1)(void))
{
	/*********************assign ptr to function to EXT pointer*************************/
	Ptr_To_EXTI1 = Ptr_to_Int1;
}
extern void callback_INT2_Assign(void(*Ptr_to_Int2)(void))
{
	/*********************assign ptr to function to EXT pointer*************************/
	Ptr_To_EXTI2 = Ptr_to_Int2;
}
extern void EXINT_init(void)
{
	/********************************Enable global Interrupt****************************/
	__asm__("SEI");
	/*********************Set Detection edge INT0,INT1 and INT2*************************/
			CLR_LOWNib(MCUCR);
			MCUCR = MCUCR  | INT0_EDGE;
			MCUCR = MCUCR  | INT1_EDGE;
	#if     INT2_EDGE == RISING_INT2
		    SetBit(MCUCSR,ICS2);
	#elif	INT2_EDGE == FALLING_INT2
		    ClrBit(MCUCSR,ICS2);
	#endif
	/**************************Enable INT0,INT1 and INT2********************************/
	#if   INT0_ENABLE == ON_INT
		     SetBit(GICR,INT0_PIN_ENABLE);
	#elif INT0_ENABLE == OFF_INT
		     ClrBit(GICR,INT0_PIN_ENABLE);
	#endif

	#if   INT1_ENABLE == ON_INT
			 SetBit(GICR,INT1_PIN_ENABLE);
	#elif INT1_ENABLE == OFF_INT
			 ClrBit(GICR,INT1_PIN_ENABLE);
	#endif

	#if   INT2_ENABLE == ON_INT
			 SetBit(GICR,INT2_PIN_ENABLE);
	#elif INT2_ENABLE == OFF_INT
			 ClrBit(GICR,INT2_PIN_ENABLE);
	#endif

}

extern u8 EXINT_Read_Int_Status(u8 Int_No, u8 *Copy_Int_Status)
{	u8 Local_u8Status = okay;

		if(Int_No<3)
			*Copy_Int_Status = GetBit(GIFR,EXINT_u8FlagPins[Int_No]);
		else
			Local_u8Status = error;
	return Local_u8Status;
}

extern u8 EXINT_Enable_Int_Peripheral(u8 Int_No)
{
u8 Local_u8Status = okay;

	if(Int_No<3)
		SetBit(GICR,EXINT_u8EnablePins[Int_No]);
	else
		Local_u8Status = error;

return Local_u8Status;
}

extern u8 EXINT_Disable_Int_Peripheral(u8 Int_No)
{
u8 Local_u8Status = okay;

	if(Int_No<3)
		ClrBit(GICR,EXINT_u8EnablePins[Int_No]);
	else
		Local_u8Status = error;

return Local_u8Status;
}

//ISR(__vector_1)
//{
//	static volatile u8 count = 0;
//	DIO_u8WritePinVal(16,DIO_u8LOW);
//	count++;
//	if(count == 5)
//		{
//		DIO_u8WritePinVal(16,DIO_u8HIGH);
//		DELAY_MS(10);
//		count = 0;
//		}
//
//}
//ISR(__vector_2)
//{
//	static volatile u8 count = 0;
//	DIO_u8WritePinVal(19,DIO_u8LOW);
//	count++;
//	if(count == 5)
//		{
//		DIO_u8WritePinVal(19,DIO_u8HIGH);
//		DELAY_MS(10);
//		count = 0;
//		}
//
//}



ISR(__vector_1)
{
	(*Ptr_To_EXTI0)();
}


ISR(__vector_2)
{
	(*Ptr_To_EXTI1)();
}

ISR(__vector_3)
{
	(*Ptr_To_EXTI1)();
}

