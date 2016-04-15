/*
 * USART_test_main.c
 *
 *  Created on: Apr 15, 2016
 *      Author: Home
 */
#include "types.h"
#include "USART_Interface.h"
#include "delay.h"
#include "DIO_interface.h"

#define USART_TEST_INT	0
void transTest(void)
{
	static u8 toggle = 1;
	DIO_u8WritePinVal(USART_TEST_INT,toggle);
	//DELAY_MS(10);
	toggle = !toggle;
}
int main()
{
	DIO_voidInit();
	USART_Init();
	__asm__("SEI");
	USART_Trans_Int_Enable();
	USART_callback_Trans_Int(transTest);

	while(1)
	{
		USART_Transmit(0xFF);

		USART_Transmit(0);
		USART_Transmit(0);
		USART_Transmit(0);
		USART_Transmit(0);
		USART_Transmit(0);
		USART_Transmit(0);
		USART_Transmit(0);
		USART_Transmit(0);
	}

	return 0;
}
