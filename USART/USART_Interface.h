#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*******************Stop bit****************/

#define ONE 1
#define TWO 2
/*******************FOSC SETTING****************/
#define FOUR_MEGA	4000000
/*******************Baud rate****************/
#if ((USART_SYNCH_MODE == USART_ASYNCH) && (USART_SPEED_MODE == USART_NORMAL_SPEED))
	#define UBRR_VAL	(u32)((USART_FOSC/(16*USART_BAUD))-1)
//#elif ((USART_SYNCH_MODE == USART_ASYNCH) && (USART_SPEED_MODE == USART_DOUBLE_SPEED))
//	#define UBRR_VAL	(u16)((USART_FOSC/(8*USART_BAUD))-1)
#elif USART_SYNCH_MODE == USART_SYNC
	#define UBRR_VAL	(u32)((USART_FOSC/(2*USART_BAUD))-1)
#endif

/********************USART ENABLE/DISABLE TRANSMITER/RECIEVER********************/
#define USART_ENABLE	1
#define USART_DISABLE	0
/*******************USART CHARACTER SIZE********************/
#define USART_5_Bit_CHAR 		(0b00<<1)
#define USART_6_Bit_CHAR 		(0b01<<1)
#define USART_7_Bit_CHAR	    (0b10<<1)
#define USART_8_Bit_CHAR	    (0b11<<1)
#define USART_9_Bit_CHAR	    (0b11<<1)

/********************USART ASYNCH/SYNCH MODE*********/
#define USART_ASYNCH (0<<6)
#define USART_SYNC   (1<<6)

/********************USART STOP BIT *****************/
#define USART_1_STOPBIT	(0<<3)
#define USART_2_STOPBIT (1<<3)
////////////////////Parity///////////////

#define   USART_NO_PARITY		(0<<4)
#define   USART_EVEN_PARITY		(2<<4)
#define   USART_ODD_PARITY 	    (3<<4)

/********************USART INT ENABLE*********************/
#define USART_RECIEVER_ENABLE 		(1<<7)
#define USART_RECIEVER_DISABLE 		(0<<7)
#define USART_TRANSMITER_ENABLE 	(1<<6)
#define USART_TRANSMITER_DISABLE 	(0<<6)
/***************Global Functions Prototypes***************/

extern void USART_Init(void);
extern void USART_Transmit(u16 data);
extern u8 USART_Receive(u16 *Ptr_To_Val);
extern void USART_Rec_Int_Enable(void);
extern void USART_Rec_Int_Disable(void);
extern void USART_Trans_Int_Enable(void);
extern void USART_Trans_Int_Disable(void);
extern void USART_Rec_Enable(void);
extern void USART_Rec_Disable(void);
extern void USART_Trans_Enable(void);
extern void USART_Trans_Disable(void);
extern void USART_callback_Rec_Int(void (*Ptr_to_Func)(void));
extern void USART_callback_Trans_Int(void (*Ptr_to_Func)(void));
#endif
