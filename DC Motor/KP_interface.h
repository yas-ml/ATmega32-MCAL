/*
 * KP_interface.h
 *
 *  Created on: Feb 29, 2016
 *      Author: Home
 */

#ifndef KP_INTERFACE_H_
#define KP_INTERFACE_H_

typedef union{
	struct{

	u16 KP_SW1:1;
	u16 KP_SW2:1;
	u16 KP_SW3:1;
	u16 KP_SW4:1;
	u16 KP_SW5:1;
	u16 KP_SW6:1;
	u16 KP_SW7:1;
	u16 KP_SW8:1;
	u16 KP_SW9:1;
	u16 KP_SW10:1;
	u16 KP_SW11:1;
	u16 KP_SW12:1;
	u16 KP_SW13:1;
	u16 KP_SW14:1;
	u16 KP_SW15:1;
	u16 KP_SW16:1;
};
u16 KP;
} Keypad;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*********************PIN NO****************************/
#define KP_PIN1     KP_SWINPUT1
#define KP_PIN2     KP_SWINPUT2
#define KP_PIN3     KP_SWINPUT3
#define KP_PIN4     KP_SWINPUT4
#define KP_PIN5     KP_SWINPUT1
#define KP_PIN6     KP_SWINPUT2
#define KP_PIN7     KP_SWINPUT3
#define KP_PIN8     KP_SWINPUT4
#define KP_PIN9     KP_SWINPUT1
#define KP_PIN10    KP_SWINPUT2
#define KP_PIN11    KP_SWINPUT3
#define KP_PIN12    KP_SWINPUT4
#define KP_PIN13    KP_SWINPUT1
#define KP_PIN14    KP_SWINPUT2
#define KP_PIN15    KP_SWINPUT3
#define KP_PIN16    KP_SWINPUT4


/*******************Switch state***********************/
#define KP_MODE1    ACTIVEHIGH
#define KP_MODE2    ACTIVEHIGH
#define KP_MODE3    ACTIVEHIGH
#define KP_MODE4    ACTIVEHIGH
#define KP_MODE5    ACTIVEHIGH
#define KP_MODE6    ACTIVEHIGH
#define KP_MODE7    ACTIVEHIGH
#define KP_MODE8    ACTIVEHIGH
#define KP_MODE9    ACTIVEHIGH
#define KP_MODE10   ACTIVEHIGH
#define KP_MODE11   ACTIVEHIGH
#define KP_MODE12   ACTIVEHIGH
#define KP_MODE13   ACTIVEHIGH
#define KP_MODE14   ACTIVEHIGH
#define KP_MODE15   ACTIVEHIGH
#define KP_MODE16   ACTIVEHIGH
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define SINGLEMODE    1
#define MULTIMODE     0


#define ACTIVEHIGH    1
#define ACTIVELOW     0


#define    On		  1
#define    Off	      0

#define KP_Released      0
#define KP_Pressed       1
#define KP_Bouncing      2
//////////////////////////////////////////////////////////////////////////////////////////////////
extern void KeypadInit(void);
extern Keypad KP_Read(void);
extern u8 KP_ReadSW(u8 Copy_u8idx, u8 *Copy_Val);
extern u8 KP_u8CheckSW(u8 CopyIdx,u8 *Copy_u8PtrVal);

#endif /* KP_INTERFACE_H_ */
