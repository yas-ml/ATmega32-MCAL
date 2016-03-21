/*
 * SFREG_interface.h
 *
 *  Created on: Feb 15, 2016
 *      Author: Yousri saleh
 */

#ifndef SREG_INTERFACE_H_
#define SREG_INTERFACE_H_

#define SREG_NUM1   0
#define SREG_NUM2   1

extern void SREG_Init(void);
extern u8 SREG_DS(u8 Copy_u8SREG_NUM,u8 Copy_u8DS_Val);
extern u8 SREG_SH(u8 Copy_u8SREG_NUM,u8 Copy_u8SH_Val);
extern u8 SREG_ST(u8 Copy_u8SREG_NUM,u8 Copy_u8ST_Val);


#endif /* SREG_INTERFACE_H_ */
