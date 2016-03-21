/*
 * SFREG_interface.h
 *
 *  Created on: Feb 15, 2016
 *      Author: Yousri saleh
 */

#ifndef SFREG_INTERFACE_H_
#define SFREG_INTERFACE_H_

#define SREG_NUM1   0
#define SREG_NUM2   1

extern void SREG_Init(void);
extern u8 SREG_DS(u8 Copy_u8SREGNUM,u8 Copy_u8DSVal);
extern u8 SREG_SH(u8 Copy_u8SREGNUM,u8 Copy_u8SHVal);
extern u8 SREG_ST(u8 Copy_u8SREGNUM,u8 Copy_u8STVal);


#endif /* SFREG_INTERFACE_H_ */
