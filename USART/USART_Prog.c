////////// MCAL  ////////////////
//Microcontroller Abistraction layer
//////////////////////////////////////

#include "types.h"
#include "USART_conig.h"
#include "USART_private.h"
#include "USART_Interface.h"
/******************Pointer to functions to be assigned to ISR*******************/

static void (*Ptr_To_Trans_Int) (void);
static void (*Ptr_To_Rec_Int) (void);

/******************** Global Functions **********************/

/*************************************************************
 * Function Description: USART initializes USART according to configuration
 * Input: None
 * Prerequisite: None
 * Return: None
 ************************************************************/

extern void USART_Init(void) {
	/*********************Enable Global Interrupt***************/
	__asm__("SEI");
	/************** Set baud rate **************/
	UBRRH = (u8) (UBRR_VAL >> 8);
	UBRRL = (u8) UBRR_VAL;
	/************** Enable transmitter **************/
	#if USART_TRANSMIT == USART_ENABLE
		UCSRB = UCSRB | (1 << TXEN);
	#elif USART_TRANSMIT == USART_DISABLE
		ClrBit(UCSRB,TXEN);
	#endif
		/************** Enable receiver **************/
	#if USART_RECIEVE == USART_ENABLE
		UCSRB = UCSRB | (1 << RXEN);
	#elif USART_RECIEVE == USART_DISABLE
		ClrBit(UCSRB,TXEN);
	#endif
	/**************** Set character size***************/
	#if USART_CHAR_SIZE != USART_9_Bit_CHAR
		UCSRC = (1 << URSEL) | (USART_CHAR_SIZE);
	#elif USART_CHAR_SIZE == USART_9_Bit_CHAR
		UCSRC = (1 << URSEL) | (USART_CHAR_SIZE);
		SetBit(UCSRB,2);
	#endif
		/**************** Set Double speed***************/
	#if ((USART_SYNCH_MODE == USART_ASYNCH) && (USART_SPEED_MODE == USART_DOUBLE_SPEED))
		SetBit(UCSRA,U2X);
	#endif
		/**************** Set Parity Bit***************/
		UCSRC |= (1<<URSEL) | USART_PARITY_MODE;
		/**************** Set SYNCH ASYNCH***************/
		UCSRC |= (1<<URSEL) | USART_SYNCH_MODE;
		/**************** Set Stop Bit***************/
		UCSRC |= (1<<URSEL) | USART_STOPBIT;
		/***************RECIEVER INT ENABLE**********/
		UCSRB |= USART_RECIEVE_INT;
		/***************TRANSMITER INT ENABLE**********/
		UCSRB |= USART_TRANSMITER_INT;
}

/*************************************************************
 * Function Description: USART transmits Data received
 * Input: Data
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/

extern void USART_Transmit(u16 data) {
	/* Wait for empty transmit buffer */
	while (!( UCSRA & (1 << UDRE)))
		;
	/***********if the data to be transmitted is 9 bits, write the MSB first*****************/
	#if USART_CHAR_SIZE  ==	USART_9_Bit_CHAR
		UCSRB |= GetBit(data,8);
	#endif
		/* Put data into buffer, sends the data */
	UDR = (u8)data;
}
/*************************************************************
 * Function Description: USART Receives Data received
 * Input: Pointer to be filled with data
 * Prerequisite: USART Init
 * Return: Parity check
 ************************************************************/
extern u8 USART_Receive(u16 *Ptr_To_Val) {
	u8 local_u8ParityError = error;
	*Ptr_To_Val = 0;
	/* Wait for data to be received */
	while (!(UCSRA & (1 << RXC)))
		;
	/****************Check if parity error is not ON********/
	if(GetBit(UCSRA,PE) != 1)
	{/***********if the data to be recieved is 9 bits, get the MSB first*****************/
	#if USART_CHAR_SIZE  ==	USART_9_Bit_CHAR
		*Ptr_To_Val = GetBit(UCSRB,1)<<8;
	#endif
		/* Get and return received data from buffer */
		*Ptr_To_Val |= UDR;
		local_u8ParityError = okay;
	}
	return local_u8ParityError;

}
/*************************************************************
 * Function Description: USART Receiver Interrupt enable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Rec_Int_Enable(void)
{
	SetBit(UCSRB,RXCIE);
}
/*************************************************************
 * Function Description: USART Receiver Interrupt Disable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Rec_Int_Disable(void)
{
	ClrBit(UCSRB,RXCIE);
}
/*************************************************************
 * Function Description: USART Transmitter Interrupt enable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Trans_Int_Enable(void)
{
	SetBit(UCSRB,TXCIE);
}
/*************************************************************
 * Function Description: USART Transmitter Interrupt Disable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Trans_Int_Disable(void)
{
	ClrBit(UCSRB,TXCIE);
}
/*************************************************************
 * Function Description: USART Receiver  enable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Rec_Enable(void)
{
	SetBit(UCSRB,RXEN);
}
/*************************************************************
 * Function Description: USART Receiver  disable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Rec_Disable(void)
{
	ClrBit(UCSRB,RXEN);
}
/*************************************************************
 * Function Description: USART Transmitter  enable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Trans_Enable(void)
{
	SetBit(UCSRB,TXEN);
}
/*************************************************************
 * Function Description: USART Transmitter  Disable
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_Trans_Disable(void)
{
	ClrBit(UCSRB,TXEN);
}
/*************************************************************
 * Function Description: USART Receiver assigned to function
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_callback_Rec_Int(void (*Ptr_to_Func)(void))
{
	Ptr_To_Rec_Int = Ptr_to_Func;
}
/*************************************************************
 * Function Description: USART Transmitted assigned to function
 * Input: None
 * Prerequisite: USART Init
 * Return: None
 ************************************************************/
extern void USART_callback_Trans_Int(void (*Ptr_to_Func)(void))
{
	Ptr_To_Trans_Int = Ptr_to_Func;
}
/*************************************************************
 * ISR Description: Receiver ISR
 * Prerequisite: USART_callback_Rec_Int
 ************************************************************/
ISR(__vector_13)
{
	(*Ptr_To_Rec_Int)();
}
/*************************************************************
 * ISR Description: Transmitter ISR
 * Prerequisite: USART_callback_Trans_Int
 ************************************************************/
ISR(__vector_15)
{
	(*Ptr_To_Trans_Int)();
}
