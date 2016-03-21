/*
 * SFREG_prog.c
 *
 *  Created on: Feb 15, 2016
 *      Author: Yousri saleh
 */
#include "types.h"
#include "SREG_interface.h"
#include "SREG_config.h"

u8 const SREG_SH[2] = {SREG_SH1,SREG_SH2};
u8 const SREG_ST[2] = {SREG_ST1,SREG_ST2};
u8 const SREG_DS[2] = {SREG_DS1,SREG_DS2};
extern void SREG_Init(void)
{
}

extern u8 SREG_DS(u8 Copy_u8SREGNUM,u8 Copy_u8DSVal)
{	u8 local_u8Returnstatus;
	if(Copy_u8SREGNUM > SRED_NUMS || Copy_u8DSVal > DIO_u8OUTPUT)
	{
		local_u8Returnstatus = error;
	}
	else
	{
		DIO_u8WritePinVal(SREG_DS(Copy_u8SREGNUM),Copy_u8DSVal);
		local_u8Returnstatus = okay;
	}
	return local_u8Returnstatus;
}
extern u8 SREG_SH(u8 Copy_u8SREGNUM,u8 Copy_u8SHVal);
extern u8 SREG_ST(u8 Copy_u8SREGNUM,u8 Copy_u8STVal);
