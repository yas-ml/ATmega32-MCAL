/*
 * EXINT_interface.h
 *
 *  Created on: Mar 29, 2016
 *      Author: Home
 */

#ifndef EXINT_INTERFACE_H_
#define EXINT_INTERFACE_H_
/*****************************************************************************
 ***********************INTERRUPTS DETECTION EGDE*****************************
 *****************************************************************************/


/**************************INT0 Detection Edge*************************/
#define LOGICAL_INT0	0b01
#define RISING_INT0	    0b11
#define FALLING_INT0	0b10
#define LOW_LEVEL_INT0	0b00
/**************************INT1 Detection Edge*************************/
#define LOGICAL_INT1	(0b01<<2)
#define RISING_INT1	    (0b11<<2)
#define FALLING_INT1	(0b10<<2)
#define LOW_LEVEL_INT1	(0b00<<2)
/**************************INT2 Detection Edge*************************/
#define FALLING_INT2	(0b0<<6)
#define RISING_INT2		(0b1<<6)

/*****************************************************************************
 *******************************INTERRUPTS ENABLE*****************************
 *****************************************************************************/

/*********************************INT ENABLE*********************************/

#define ON_INT		1
#define OFF_INT	0



/*************************************EXT Interrupts APIS*********************/
extern void callback_INT0_Assign(void(*Ptr_to_Int0)(void));
extern void callback_INT1_Assign(void(*Ptr_to_Int1)(void));
extern void callback_INT2_Assign(void(*Ptr_to_Int2)(void));
extern void EXINT_init(void);
extern u8 EXINT_Read_Int_Status(u8 Int_No, u8 *Copy_Int_Status);
extern u8 EXINT_Enable_Int_Peripheral(u8 Int_No);
extern u8 EXINT_Disable_Int_Peripheral(u8 Int_No);

#endif /* EXINT_INTERFACE_H_ */
