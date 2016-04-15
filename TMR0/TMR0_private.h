/*
 * TMR0_private.h
 *
 *  Created on: Apr 1, 2016
 *      Author: Home
 */

#ifndef TMR0_PRIVATE_H_
#define TMR0_PRIVATE_H_

/********************************EXT INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)

/**************************TMR0 Registers*************************************/
#define TCCR0	*((volatile u8*) (0x53))
#define TCNT0	*((volatile u8*) (0x52))
#define TIMSK	*((volatile u8*) (0x59))
#define OCR0	*((volatile u8*) (0x5C))

/**************************TCCR0 Registers*************************************/
#define FOC0 	7
#define WGM00	6
#define COM01 	5
#define COM00	4
#define WGM01	3
#define CS02 	2
#define CS01 	1
#define CS00 	0
/**************************Enable TMR0 Pin*************************************/
#define TOIE0	0
#define OCIE0	1


#endif /* TMR0_PRIVATE_H_ */
