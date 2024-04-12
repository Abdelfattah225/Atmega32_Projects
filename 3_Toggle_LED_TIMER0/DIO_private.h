/*****************************************************************************/
/* File Defination :
 *
 * File 		: DIO_private.h
 *
 * Created on	: Sep 8, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/



#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#include"STD_TYPES.h"


/*configration portA*/
#define DIO_U8_PORTA 	 *((volatile u8*)0x3B)
#define DIO_U8_DDRA		 *((volatile u8*)0x3A) // casting        volatile -->RAM
#define DIO_U8_PINA	     *((volatile u8*)0x39)
/*configration portB*/
#define DIO_U8_PORTB 	 *((volatile u8*)0x38)
#define DIO_U8_DDRB		 *((volatile u8*)0x37)
#define DIO_U8_PINB  	 *((volatile u8*)0x36)
/*configration portC*/
#define DIO_U8_PORTC  	 *((volatile u8*)0x35)
#define DIO_U8_DDRC 	 *((volatile u8*)0x34)
#define DIO_U8_PINC 	 *((volatile u8*)0x33)
/*configration portC*/
#define DIO_U8_PORTD 	 *((volatile u8*)0x32)
#define DIO_U8_DDRD 	 *((volatile u8*)0x31)
#define DIO_U8_PIND  	 *((volatile u8*)0x30)

#define DIO_U8_INTIAL_INPUT		0
#define DIO_U8_INTIAL_OUTPUT	1

#define DIO_MAX_U8_PROT_ID		3
#define DIO_MIN_U8_PROT_ID		0
#define DIO_MAX_U8_PIN_ID		7
#define DIO_MIN_U8_PIN_ID		0




#endif /* DIO_PRIVATE_H_ */
