/*
 * app.c
 *
 *  Created on: Oct 15, 2023
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
/**/
#include"app.h"


u8 password[]={'1','2','3','4'};

static void APP_voidMainMenuScreen();
static void APP_voidTruePasswordScreen();
static void APP_voidOpenSafeScreen();
static void APP_voidChangePasswordScreen();
static void APP_voidChangePassword();
static void APP_voidWrongPasswordScreen(u8 lletrations);
static void APP_voidThiefAlert();
static void APP_voidTruePasswordScreen();


void APP_voidInit(){
		DIO_void_Init();
		LCD_void_Init();
		KPD_Init();
}

void APP_voidWelcomeScreen()
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("welcome my user");
	_delay_ms(LONG_DELAY);
	APP_voidMainMenuScreen();
}


static void APP_voidMainMenuScreen()
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("1] Open Safe");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("2] Change Pass");


	u8 pressedkey = KPD_Void_GET_Status();

	if(pressedkey =='1')
	{
		APP_voidOpenSafeScreen();
	}
	else if (pressedkey =='2')
	{
		APP_voidChangePasswordScreen();
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

		APP_voidWelcomeScreen();
	}

}


static void APP_voidOpenSafeScreen()
{

 u8 Enter_Password[4] ;
 u8 state = WRONG_PASSWORD ;
 	 for(u8 i = 0 ; (i<3 && state==WRONG_PASSWORD) ; i++)
 	 {
 		 LCD_void_Clear_Screen();
 		 LCD_void_Write_String("Plz Enter Pass");
 		 LCD_void_DDRAM_Address(1,0);
 		 /*get password*/
 		 for(u8 j = 0 ; j<4 ; j++)
 		 {
 			Enter_Password[j] = KPD_Void_GET_Status();
 			_delay_ms(200);
 			LCD_void_Write_Data('*');
 		 }

 		 state = CORRECT_PASSWORD;

 		 /*check password*/
 		 for(u8 j = 0 ; j<4 ; j++)
 		 {
 			 if(Enter_Password[j]!=password[j])
 			 {
 				state =WRONG_PASSWORD;
 				APP_voidWrongPasswordScreen(2-i);
 				break;
 			 }
 		 }
 	 }

 	 if(state == CORRECT_PASSWORD)
 	 {
 		APP_voidTruePasswordScreen();
 		APP_voidMainMenuScreen();
 	 }
 	 else
 	 {
 		APP_voidThiefAlert();
 		APP_voidMainMenuScreen();
 	 }

}






static void APP_voidWrongPasswordScreen(u8 illetrations)
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("wrong password");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("Tires Left ");
	LCD_void_Write_Numbers(illetrations);

	DIO_U8_Set_Pin_value(LED_RED_PORT , LED_RED_PIN , PIN_HIGH);
	_delay_ms(SHORT_DELAY);
	DIO_U8_Set_Pin_value(LED_RED_PORT , LED_RED_PIN , PIN_LOW);
}


static void APP_voidTruePasswordScreen(){
		LCD_void_Clear_Screen();
		LCD_void_Write_String("True password!!");
		DIO_U8_Set_Pin_value(LED_GREEN_PORT , LED_GREEN_PIN , PIN_HIGH);
		_delay_ms(LONG_DELAY);
		DIO_U8_Set_Pin_value(LED_GREEN_PORT , LED_GREEN_PIN , PIN_LOW);
}

static void APP_voidThiefAlert(){
static u8 state = 0;
		LCD_void_Clear_Screen();
		LCD_void_Write_String("Thief Alert !!");
		DIO_U8_Set_Pin_value(LED_RED_PORT , LED_RED_PIN , PIN_HIGH );
		DIO_U8_Set_Pin_value(BUZZER_PORT , BUZZER_PIN , PIN_HIGH);
		_delay_ms(LONG_DELAY);
		DIO_U8_Set_Pin_value(BUZZER_PORT , BUZZER_PIN , PIN_LOW);
		DIO_U8_Set_Pin_value(LED_RED_PORT , LED_RED_PIN , PIN_LOW);
}


static void APP_voidChangePasswordScreen()
{
	u8 old_password[4];
	u8 state = WRONG_PASSWORD ;
	for(u8 i=0 ; (i<3 && state ==WRONG_PASSWORD) ; i++ )
	{
		LCD_void_Clear_Screen();
		LCD_void_Write_String("Enter old pass");
		LCD_void_DDRAM_Address(1,0);
		/*get password*/
		for(u8 j = 0 ; j<4 ; j++)
		{
			old_password[j] = KPD_Void_GET_Status();
			_delay_ms(200);
			LCD_void_Write_Data('*');
		}
		state = CORRECT_PASSWORD ;
		/*check password*/
		for(u8 j = 0 ; j<4 ; j++)
		{
			if(old_password[j] != password[j] )
			{
				state = WRONG_PASSWORD ;
				APP_voidWrongPasswordScreen(2-i);
				break;
			}
		}

	}
	if(state == WRONG_PASSWORD)
	{
		APP_voidThiefAlert();
		APP_voidMainMenuScreen();
	}
	else
	{
		APP_voidChangePassword();
		APP_voidMainMenuScreen();
	}
}


static void APP_voidChangePassword()
{

	LCD_void_Clear_Screen();
	LCD_void_Write_String("Enter New Pass");
	LCD_void_DDRAM_Address(1,0);

	for(u8 i=0 ; i<4 ; i++)
	{
		password[i] = KPD_Void_GET_Status();
		_delay_ms(200);
		LCD_void_Write_Data('*');
	}

}
