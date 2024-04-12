/**********************************************************************************************
 *  SWC				: LCD
 *
 *  File			: LCD_program.c
 *
 *  Created on		: Sep 24, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

/******************************************< inclusion >************************************/

#include"util/delay.h"
#define F_CPU  8000000UL
/*LIB*/
#include"STD_TYPES.h"
#include"BIT_CALC.h"
/*MCAL*/
#include"DIO_interface.h"
/*HAL*/
#include"LCD_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"




void LCD_void_Init(void){
#if LCD_U8_MODE==LCD_U8_8_BIT_MODE
		/*delay more than 30ms*/
		_delay_ms(35);
		/*send function set */
		LCD_void_Write_CMD(LCD_Function_set_8_bit_2_line_mode);
		/*delay more than 39us*/
		_delay_us(40);
		/*send cursor mode */
		LCD_void_Write_CMD(LCD_Cursor_OFF);
		/*delay more than 39us*/
		_delay_us(40);
		/*send command clear display*/
		LCD_void_Write_CMD(LCD_Clear_Display_Screen);
		/*delay more than 1.53ms*/
		_delay_ms(2);
		/*increment cursor*/
		LCD_void_Write_CMD(LCD_Cursor_Increment);
#elif LCD_U8_MODE==LCD_U8_4_BIT_MODE
		/*code of send intializtion of 4 bit mode*/
		/*delay more than 30ms*/
		_delay_ms(35);
		/*send function set */
		LCD_void_Write_CMD(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
		LCD_void_Write_CMD(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);
		LCD_void_Write_CMD(LCD_Function_set_4_bit_2_line_mode);
		LCD_void_Write_CMD(LCD_Function_set_4_bit_2_line_mode);
			/*delay more than 39us*/
		_delay_us(40);
		/*send cursor mode */
		LCD_void_Write_CMD(LCD_Cursor_OFF);
		/*delay more than 39us*/
		_delay_us(40);
		/*send command clear display*/
		LCD_void_Write_CMD(LCD_Clear_Display_Screen);
		/*delay more than 1.53ms*/
		_delay_ms(2);
		/*increment cursor*/
		LCD_void_Write_CMD(LCD_Cursor_Increment);


#endif




}

void LCD_void_Write_CMD(u8 Copy_u8_CMD){

	/*steps*/
	/*RS=0*/
	/*RW=0*/
	/*write a command*/
	/*E=1*/
	/*E=0*/
//	DIO_U8_Set_Pin_Dir(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_OUTPUT);
	DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_LOW);

	LCD_void_Write(Copy_u8_CMD);

}



void LCD_void_Write(u8 Copy_u8_val){

	/*RW=0*/
		DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_RW_PIN,PIN_LOW);

#if LCD_U8_MODE==LCD_U8_8_BIT_MODE

	/*WRITE */
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN0,Get_Bit(Copy_u8_val,DIO_U8_PIN0));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN1,Get_Bit(Copy_u8_val,DIO_U8_PIN1));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN2,Get_Bit(Copy_u8_val,DIO_U8_PIN2));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN3,Get_Bit(Copy_u8_val,DIO_U8_PIN3));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN4,Get_Bit(Copy_u8_val,DIO_U8_PIN4));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN5,Get_Bit(Copy_u8_val,DIO_U8_PIN5));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN6,Get_Bit(Copy_u8_val,DIO_U8_PIN6));
	DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN7,Get_Bit(Copy_u8_val,DIO_U8_PIN7));
	/*E=1*/
	/*E=0*/
	DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_E_PIN,PIN_HIGH);
	_delay_us(1);
	DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_E_PIN,PIN_LOW);

#elif LCD_U8_MODE==LCD_U8_4_BIT_MODE
		/*code of send intializtion of 4 bit mode*/
/*MSB*/

		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN4,Get_Bit(Copy_u8_val,DIO_U8_PIN4));
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN5,Get_Bit(Copy_u8_val,DIO_U8_PIN5));
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN6,Get_Bit(Copy_u8_val,DIO_U8_PIN6));
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN7,Get_Bit(Copy_u8_val,DIO_U8_PIN7));
		/*E=1*/
		/*E=0*/
		DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_E_PIN,PIN_HIGH);
		_delay_us(1);
		DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_E_PIN,PIN_LOW);
/*LSB*/
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN4,Get_Bit(Copy_u8_val,DIO_U8_PIN0));
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN5,Get_Bit(Copy_u8_val,DIO_U8_PIN1));
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN6,Get_Bit(Copy_u8_val,DIO_U8_PIN2));
		DIO_U8_Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN7,Get_Bit(Copy_u8_val,DIO_U8_PIN3));
		/*E=1*/
		/*E=0*/
		DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_E_PIN,PIN_HIGH);
		_delay_us(1);
		DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_E_PIN,PIN_LOW);

#endif


}


void LCD_void_Write_Data(u8 Copy_u8_char)
{
	/*steps*/
		/*RS=1*/
//	DIO_U8_Set_Pin_Dir(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_OUTPUT);
	DIO_U8_Set_Pin_value(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_HIGH);
		/*RW=0*/
		/*write a data*/
		/*E=1*/
		/*E=0*/
	LCD_void_Write(Copy_u8_char);
}




void LCD_void_Write_String(u8 *str)
{
	while( *str!='\0')
	{
		LCD_void_Write_Data(*str);
		str++;
	}
}


void LCD_void_Write_Numbers(u32 Copy_U8_Number)
{
	u8 rem ;
	u8 index=0 ;
	u8 arr[BITSET_NUMBER];
	if(Copy_U8_Number == 0){
		arr[index]='0';
		index++;
	}
	while(Copy_U8_Number!=0)
	{
		rem=Copy_U8_Number%10;
		arr[index]=rem+'0';
		index++;
		Copy_U8_Number/=10;
	}
	arr[index]='\0';
	reverse(arr,index);
	LCD_void_Write_String(arr);

}

void reverse(u8 *ptr , u8 element)
{
	u8 start = 0;
	u8 end = element-1;
	while(start<end)
	{
		u32 temp = ptr[start];
		ptr[start]=ptr[end];
		ptr[end]=temp;
		start++;
		end--;

	}
}


void LCD_void_DDRAM_Address(u8 Copy_u8_Line , u8 Copy_u8_Location)
{
	u8 DDRAM_Address = (Copy_u8_Location+(64*Copy_u8_Line));
	DDRAM_Address|=0b10000000;
	LCD_void_Write_CMD(DDRAM_Address);
}


void LCD_void_Set_CGRAM_Address(u8 Address , u8 *ptr)
{
	LCD_void_Write_CMD(Address);
	for(u8 i =0 ; i<8 ; i++)
	{
		LCD_void_Write_Data(*ptr);
		ptr++;
	}

}

void LCD_void_Clear_Screen(void)
{
	LCD_void_Write_CMD(LCD_Clear_Display_Screen);
	_delay_ms(2);
}


/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_integerToString(int data)
{
   char arr[16];

   /* store the integer number to arr & 10 is for decimal numbering system*/
   itoa(data,arr,10);

   LCD_void_Write_String(arr);
}
