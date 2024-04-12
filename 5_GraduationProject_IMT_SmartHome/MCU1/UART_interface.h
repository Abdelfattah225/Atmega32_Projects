/**********************************************************************************************
 *  SWC				: MCAL
 *
 *  File			: UART_interface.h
 *
 *  Created on		: Oct 28, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/



#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_void_Init(void);
void UART_void_Send_Char(u8 Copy_U8_Data);
u8 UART_U8_Receive_Char(void);
void UART_void_Send_String(u8 *Copy_U8_Str);
void UART_void_Receive_String(u8 *Copy_U8_arr);


#endif /* UART_INTERFACE_H_ */
