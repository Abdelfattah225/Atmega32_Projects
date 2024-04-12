/*
 * Door.c
 *
 *  Created on: Feb 3, 2024
 *      Author: Administrator
 */
/***************************************************************************/

#define F_CPU  8000000UL
#include"util/delay.h"
#include"Door.h"
/*LIB*/
#include"BIT_CALC.h"
#include"STD_Types.h"
/*HAL*/
#include"LCD_interface.h"
#include"KEYPAD_interface.h"
#include"Servo_interface.h"
/*MCAL*/
#include"DIO_interface.h"
#include"DIO_private.h"
#include"TIMER1_interface.h"
#include"UART_interface.h"

/********************************************************************************/

u8 adminPass[NumAdminPass]={'1','1','1','1'};
u8 EmadPass[4]={'2','2','2','2'};
u8 HamadaPass[4]={'3','3','3','3'};

static void start_project();
static void AdminModeDoor();
static void GuestModeDoor();
static void WrongPassword(u8 iteration);
static void BlockMode();
static void TrueAdminPass();
static void AdminChoosedHome();
static void AdminChoosedGrage();
static void WrongChoice();
/**********/
static void TrueGuestPass();




/**********************************************************************************/

void DOOR_INIT()
{
	DIO_void_Init();
	LCD_void_Init();
	KPD_Init();
	ADC_void_Init();
	TIMER1_void_Init();
	SERVO_void_Init();
	UART_void_Init();


}

void WelcomeMainScreen()
{

	LCD_void_Clear_Screen();
	LCD_void_Write_String("Welcome to my");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("Smart Home");
	_delay_ms(SHORT_DELAY);
	start_project();

}

static void start_project()
{
	u8 Password_door;

	LCD_void_Clear_Screen();
		LCD_void_Write_String("  Select Mode:  ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("1-Admin  2-Guest");

			Password_door = KPD_Void_GET_Status();

			if(Password_door=='1')
			{

				AdminModeDoor();
			}
			else if(Password_door=='2')
			{
				GuestModeDoor();
			}
			else
			{
				WrongChoice();
				WelcomeMainScreen();
			}


}
static void AdminModeDoor()
{
	u8 statePass = WrongPass ;
	u8 adminEnterPass[4];


	for(u8 j=0 ; (j<Tries && statePass==WrongPass);j++)
	{

			LCD_void_Clear_Screen();
			LCD_void_Write_String("  Admin Mode:  ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Enter Pass:");

		/*get password*/
		for(u8 k =0 ; k<NumAdminPass ; k++)
		{
			adminEnterPass[k] = KPD_Void_GET_Status();
			_delay_ms(MINI_DELAY);
			LCD_void_Write_Data('*');

		}

		statePass=TruePass;

		/*check password*/
		for(u8 i=0 ; i<NumAdminPass ; i++)
		{
			if(adminEnterPass[i] != adminPass[i])
			{
				statePass=WrongPass;
				WrongPassword(2-j);
				break;
			}
		}

	}
	if(statePass==TruePass)
		{

		LCD_void_Clear_Screen();
		LCD_void_Write_String("    Welcome    ");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("   Abdelfattah  ");
		_delay_ms(SHORT_DELAY);
		TrueAdminPass();

		}
	else if(statePass==WrongPass)
		{

		BlockMode();

		}




}



static void WrongPassword(u8 iteration)
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("Wrong Password");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("Tries Left");
	LCD_void_Write_Numbers(iteration);
	_delay_ms(SHORT_DELAY);
}



static void TrueAdminPass()
{

	u8 pressedkey;
	DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN3,PIN_HIGH);
	LCD_void_Clear_Screen();
	LCD_void_Write_String("1:Home  2:Grage");
	pressedkey = KPD_Void_GET_Status();
	if(pressedkey=='1')
	{
		AdminChoosedHome();
	}
	else if(pressedkey=='2')
	{
		AdminChoosedGrage();
	}
	else
	{
		WrongChoice();
		TrueAdminPass();
	}

}


static void BlockMode()
{
		DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN5,PIN_HIGH);
		LCD_void_Clear_Screen();
		LCD_void_Write_String("Login Blocked");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Wait 5 second ");
		_delay_ms(1000);
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Wait 4 second ");
		_delay_ms(1000);
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Wait 3 second ");
		_delay_ms(1000);
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Wait 2 second ");
		_delay_ms(1000);
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Wait 1 second ");
		_delay_ms(1000);
		DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN5,PIN_LOW);
		WelcomeMainScreen();
	}


static void AdminChoosedHome()
{
	LCD_void_Clear_Screen();
	LCD_void_Write_String("   Home Door");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("   Will Open");
	/*on the motor*/
	SERVO_void_Enable(90,SERVO_OC1A);
	_delay_ms(3000);

	LCD_void_Clear_Screen();
	LCD_void_Write_String("   Home Door");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("Will close again");
	/*off the motor*/
	SERVO_void_Enable(0,SERVO_OC1A);


_delay_ms(1000);



	UART_void_Send_Char('A');
	DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN3,PIN_LOW);
	start_project();



}


static void AdminChoosedGrage()
{
		LCD_void_Clear_Screen();
		LCD_void_Write_String("   Grage Door");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("   Will Open");
		/*on the motor*/
		SERVO_void_Enable(90,SERVO_OC1B);
		_delay_ms(3000);

		LCD_void_Clear_Screen();
		LCD_void_Write_String("   Grage Door");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Will close again");
		/*off the motor*/
		SERVO_void_Enable(0,SERVO_OC1B);
		_delay_ms(1000);
		DIO_U8_Set_Pin_value(PORTA_ID,3,0);
		start_project();

}

static void WrongChoice()
{
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Wrong Choice");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Choose again");
			_delay_ms(SHORT_DELAY);
}
/*********************************************************************/


static void GuestModeDoor()
{
	u8 statePass = WrongPass ;
		u8 GuestEnterPass[4];
		u8 guestis ;

		for(u8 j=0 ; (j<Tries && statePass==WrongPass);j++)
		{

				LCD_void_Clear_Screen();
				LCD_void_Write_String("  Guest Mode:  ");
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("Enter Pass:");

			/*get password*/
			for(u8 k =0 ; k<4 ; k++)
			{
				GuestEnterPass[k] = KPD_Void_GET_Status();
				_delay_ms(MINI_DELAY);
				LCD_void_Write_Data('*');

			}

			statePass=TruePass;
			guestis = Emad;

			/*check password*/
			for(u8 i=0 ; i<4 ; i++)
			{
				if((GuestEnterPass[i] != EmadPass[i]) )
				{

					guestis=Hamada;
					if(GuestEnterPass[i]!= HamadaPass[i])
						{
							statePass=WrongPass;
							WrongPassword(2-j);
								break;
						}

				}


			}

		}
		if(statePass==TruePass)
			{

			if(guestis==Emad)
			{
				LCD_void_Clear_Screen();
				LCD_void_Write_String("Right Password");
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("Welcome Emad");
				_delay_ms(SHORT_DELAY);
				/*send to another microcontroller to display guest Emad outside*/
				UART_void_Send_Char('E');
				/**/
				TrueGuestPass();
			}
			else if(guestis==Hamada)
			{
				LCD_void_Clear_Screen();
				LCD_void_Write_String("Right Password");
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("Welcome Hamada");
				_delay_ms(SHORT_DELAY);
				/*send to another microcontroller to display guest Emad outside*/
				UART_void_Send_Char('H');
				/**/
				TrueGuestPass();

			}

		}
		else if(statePass==WrongPass)
			{

			BlockMode();

			}

}



static void TrueGuestPass()
{
	u8 i=0;
	u8 state=0;

	/**/
	DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN4,PIN_HIGH);
	LCD_void_Clear_Screen();
	LCD_void_Write_String("Bell will ring");
	/*trun on bell*/
	DIO_U8_Set_Pin_Dir(PORTA_ID,DIO_U8_PIN6,PIN_OUTPUT);
	while(i<10)
	{
		DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN6,Get_Bit(state,0));
		_delay_ms(300);
		i++;
		Toggle_Bit(state,0);
	}

	/*turn off bell*/
	LCD_void_Clear_Screen();
	LCD_void_Write_String("Bell will ");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("Turn OFF!!!");
	DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN6,PIN_LOW);
	_delay_ms(2000);
	DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN4,PIN_LOW);
	start_project();


}
