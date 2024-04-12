/**********************************************************************************************
 *  SWC				: MCAL
 *
 *  File			: UART_program.c
 *
 *  Created on		: Oct 28, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/
#include"BIT_CALC.h"
#include"STD_Types.h"
#include"DIO_interface.h"


#include"UART_config.h"
#include"UART_private.h"
#include"UART_interface.h"

void UART_void_Init(void)
{
	UART_U8_UBRRH = 0 ;    // Reg select is UBRRH
	UART_U8_UBRRL = 51 ;   // UBRR value = (system frq / (16*bude rate) ) -1
	UART_U8_UCSRC = 0b10000110; // REG select is UCSRC
								// Asynch
								// no parity
								// stop bit


	UART_U8_UCSRB=0b00011000;   // receiver enable , tx enable
								// 8 bits --> data bits


}
void UART_void_Send_Char(u8 Copy_U8_Data)
{
	while(Get_Bit(UART_U8_UCSRA,5)==0);
//	Set_Bit(UART_U8_UCSRA,5);
	UART_U8_UDR = Copy_U8_Data ;

}

u8 UART_U8_Receive_Char(void)
{
	while(Get_Bit(UART_U8_UCSRA,7)==0);
	return UART_U8_UDR ;
}

void UART_void_Send_String(u8 *Copy_U8_Str)
{
	while(*Copy_U8_Str != '\0')
	{
		UART_void_Send_Char(*Copy_U8_Str);
		Copy_U8_Str++;
	}
}
void UART_void_Receive_String(u8 *Copy_U8_arr)
{
	u8 i=0;
	// use do while
	Copy_U8_arr[i] = UART_U8_Receive_Char();

	while(Copy_U8_arr[i]!='K')
	{
	i++;
	Copy_U8_arr[i] = UART_U8_Receive_Char();

	}
}
