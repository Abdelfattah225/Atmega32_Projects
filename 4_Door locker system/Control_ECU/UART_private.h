/**********************************************************************************************
 *  SWC				: MCAL
 *
 *  File			: UART_private.h
 *
 *  Created on		: Oct 28, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UART_U8_UDR		 	 *((volatile u8*)0x2C)
#define UART_U8_UCSRA	 	 *((volatile u8*)0x2B)
#define UART_U8_UCSRB	 	 *((volatile u8*)0x2A)
#define UART_U8_UCSRC		 *((volatile u8*)0x40)
#define UART_U8_UBRRL	 	 *((volatile u8*)0x29)
#define UART_U8_UBRRH	 	 *((volatile u8*)0x40)

#endif /* UART_PRIVATE_H_ */
