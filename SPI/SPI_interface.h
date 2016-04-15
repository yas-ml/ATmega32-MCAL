/*
 * SPI_interface.h
 *
 *  Created on: Apr 7, 2016
 *      Author: Home
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*****************************************/
#define SPI_MASTER			1
#define SPI_SLAVE			0
/*****************************************/
#define SPI_Fosc4			0b00
#define SPI_Fosc16			0b01
#define SPI_Fosc64			0b10
#define SPI_Fosc128			0b11
/*****************************************/
#define SPI_DOUBLE_SPEED_MODE_ON		1
#define SPI_DOUBLE_SPEED_MODE_OFF		0
/*****************************************/
#define SPI_ENABLE_ON		1
#define SPI_DISABLE_OFF		0
/*****************************************/
#define SPI_IDLE_LOW		0
#define SPI_IDLE_HIGH		1
/*****************************************/
#define SPI_RISING			1
#define SPI_FALLING			0
/*****************************************/
#define SPI_INT_ON			1
#define SPI_INT_OFF			0
/*****************************************/
#define SPI_LSB_FISRT		1
#define SPI_MSB_FISRT		0

extern void SPI_voidInit(void);
extern u8 SPI_MasterSlaveMode(u8 Copy_u8Master);
extern void SPI_Send(u8 Copy_u8Data);
extern void SPI_Recieve(u8 *Copy_u8Data);
extern u8 SPI_CheckColl(void);
extern void SPI_callBackFunc_Assign(void(*PtrToSPI_Isr)(void));
#endif /* SPI_INTERFACE_H_ */
