/*
 * ADC_interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Home
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/********************ADCMUX*******************/


#define LEFT	    1
#define RIGHT	    0

#define ADC_EIGHT_RES		0
#define ADC_TEN_RES			1

#define CH_ON	    1
#define CH_OFF	    0

//#define 0TO3	    1
//#define 4TO7	    0

#define ENABLED		1
#define DISABLED	0

#define AUTOMODE	1
#define SINGLEMODE	0

#define RANGE1	1
#define RANGE2	2
#define RANGE3	3
#define RANGE4	4
#define RANGE5	5
#define RANGE6	6
#define RANGE7	7
/********************ADCSRA*******************/

extern void ADC_INIT(void);
extern u8 ADC_ReadCh(u8 Copy_u8ChNo, u16 *Copy_u8PtrToVal,u8 Resolution_u8Flag,u8 Precision_u8flag);
extern u8 ADC_StartChGrp(u8 Copy_u8ChGrpNo);
extern void ADC_Enable(void);
extern void ADC_Disable(void);

#endif /* ADC_INTERFACE_H_ */
