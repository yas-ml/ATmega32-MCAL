/*
 * SFREG_prog.c
 *
 *  Created on: Feb 15, 2016
 *      Author: Yousri saleh
 */
#include "types.h"
#include "SREG_config.h"
#include "SREG_interface.h"
#include "DIO_interface.h"

static u8 const SREG_DSPin[2] = {SREG_DS1,SREG_DS2};
static u8 const SREG_SHPin[2] = {SREG_SH1,SREG_SH2};
static u8 const SREG_STPin[2] = {SREG_ST1,SREG_ST2};

extern void SREG_Init(void)
{

}

extern u8 SREG_DS(u8 Copy_u8SREG_NUM,u8 Copy_u8DS_Val)
{	u8 local_u8Returnstatus;
	if((Copy_u8SREG_NUM > SREG_NUMS-1) || (Copy_u8DS_Val > DIO_u8OUTPUT))
	{
		local_u8Returnstatus = error;
	}
	else
	{
		DIO_u8WritePinVal(SREG_DSPin[Copy_u8SREG_NUM],Copy_u8DS_Val);
		local_u8Returnstatus = okay;
	}
	return local_u8Returnstatus;
}
extern u8 SREG_SH(u8 Copy_u8SREG_NUM,u8 Copy_u8SH_Val)
{	u8 local_u8Returnstatus;
	if((Copy_u8SREG_NUM > SREG_NUMS) || (Copy_u8SH_Val > DIO_u8OUTPUT))
	{
		local_u8Returnstatus = error;
	}
	else
	{
		DIO_u8WritePinVal(SREG_SHPin[Copy_u8SREG_NUM],Copy_u8SH_Val);
		local_u8Returnstatus = okay;
	}
	return local_u8Returnstatus;
}
extern u8 SREG_ST(u8 Copy_u8SREG_NUM,u8 Copy_u8ST_Val)

	{	u8 local_u8Returnstatus;
		if((Copy_u8SREG_NUM > SREG_NUMS) || (Copy_u8ST_Val > DIO_u8OUTPUT))
		{
			local_u8Returnstatus = error;
		}
		else
		{
			DIO_u8WritePinVal(SREG_STPin[Copy_u8SREG_NUM],Copy_u8ST_Val);
			local_u8Returnstatus = okay;
		}
		return local_u8Returnstatus;
	}

