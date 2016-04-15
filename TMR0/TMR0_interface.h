/*
 * TMR0_interface.h
 *
 *  Created on: Apr 1, 2016
 *      Author: Home
 */

#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

/******************Enable status**********************/
#define TMR0_ENABLE   0
#define TMR0_DISABLE  1

#define OCR0_DISABLE  0
#define OCR0_ENABLE  1
/****************Prescalar value**********************/
#define NO_CLK_SRC		     0b000
#define NO_PRESCALING	     0b001
#define PRESCALING_CLK8      0b010
#define PRESCALING_CLK64     0b011
#define PRESCALING_CLK256    0b100
#define PRESCALING_CLK1024	 0b101
#define EXT_CLK_FALLING		 0b110
#define EXT_CLK_RISING		 0b111
/*******************WAVE_FORM_GEN**********************/
#define NORMAL			1
#define CTC				0

extern void TMR0_Init(void);
extern void TMR0_ReadCurrentTicks(u8 *Copy_u8NumOfTicks);
extern void TMR0_OCVal_Assign(u8 copy_u8Val);
extern void TMR0_WriteTimerVal(u8 Copy_u8TimerVal);
extern void TMR0_GetOV(u8 *Copu_u8TMR0_OV);
extern void TMR0_SetOV(u8 Copu_u8TMR0_OV);
extern void TMR0_GetNo_of_Ticks(u32 *Copy_No_of_Ticks);
extern void TMR0_Enable(void);
extern void TMR0_Disable(void);
extern void OCR0_Enable(void);
extern void OCR0_Disable(void);
extern void callback_TMR0_Assign(void(*Ptr_to_timer0)(void));
extern void callback_OCR0_Assign(void(*Ptr_to_outputcomp0)(void));
#endif /* TMR0_INTERFACE_H_ */
