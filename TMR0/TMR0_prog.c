/*
 * TMR0_prog.c
 *
 *  Created on: Apr 1, 2016
 *      Author: Home
 */

#include "types.h"
#include "TMR0_config.h"
#include "TMR0_interface.h"
#include "TMR0_private.h"

static void (*Ptr_To_TMR0)(void);
static void (*Ptr_To_OCR0)(void);

static u8 No_OF_TOV = 0;
static u8 No_OF_TOCOV = 0;

extern void TMR0_Init(void)
{
	__asm__("SEI");
	/*The FOC0 must stay the same and all the register will be zeros*/
	TCCR0 = TCCR0 & (1<<FOC0);
	/*********************Adjust WAVE_FORM_GEN***********************/
	#if WAVE_FORM_GEN == NORMAL
	ClrBit(TCCR0,WGM00);
	ClrBit(TCCR0,WGM01);
	#endif

	#if WAVE_FORM_GEN == CTC
	ClrBit(TCCR0,WGM00);
	SetBit(TCCR0,WGM01);
	#endif
	/************************Adjust prescalar************************/
	TCCR0 = TCCR0 | TMR0_PRESCALAR;
	/**************************TMR0 Enable/Diable********************/
	#if TMR0_INT__ON_OFF_MODE == TMR0_ENABLE
	SetBit(TIMSK,TOIE0);
	#elif TMR0_INT__ON_OFF_MODE == TMR0_DISABLE
	ClrBit(TIMSK,TOIE0);
	#else
	#error "TMR0 Must be either TMR0_ENABLE or TMR0_ENABLE"
	#endif
	/**************************OCR0 Enable/Diable********************/
	#if OCR0_INT__ON_OFF_MODE == OCR0_ENABLE
	SetBit(TIMSK,OCIE0);
	#elif OCR0_INT__ON_OFF_MODE == OCR0_DISABLE
	ClrBit(TIMSK,OCIE0);
	#else
	#error "OCR0 Must be either OCR0_ENABLE or OCR0_ENABLE"
	#endif
}
extern void callback_TMR0_Assign(void(*Ptr_to_timer0)(void))
{
	Ptr_To_TMR0 = Ptr_to_timer0;
}
extern void callback_OCR0_Assign(void(*Ptr_to_outputcomp0)(void))
{
	Ptr_To_OCR0 = Ptr_to_outputcomp0;
}
extern void TMR0_OCVal_Assign(u8 copy_u8Val)
{
	OCR0 = copy_u8Val;
}
extern void TMR0_GetOV(u8 *Copu_u8TMR0_OV)
{
	*Copu_u8TMR0_OV = No_OF_TOV;
}
extern void TMR0_SetOV(u8 Copu_u8TMR0_OV)
{
	No_OF_TOV = Copu_u8TMR0_OV;
}
extern void TMR0_Enable(void)
{
	SetBit(TIMSK,TOIE0);
}
extern void TMR0_Disable(void)
{
	ClrBit(TIMSK,TOIE0);
}
extern void OCR0_Enable(void)
{
	SetBit(TIMSK,OCIE0);
}
extern void OCR0_Disable(void)
{
	ClrBit(TIMSK,OCIE0);
}
extern void TMR0_WriteTimerVal(u8 Copy_u8TimerVal)
{
	TCNT0 = Copy_u8TimerVal;
}
extern void TMR0_GetNo_of_Ticks(u32 *Copy_No_of_Ticks)
{
	*Copy_No_of_Ticks = 256*No_OF_TOV + TCNT0;
}
extern void TMR0_ReadCurrentTicks(u8 *Copy_u8NumOfTicks)
{
	*Copy_u8NumOfTicks = TCNT0;
}
ISR(__vector_10)
{
	No_OF_TOCOV++;
	(*Ptr_To_OCR0)();
}
ISR(__vector_11)
{
	No_OF_TOV++;
	(*Ptr_To_TMR0)();
}
