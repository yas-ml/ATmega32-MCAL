/*
 * TSW_interface.h
 *
 *  Created on: Feb 13, 2016
 *      Author: Home
 */

#ifndef TSW_INTERFACE_H_
#define TSW_INTERFACE_H_



#define SINGLEMODE    1
#define MULTIMODE     0


#define ACTIVEHIGH    1
#define ACTIVELOW     0


#define    On		  1
#define    Off	      0

#define TSW_Released      0
#define TSW_Pressed       1
#define TSW_Bouncing      2



extern u8 TSW_u8CheckSW(u8 CopyIdx,u8*Copy_u8PtrVal);
extern void TSW_VoidInit(void);

#endif /* TSW_INTERFACE_H_ */
