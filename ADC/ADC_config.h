/*
 * ADC_config.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Home
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define AREF	          3
#define INTERNAL          2
#define AVCC	   		  5

#define VREFSELECTION	INTERNAL
/*************Voltage Levels****************/

#define RL_ADJUST		LEFT,RIGHT		/**left or right adjusted*/

#define ADC0		CH_ON
#define ADC1		CH_OFF
#define ADC2		CH_OFF
#define ADC3		CH_OFF
#define ADC4		CH_OFF
#define ADC5		CH_OFF
#define ADC6		CH_OFF
#define ADC7		CH_OFF

#define ADC0_Res    EIGHT
#define ADC1_Res    EIGHT
#define ADC2_Res    EIGHT
#define ADC3_Res    EIGHT
#define ADC4_Res    EIGHT
#define ADC5_Res    EIGHT
#define ADC6_Res    EIGHT
#define ADC7_Res    EIGHT

#define CHANNELGRP1		0TO3
#define CHANNELGRP2		4TO7


#define INITIAL_STATE	ENABLED//,DISABLED		/**enable ADC**/
#define TRIGGERMODE		SINGLEMODE
#define PRESCALAR		RANGE7



#endif /* ADC_CONFIG_H_ */
