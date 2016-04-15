/*
 * Types.h
 *
 *  Created on: Jan 5, 2016
 *      Author: Yaser
 */
#ifndef _H_TYPES_
#define _H_TYPES_
#define okay  1
#define error 0
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long  u32;
typedef signed long   s32;
typedef unsigned long   u64;
typedef signed long   s64;
typedef float f32;
typedef double f64;

#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)
#define CLR_LOWNib(Reg) 	Reg &= 0xF0
#define SET_LOWNib(Reg)  	Reg =Reg|0x0F
#define ClrBit(Reg,BitNo)   ((Reg)&=~(1<<(BitNo)))
#define SetBit(Reg,BitNo)   (Reg|=(1<<BitNo))

#endif
