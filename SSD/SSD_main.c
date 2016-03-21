/*
 * SSD_main.c
 *
 *  Created on: Feb 6, 2016
 *      Author: Home
 */
#include "types.h"
#include "SSD_interface.h"
int main()
{
	SSD_voidInit();
	for(int i = 0; i<10;i++)
	{
	 SSD_u8Display(0,i);
	 for(u64 count;count<4000000;count++ )
		 __asm__("NOP");;
	 for(u64 count;count<4000000;count++ )
		 __asm__("NOP");;

	}
	return 0;
}

