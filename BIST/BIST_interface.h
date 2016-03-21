/*
 * BIST_interface.h
 *
 *  Created on: Mar 2, 2016
 *      Author: Home
 */

#ifndef BIST_INTERFACE_H_
#define BIST_INTERFACE_H_

#define CHECKPORT3PATTERN1 (PATTERN1&0x3f)
#define CHECKPORT3PATTERN2 PATTERN2&0x3f

extern u8 BIST_CheckPattern(u8 Pattern);

extern void BIST_Init(void);

#endif /* BIST_INTERFACE_H_ */
