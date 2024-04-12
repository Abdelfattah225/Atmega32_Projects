/**********************************************************************************************
 *  SWC				: LCD
 *
 *  File			: LCD_private.h
 *
 *  Created on		: Sep 24, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_
/*LIB*/
#include"STD_TYPES.h"
/*MCAL*/
#include"DIO_private.h"



/*COMMANDS*/
/*cursor*/
#define LCD_Clear_Display_Screen									0x01
#define LCD_Force_cursor_to_beginning_of_first_line					0x80
#define LCD_Force_cursor_to_beginning_of_Second_line				0xC0
#define LCD_Cursor_ON												0x0E
#define LCD_Cursor_OFF												0x0C
#define LCD_Cursor_Blinking											0x0F
#define LCD_Cursor_Increment										0x06
#define LCD_Cursor_decrement										0x04
/*mode of numbers of bits*/
#define LCD_Function_set_8_bit_1_line_mode							0x30
#define LCD_Function_set_8_bit_2_line_mode							0x38
#define LCD_Function_set_4_bit_1_line_mode							0x20
#define LCD_Function_set_4_bit_2_line_mode							0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   			 			0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   			 			0x32
/*display*/
#define LCD_Shift_Display_LEFT										0x07
#define LCD_Shift_Display_RIGHT										0x05


#define BITSET_NUMBER	20
#define ADDRESS_OF_CHAR0_IN_CGRAM			0b01000000
/*mode*/
#define LCD_U8_4_BIT_MODE		4
#define LCD_U8_8_BIT_MODE		8

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
