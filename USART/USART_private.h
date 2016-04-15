/*
 * UART_private.h
 *
 *  Created on: Apr 14, 2016
 *      Author: Home
 */

#ifndef USART_PRIVATE_H__
#define USART_PRIVATE_H__
/********************************TR INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)
/********************************Addresses***********************************/
#define UBRRH  (*(volatile u8 *)(0x40))
#define UBRRL  (*(volatile u8 *)(0x29))
#define UCSRB  (*(volatile u8 *)(0x2A))
#define UCSRA  (*(volatile u8 *)(0x2B))
#define UCSRC  (*(volatile u8 *)(0x40))
#define UDR	   (*(volatile u8 *)(0x2C))
#define UCSRB  (*(volatile u8 *)(0x2A))

/**********************UCSRA************************/
#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR		3
#define PE 		2
#define U2X		1
#define MPCM	0

/**********************UCSRB************************/
#define RXCIE 	7
#define TXCIE	6
#define UDRIE	5
#define RXEN 	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

/**********************UCSRC************************/
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0



#endif
