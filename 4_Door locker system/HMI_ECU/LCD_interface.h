/**********************************************************************************************
 *  SWC				: LCD
 *
 *  File			: LCD_interface.h
 *
 *  Created on		: Sep 24, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/



#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


#define ADDRESS_OF_CHAR0_IN_CGRAM			0b01000000

/*FUNCTIONS*/
void LCD_void_Init(void);

void LCD_void_Write_CMD(u8 Copy_u8_CMD);

void LCD_void_Write(u8 Copy_u8_val);

void LCD_void_Write_Data(u8 Copy_u8_char);

void LCD_void_Write_String(u8 *str);

void LCD_void_Write_Numbers(u32 Copy_U8_Number);

void LCD_void_DDRAM_Address(u8 Copy_u8_Line , u8 Copy_u8_Location);

void LCD_void_Set_CGRAM_Address(u8 Address , u8 *ptr);

void LCD_void_Clear_Screen(void);

void reverse(u8 *ptr , u8 element);

void LCD_integerToString(int data);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
