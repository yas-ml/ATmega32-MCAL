/*
 * SSD_prog.c
 *
 *  Created on: Feb 3, 2016
 *      Author: Home
 */
#include "types.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 const SSD_u8ArrayofVal []={0b11111101,0b01100001,0b11011011,0b11110011,0b01100111,0b10110111,0b10111111,0b11100011,0b11111111,0b11110111};
u8 const SSD_u8ArrayofDisp [2][8] = {\
		{SSD_u8DISP1COM,SSD_u8DISP1SEGG,SSD_u8DISP1SEGF,SSD_u8DISP1SEGE,SSD_u8DISP1SEGD,SSD_u8DISP1SEGC,SSD_u8DISP1SEGB,SSD_u8DISP1SEGA},\
		{SSD_u8DISP2COM,SSD_u8DISP2SEGG,SSD_u8DISP2SEGF,SSD_u8DISP2SEGE,SSD_u8DISP2SEGD,SSD_u8DISP2SEGC,SSD_u8DISP2SEGB,SSD_u8DISP2SEGA}};

extern u8 SSD_u8Display(u8 Copy_u8DispIdx,u8 Copy_u8DispVal)
{
	u8 local_u8return_status;
	u8 local_u8assignBit;
	if(Copy_u8DispIdx>= NO_OF_DISP|| Copy_u8DispVal>SSD_u8NUM9)
		{
			local_u8return_status = error;
		}
	else
		{
		/*Comment!: Enable Pin of Display X */
		 local_u8return_status = DIO_u8WritePinVal(SSD_u8ArrayofDisp[Copy_u8DispIdx][COMMON_PIN],GetBit(DISP_TYPES,(Copy_u8DispIdx-1)));
		/*Comment!: Display the number on Display X */
		 if(local_u8return_status == okay)
			 {
				for(local_u8assignBit = 1;local_u8assignBit <= 8 ;local_u8assignBit++)
					{
					if(GetBit(DISP_TYPES,(Copy_u8DispIdx-1)) == SSD_u8COMAND)
						{
						local_u8return_status = DIO_u8WritePinVal(SSD_u8ArrayofDisp[Copy_u8DispIdx-1][local_u8assignBit],(GetBit(SSD_u8ArrayofVal[Copy_u8DispVal-1],local_u8assignBit)));
						}
					else
						{
							local_u8return_status = DIO_u8WritePinVal(SSD_u8ArrayofDisp[Copy_u8DispIdx-1][local_u8assignBit],~(GetBit(SSD_u8ArrayofVal[Copy_u8DispVal-1],local_u8assignBit)));
						}
					if(local_u8return_status == error)
						{
							break;
						}
					else
						{

						}
					}
			 }
		 else
		 {

		 }
		}
	return local_u8return_status;
}

extern void SSD_voidInit(void)
	{
	/*Comment!: Initialize I/O peripherals of Display 1 */
	if(SSD_u8DISP1INITSTATE == On)
		{
			DIO_u8WritePinDir( SSD_u8DISP1COM, DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGA,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGB,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGC,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGD,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGE,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGF,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP1SEGG,DIO_u8OUTPUT);
		/*Comment!: Initialize initial  output value on Display 1 */
			SSD_u8Display(SSD_u8DISP1,SSD_u8DISP1INITVAL);
		}
	/*Comment!: Initialize I/O peripherals of Display 2 */
	if(SSD_u8DISP2INITSTATE == On)
		{
			DIO_u8WritePinDir( SSD_u8DISP2COM,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGA,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGB,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGC,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGD,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGE,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGF,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP2SEGG,DIO_u8OUTPUT);

			/*Comment!: Initialize initial  output value on Display 2 */
			SSD_u8Display(SSD_u8DISP2,SSD_u8DISP2INITVAL);
		}/*
	if(SSD_u8DISP3INITSTATE == On)
		{
			DIO_u8WritePinDir( SSD_u8DISP3COM, DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGA,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGB,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGC,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGD,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGE,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGF,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP3SEGG,DIO_u8OUTPUT);
		/*Comment!: Initialize initial  output value on Display 1 */
			SSD_u8Display(SSD_u8DISP3,SSD_u8DISP3INITVAL);
	//	}/*
	/*if(SSD_u8DISP4INITSTATE == On)
		{
			DIO_u8WritePinDir( SSD_u8DISP4COM, DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGA,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGB,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGC,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGD,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGE,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGF,DIO_u8OUTPUT);
			DIO_u8WritePinDir( SSD_u8DISP4SEGG,DIO_u8OUTPUT);
		/*Comment!: Initialize initial  output value on Display 1 */
	//		SSD_u8Display(SSD_u8DISP4,SSD_u8DISP4INITVAL);
	//	}

	}
