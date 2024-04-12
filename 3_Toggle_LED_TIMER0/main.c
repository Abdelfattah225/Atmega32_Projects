/**********************************************************************************************
 *  SWC				: app
 *
 *  File			: mian.c
 *
 *  Created on		: oct 14, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

/******************************************< inclusion >************************************/


#include<util/delay.h>
///*LIB*/
#include"BIT_CALC.h"
#include"STD_TYPES.h"
///*HAL*/
#include"LCD_interface.h"
///*MCAL*/
#include"DIO_interface.h"
#include"TIMER0_interface.h"


void main(void)
{
	extern f32 Number_ovf ;
	extern f64  Time_ovf;
	DIO_void_Init();
	LCD_void_Init();
	DIO_U8_Set_Pin_Dir(PORTA_ID,DIO_U8_PIN0,PIN_OUTPUT);
	TIMER0_void_Init();
	LCD_void_Write_Numbers((u32)Number_ovf);
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_Numbers(Time_ovf);
	while(1){

	}

}






