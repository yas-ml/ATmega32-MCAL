/*
 * SFREG_config.h
 *
 *  Created on: Feb 15, 2016
 *      Author: Yousri saleh
 */

#ifndef SREG_CONFIG_H_
#define SREG_CONFIG_H_

#define SREG_NUMS  2
#if SREG_NUMS == 1
#define SREG_DS1   0
#define SREG_SH1   0
#define SREG_ST1   0
#endif

#if SREG_NUMS == 2
#define SREG_DS1   0
#define SREG_SH1   0
#define SREG_ST1   0

#define SREG_DS2   0
#define SREG_SH2   0
#define SREG_ST2   0
#endif

#endif /* SREG_CONFIG_H_ */
