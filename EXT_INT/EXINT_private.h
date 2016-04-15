/*
 * EXINT_private.h
 *
 *  Created on: Mar 28, 2016
 *      Author: Home
 */

#ifndef EXINT_PRIVATE_H_
#define EXINT_PRIVATE_H_

#define MCUCR   *((volatile u8*) (0x55))
#define MCUCSR  *((volatile u8*) (0x54))
#define GICR    *((volatile u8*) (0x5B))
#define GIFR    *((volatile u8*) (0x5A))

/********************************EXT INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)
/*******************************INT ENABLE PINS*******************************/
#define INT0_PIN_ENABLE		6
#define INT1_PIN_ENABLE		7
#define INT2_PIN_ENABLE		5

/********************************INT Flag PIN*********************************/
#define INT0_FLAG_PIN		6
#define INT1_FLAG_PIN		7
#define INT2_FLAG_PIN		5

/******************************INT PINS DETCTION******************************/
#define ICS2 6


#endif /* EXINT_PRIVATE_H_ */
