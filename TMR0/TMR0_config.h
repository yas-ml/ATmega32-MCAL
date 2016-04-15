/*
 * TMR0_config.h
 *
 *  Created on: Apr 1, 2016
 *      Author: Home
 */

#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_
/******************Enable status**********************/
#define TMR0_INT__ON_OFF_MODE	TMR0_ENABLE		//TMR0_ENABLE
#define OCR0_INT__ON_OFF_MODE	OCR0_DISABLE	//OCR0_ENABLE
#define WAVE_FORM_GEN			CTC//NORMAL

/****************Prescalar value**********************/
#define TMR0_PRESCALAR		PRESCALING_CLK1024 // NO_CLK_SRC,NO_PRESCALING,PRESCALING_CLK8,PRESCALING_CLK64,PRESCALING_CLK256,PRESCALING_CLK8,EXT_CLK_FALLING,EXT_CLK_RISING




#endif /* TMR0_CONFIG_H_ */
