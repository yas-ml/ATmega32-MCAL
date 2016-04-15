/*
 * SPI_private.h
 *
 *  Created on: Apr 7, 2016
 *      Author: Home
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
/*************SPI Addresses*********/
#define SPCR	*((volatile u8*) (0x2D))
#define SPSR	*((volatile u8*) (0x2E))
#define SPDR	*((volatile u8*) (0x2F))

/*****************SPCR*************/
#define SPIE 	7
#define SPE 	6
#define DORD 	5
#define MSTR 	4
#define CPOL 	3
#define CPHA 	2
#define SPR1	1
#define SPR0	0
/*****************SPSR*************/
#define SPIF	7
#define WCOL	6
#define SPI2X	0
/**********************************SPI Interrupt******************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)


#endif /* SPI_PRIVATE_H_ */
