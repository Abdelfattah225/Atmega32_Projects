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


static void APP_voidMainMenuScreen();
static void APP_voidTakefirstoperator();
static void APP_voidTakesecondoperator();
static void APP_voidTakethirdoperator();
static void APP_voidTakefourthoperator();
static void APP_voidTakefristnumber();
static void APP_voidTakeSecondNumber();
static void APP_voidTakeThirdNumber();
static void APP_voidTakeFouthNumber();


static u8 pressedkey ;
static u32 number1= 0;
static u32 number2= 0;
static u32 number3= 0;
static u32 number4= 0;
static f32 result;
static u8 arr_of_operator[3];


void APP_voidInit(){
		DIO_void_Init();
		LCD_void_Init();
		KPD_Init();
}

void APP_voidWelcomeScreen()
{
//	LCD_void_Clear_Screen();
//	LCD_void_Write_String("Adv. Calculator");
//	_delay_ms(LONG_DELAY);
	APP_voidMainMenuScreen();
}


static void APP_voidMainMenuScreen()
{

	LCD_void_Clear_Screen();
	APP_voidTakefristnumber();


}
static void APP_voidTakefristnumber()
{
	 pressedkey = KPD_Void_GET_Status();
		while(pressedkey>='0' && pressedkey<='9')
		{
			number1 *= 10 ;
			number1 += (pressedkey-'0');
			LCD_void_Write_Data(pressedkey);
			pressedkey = KPD_Void_GET_Status();
		}
		APP_voidTakefirstoperator();
}
static void APP_voidTakefirstoperator()
{
	switch(pressedkey)
		{
		case '=' :

			LCD_void_Clear_Screen();
			LCD_void_DDRAM_Address(0,5);
			LCD_void_Write_String("!!Error!!");
			_delay_ms(1000);
			LCD_void_Clear_Screen();
			LCD_void_Write_Numbers(number1);
			pressedkey = KPD_Void_GET_Status();
			APP_voidTakefirstoperator();

			break;

		case '%' :
			APP_voidWelcomeScreen();
			result=0;
			number1=0;
			number2=0;
			number3=0;
			number4=0;
			break;
		default:
			LCD_void_Write_Data(pressedkey);
			arr_of_operator[0]=pressedkey;
			APP_voidTakeSecondNumber();
			break;
		}

}

static void APP_voidTakeSecondNumber()
{
	 	 	 pressedkey = KPD_Void_GET_Status();
			while(pressedkey>='0' && pressedkey<='9')
			{
				number2 *= 10 ;
				number2 += (pressedkey-'0');
				LCD_void_Write_Data(pressedkey);
				pressedkey = KPD_Void_GET_Status();
			}
			APP_voidTakesecondoperator();
}

static void APP_voidTakesecondoperator()
{
	switch(arr_of_operator[0])
	{
				case '+':
					(result) = (number1+number2);
					break;
				case '-': (result) =number1-number2;
					break;
				case '/':
					(result) =number1 / number2;
					break;
				case '*':
					(result) =number1*number2;
					break;
	}

	switch(pressedkey)
		{
		case '=' :
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Answer:");
			LCD_void_Write_Numbers(result);
			pressedkey = KPD_Void_GET_Status();
			if(pressedkey=='%')
				{
				result=0;
				number1=0;
				number2=0;
				number3=0;
				number4=0;
				APP_voidMainMenuScreen();
				}
			else
			{
				_delay_ms(500);
				result=0;
							number1=0;
							number2=0;
							number3=0;
							number4=0;

				APP_voidMainMenuScreen();
			}

			break;

		case '%' :
			result=0;
						number1=0;
						number2=0;
						number3=0;
						number4=0;
						APP_voidMainMenuScreen();
			break;
		default:
			LCD_void_Write_Data(pressedkey);
			arr_of_operator[1]=pressedkey;
			APP_voidTakeThirdNumber();
			break;
		}
}


static void APP_voidTakeThirdNumber()
{
	 pressedkey = KPD_Void_GET_Status();
				while(pressedkey>='0' && pressedkey<='9')
				{
					number3 *= 10 ;
					number3 += (pressedkey-'0');
					LCD_void_Write_Data(pressedkey);
					pressedkey = KPD_Void_GET_Status();
				}
				APP_voidTakethirdoperator();
}


static void APP_voidTakethirdoperator()
{
	switch(arr_of_operator[1]){
				case '+':
					(result) +=number3;
					break;
				case '-': (result) -=number3;
					break;

				case '/':
					(result) /=number3;
					break;

				case '*':
					(result) *=number3;
					break;
				}

	switch(pressedkey)
		{
		case '=' :
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Answer:");
			LCD_void_Write_Numbers(result);
			pressedkey = KPD_Void_GET_Status();
			if(pressedkey=='%')
			{
				result=0;
										number1=0;
										number2=0;
										number3=0;
										number4=0;
										APP_voidMainMenuScreen();
			}
				else
			{
					result=0;
											number1=0;
											number2=0;
											number3=0;
											number4=0;
											_delay_ms(500);
				APP_voidMainMenuScreen();
			}

			break;

		case '%' :
			result=0;
									number1=0;
									number2=0;
									number3=0;
									number4=0;
									APP_voidMainMenuScreen();
			break;
		default:
			LCD_void_Write_Data(pressedkey);
			arr_of_operator[2]=pressedkey;
			APP_voidTakeFouthNumber();
			break;
		}
}

static void APP_voidTakeFouthNumber()
{
	 pressedkey = KPD_Void_GET_Status();
					while(pressedkey>='0' && pressedkey<='9')
					{
						number4 *= 10 ;
						number4 += (pressedkey-'0');
						LCD_void_Write_Data(pressedkey);
						pressedkey = KPD_Void_GET_Status();
					}
					APP_voidTakefourthoperator();


}


static void APP_voidTakefourthoperator()
{
	switch(arr_of_operator[2]){
				case '+':
					(result) +=number4;
					break;
				case '-': (result) -=number4;
					break;

				case '/':
					(result) /=number4;
					break;

				case '*':
					(result) *=number4;
					break;
				}

	switch(pressedkey)
		{
		case '=' :
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Answer:");
			LCD_void_Write_Numbers(result);
			pressedkey = KPD_Void_GET_Status();
			if(pressedkey=='%')
				{
				result=0;
										number1=0;
										number2=0;
										number3=0;
										number4=0;
										APP_voidMainMenuScreen();
				}
			else
			{
				result=0;
										number1=0;
										number2=0;
										number3=0;
										number4=0;				_delay_ms(500);
				APP_voidMainMenuScreen();
			}

			break;



		default:
			result=0;
			number1=0;
			number2=0;
			number3=0;
			number4=0;
									APP_voidMainMenuScreen();

			}
}
