/*
 * delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: Home
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "Delay_config.h"
#define DELAY_MS(x) do{for(u32 Local_u8DelayCount = (DELAY_u32SYSCLK*125UL*x); Local_u8DelayCount >0; Local_u8DelayCount--){__asm("NOP");}}while(0)




#endif /* DELAY_H_ */
