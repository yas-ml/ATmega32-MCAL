/*
 * SPI_prog.c
 *
 *  Created on: Apr 7, 2016
 *      Author: Home
 */
#include "types.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"

static void (*SPI_ISR)(void);
/*************************************************************
 * Function Description: SPI initializes SPI according to configuration
 * Input: None
 * Prerequisite: DIO Init
 * Return: None
 ************************************************************/
extern void SPI_voidInit(void)
{

		/********************Enable SPI Interrupt ******************/
	//SPCR = SPCR | (SPI_INT_ENABLE<<SPIE);
	//SPCR = SPCR |  (SPI_INT_ENABLE<<SPIE) | (SPI_ENABLE<<SPE) | (SPI_DATA_ORDER<<DORD) | (SLAVE_MODE<<MSTR) | (SPI_OPERATING_LEVEL<<CPOL) | (SPI_SAMPLING_EDGE<<CPHA) | (SPI_PRESCALAR);
	#if SPI_INT_ENABLE == SPI_INT_ON
		SetBit(SPCR,SPIE);
	#elif SPI_INT_ENABLE == SPI_INT_OFF
		ClrBit(SPCR,SPIE);
	#else
		#error"can't choose other than SPI_INT_ON or SPI_INT_OFF"
	#endif

	/*******************Data Order ******************/
	#if SPI_DATA_ORDER == SPI_LSB_FISRT
		SetBit(SPCR,DORD);
	#elif SPI_DATA_ORDER == SPI_MSB_FISRT
		ClrBit(SPCR,DORD);
	#else
			#error "can't choose other than SPI_LSB_FISRT or SPI_MSB_FISRT"
	#endif

	/********************Master Slave Select ******************/
	#if SLAVE_MODE == SPI_MASTER
		SetBit(SPCR,MSTR);
	#elif SLAVE_MODE == SPI_SLAVE
		ClrBit(SPCR,MSTR);
	#else
		#error "can't choose other than SPI_MASTER or SPI_SLAVE"
	#endif
	/********************clock polarity******************/
	#if SPI_OPERATING_LEVEL == SPI_IDLE_LOW
		SetBit(SPCR,CPOL);
	#elif SPI_OPERATING_LEVEL == SPI_IDLE_HIGH
		ClrBit(SPCR,CPOL);
	#else
		#error "can't choose other than SPI_IDLE_LOW or SPI_IDLE_HIGH"
	#endif

	/********************clock phase******************/
	#if SPI_SAMPLING_EDGE == SPI_RISING
		SetBit(SPCR,CPHA);
	#elif SPI_SAMPLING_EDGE == SPI_FALLING
		ClrBit(SPCR,CPHA);
	#else
		#error "can't choose other than SPI_RISING or SPI_FALLING"
	#endif
	/********************SPI pre-scalar in case of master ******************/
		SPCR = SPCR | (SPI_PRESCALAR);
	/********************Double SPI speed if master******************/
	#if SPI_DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_ON
		SetBit(SPSR,SPI2X);
	#elif SPI_DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_OFF
		ClrBit(SPSR,SPI2X);
	#else
		#error "can't choose other than SPI_DOUBLE_SPEED_MODE_ON or SPI_DOUBLE_SPEED_MODE_OFF"
	#endif
	/********************Enable SPI ******************/
	#if  SPI_ENABLE == SPI_ENABLE_ON
		SetBit(SPCR,SPE);
	#elif SPI_ENABLE == SPI_ENABLE_OFF
		ClrBit(SPCR,SPE);
	#else
		#error "can't choose other than SPI_ENABLE_ON or SPI_ENABLE_OFF"
	#endif
}
/*************************************************************
 * Function Description: SPI master or slave select
 * Input: Master/Slave Bit
 * Prerequisite: SPI Init
 * Return: return status
 ************************************************************/
extern u8 SPI_MasterSlaveMode(u8 Copy_u8Master)
{ u8 local_u8returnStatus = error;

		switch(Copy_u8Master)
		{
		case SPI_SLAVE:	ClrBit(SPCR,MSTR);local_u8returnStatus = okay;
			break;
		case SPI_MASTER: SetBit(SPCR,MSTR);local_u8returnStatus = okay;
			break;
		default:local_u8returnStatus = error;
			break;
		}
	return local_u8returnStatus;
}
/*************************************************************
 * Function Description: SPI master or slave select
 * Input: Data to e sent
 * Prerequisite: SPI Init
 * Return: None
 ************************************************************/
extern void SPI_Send(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(!(SPSR & (1<<SPIF)));
}
/*************************************************************
 * Function Description: SPI recieve
 * Input: pointer to recieve data
 * Prerequisite: SPI Init
 * Return: None
 ************************************************************/
extern void SPI_Recieve(u8 *Copy_u8Data)
{
	while(!(SPSR & (1<<SPIF)));
	*Copy_u8Data = SPDR;
}
/*************************************************************
 * Function Description: Checks for collision
 * Input: None
 * Prerequisite: SPI Init
 * Return: collision status
 ************************************************************/
extern u8 SPI_CheckColl(void)
{
	u8 local_u8CollStatus = GetBit(SPSR,WCOL);
	return local_u8CollStatus;
}
/*************************************************************
 * Function Description: Assigns callback function
 * Input: Pointer to function
 * Prerequisite: SPI Init
 * Return: None
 ************************************************************/
extern void SPI_callBackFunc_Assign(void (*PtrToSPI_Isr) (void))
{
	SPI_ISR = PtrToSPI_Isr;
}
/*************************************************************
 * Interrupt Description: ISR that calls function in application
 * Input: None
 * Prerequisite: SPI Init
 * Return: None
 ************************************************************/
ISR(__vector_12)
{
	SPI_ISR();
}
