/*
*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: Yaser
 */
#include "types.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"

volatile u8 * const DIO_u8ports[] = {portA,portB,portC,portD};
volatile u8 * const DIO_u8dirs[] = {DDRA,DDRB,DDRC,DDRD};
volatile u8 * const DIO_u8pins[] = {PINA,PINB,PINC,PIND};

/*Comment!: Initialization function */
extern void DIO_voidInit(void)
{
	/*Comment!: DDR initialization  */
	*DIO_u8dirs[0] = DIO_u8PORTA_INITDIR;
	*DIO_u8dirs[1] = DIO_u8PORTB_INITDIR;
	*DIO_u8dirs[2] = DIO_u8PORTC_INITDIR;
	*DIO_u8dirs[3] = DIO_u8PORTD_INITDIR;
	/*Comment!: Port initialization  */
	*DIO_u8ports[0] =(DIO_u8PORTA_INITDIR & DIO_u8PORTAINIT) | ((~DIO_u8PORTA_INITDIR)&*DIO_u8ports[0] );
	*DIO_u8ports[1] =(DIO_u8PORTB_INITDIR & DIO_u8PORTBINIT) | ((~DIO_u8PORTB_INITDIR)&*DIO_u8ports[1] );
	*DIO_u8ports[2] =(DIO_u8PORTC_INITDIR & DIO_u8PORTCINIT) | ((~DIO_u8PORTC_INITDIR)&*DIO_u8ports[2] );
	*DIO_u8ports[3] =(DIO_u8PORTD_INITDIR & DIO_u8PORTDINIT) | ((~DIO_u8PORTD_INITDIR)&*DIO_u8ports[3] );


}

extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PtrToDir)
{
	u8 local_u8return_status;
	if(Copy_u8PortIdx > no_of_ports)
		{
			local_u8return_status = error;
		}
	else
		{
			*Copy_u8PtrToDir = *(DIO_u8dirs[Copy_u8PortIdx]);
			local_u8return_status = okay;
		}
    return local_u8return_status;
}

extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8* Copy_u8PtrToDir)
{
	u8 local_u8return_status;
	u8 local_u8port_dir_val;
	
	if(Copy_u8PinIdx > no_of_total_pins)
		{
			local_u8return_status = error;
		}
	else
		{
			local_u8port_dir_val = *(DIO_u8dirs[(u8)(port_number)]);
			* Copy_u8PtrToDir = GetBit(local_u8port_dir_val,Copy_u8PinIdx%no_of_pins);
			local_u8return_status = okay;
		}
	
	return local_u8return_status;
}

extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{
	u8 local_u8return_status=okay;
	
	if(Copy_u8PortIdx > no_of_ports)
	{
		local_u8return_status = error;
	}
	else
	{
		*(DIO_u8dirs[Copy_u8PortIdx]) = Copy_u8PortDir;
	}
    return local_u8return_status;
}

extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
	u8 local_u8return_status;
	
	if(Copy_u8PinIdx > no_of_total_pins)
		{
			local_u8return_status = error;
		}
	else
		{
			switch(Copy_u8PinDir)
			{
				case DIO_u8HIGH:
					SetBit(*(DIO_u8dirs[(u8)(port_number)]),(Copy_u8PinIdx%no_of_pins));
					local_u8return_status = okay;
					break;
				case DIO_u8LOW:
					ClrBit(*(DIO_u8dirs[(u8)(port_number)]),(Copy_u8PinIdx%no_of_pins));
					local_u8return_status = okay;
					break;
				default:
					local_u8return_status = error;
					break;
				
			}
		}
	
	return local_u8return_status;
}
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8PortVal)
{
	u8 local_u8return_status;
	
	if(Copy_u8PortIdx > no_of_ports)
	{
		local_u8return_status = error;
	}
	else
	{
		*(DIO_u8ports[Copy_u8PortIdx]) = Copy_u8PortVal;
		local_u8return_status = okay;
	}
    return local_u8return_status;
}

extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8PtrToVal)
{
	u8 local_u8return_status;
	
	if(Copy_u8PortIdx > no_of_ports)
	{
		local_u8return_status = error;
	}
	else
	{
		*Copy_u8PtrToVal = *(DIO_u8ports[Copy_u8PortIdx]);
		local_u8return_status = okay;
	}
    return local_u8return_status;
}

extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8PinVal)
{
	u8 local_u8return_status;
	
	if(Copy_u8PinIdx > no_of_total_pins)
		{
			local_u8return_status = error;
		}
	else
		{
			switch(Copy_u8PinVal)
			{
				case DIO_u8HIGH:
					SetBit(*(DIO_u8ports[(u8)(port_number)]),(Copy_u8PinIdx%no_of_pins));
					local_u8return_status = okay;
					break;
				case DIO_u8LOW:
					ClrBit(*(DIO_u8ports[(u8)(port_number)]),(Copy_u8PinIdx%no_of_pins));
					local_u8return_status = okay;
					break;
				default:
					local_u8return_status = error;
					break;
				
			}
		}
	
	return local_u8return_status;
}

extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrToVal)
{
	u8 local_u8return_status;
	
	if(Copy_u8PinIdx > no_of_total_pins)
		{
			local_u8return_status = error;
		}
	else
		{
			*Copy_u8PtrToVal = GetBit(*(DIO_u8pins[(u8)(port_number)]),(Copy_u8PinIdx%no_of_pins));
			local_u8return_status = okay;
		}
	
	return local_u8return_status;
}






