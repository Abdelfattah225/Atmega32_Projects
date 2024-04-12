/*
 * APP.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Administrator
 */

#define F_CPU	8000000UL
#include<util/delay.h>
///*LIB*/
#include"BIT_CALC.h"
#include"STD_TYPES.h"
///*HAL*/
#include"LCD_interface.h"
#include"KEYPAD_interface.h"
///*MCAL*/
#include"DIO_interface.h"
#include"UART_interface.h"
#include"UART_private.h"
/**/
#include"APP.h"



/************************************FUNCTIONS PROTOTYPE*******************************/
static void APP_voidtakePass();
static void APP_voidMainMenuScreen();
//static void APP_voidTruePasswordScreen();
static void	APP_voidThiefAlert();
//static void APP_voidOpenDoorScreen();
//static void APP_voidChangePasswordScreen();
//static void APP_voidWrongPasswordScreen();
static void APP_voidWrongPasswordScreen(u8 illetrations);

/************************************FUNCTIONS*******************************/

void APP_voidInit()
{
		DIO_void_Init();
		LCD_void_Init();
		KPD_Init();
		UART_void_Init();
}

void APP_voidWelcomeScreen()
{
//	LCD_void_Clear_Screen();
//	LCD_void_Write_String("welcome my user");
//	_delay_ms(LONG_DELAY);
	APP_voidtakePass();
}

static void APP_voidtakePass(){
	 u8 Enter_Password[5] ;
	 Enter_Password[4]='K';
	 u8 state = WRONG_PASSWORD ;
	 	 for(u8 i = 0 ; (i<3 && state==WRONG_PASSWORD) ; i++)
	 	 {
	 		 LCD_void_Clear_Screen();
	 		 LCD_void_Write_String("Plz Enter Pass : ");
	 		 LCD_void_DDRAM_Address(1,0);
	 		 /*get password*/
	 		 for(u8 j = 0 ; j<4 ; j++)
	 		 {
	 			Enter_Password[j] = KPD_Void_GET_Status();
	 			_delay_ms(200);
	 			LCD_void_Write_Data('*');
	 		 }


	 		 state = CORRECT_PASSWORD;
	 		 UART_void_Send_String(Enter_Password);

	 		Clear_Bit(UART_U8_UCSRA,7);
	 		 state = UART_U8_Receive_Char() ;
	 		DIO_U8_Set_Pin_Dir(PORTD_ID,7,1);
	 			 			 			 		DIO_U8_Set_Pin_value(PORTD_ID,7,1);
	 		if(state==WRONG_PASSWORD)
	 		{

	 			APP_voidWrongPasswordScreen(2-i);
	 		}

	 	 }
	 	 if(state == CORRECT_PASSWORD)
	 	 {

	 		APP_voidMainMenuScreen();
	 	 }
	 	 else
	 	 {
	 		APP_voidThiefAlert();
	 		APP_voidWelcomeScreen();
	 	 }

}


static void APP_voidMainMenuScreen()
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("1] Open Door");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("2] Change Pass");


	u8 pressedkey = KPD_Void_GET_Status();

	if(pressedkey =='1')
	{
//		APP_voidOpenDoorScreen();
	}
	else if (pressedkey =='2')
	{
//		APP_voidChangePasswordScreen();
	}
	else
	{
		LCD_void_Clear_Screen();
		LCD_void_Write_String("wrong input");
		_delay_ms(SHORT_DELAY);
		LCD_void_Clear_Screen();
		LCD_void_Write_String("Reset.");
		_delay_ms(SHORT_SHORT_DELAY);
		LCD_void_Write_String("Reset..");
		_delay_ms(SHORT_SHORT_DELAY);
		LCD_void_Write_String("Reset...");

		APP_voidMainMenuScreen();
	}
}


static void	APP_voidThiefAlert()
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("Thief Alert !!");
	DIO_U8_Set_Pin_value(BUZZER_PORT , BUZZER_PIN , PIN_HIGH);
	_delay_ms(LONG_DELAY);
	DIO_U8_Set_Pin_value(BUZZER_PORT , BUZZER_PIN , PIN_LOW);


}







//
//static void APP_voidTruePasswordScreen(){
//
//
//}
//static void APP_voidOpenSafeScreen()
//{
//
//}
//static void APP_voidChangePasswordScreen()
//{
//}
static void APP_voidWrongPasswordScreen(u8 illetrations)
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("wrong password");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("Tires Left ");
	LCD_void_Write_Numbers(illetrations);
}
