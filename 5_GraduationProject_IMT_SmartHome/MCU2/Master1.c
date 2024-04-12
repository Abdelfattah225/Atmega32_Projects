/*
 * Master1.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Administrator
 */

#define F_CPU  8000000UL
#include"util/delay.h"
#include"Master1.h"
/*LIB*/
#include"BIT_CALC.h"
#include"STD_Types.h"
/*HAL*/
#include"LCD_interface.h"
#include"KEYPAD_interface.h"
/*MCAL*/
#include"DIO_interface.h"
#include"DIO_private.h"
#include"UART_interface.h"
#include"SPI_interface.h"
/********************************************************************************/
Room[5]={0};
u8 receivedData;
u8 Air_Cond;
static void recived_A();
static void WrongChoice();
static void AdminMode();
static void GuestMode();
static void MoreOptions();
static void AdminRoomStatus(u8 RoomNumber , u8 status);
static void AdminAirCondStatus();
static void AdminTVStatus(u8 RoomNumber , u8 status);
static void GuestRoomStatus(u8 RoomNumber , u8 status);

/********************************************************************************/

void Init_Master()
{
	DIO_void_Init();
	LCD_void_Init();
	KPD_Init();
	UART_void_Init();
	SPI_Void_Init();

}






void recieve_order()
{
	u8 recieve_order ;

	recieve_order = UART_U8_Receive_Char();

	LCD_void_Clear_Screen();
	switch(recieve_order)
	{
	case 'A':

		LCD_void_Clear_Screen();
		LCD_void_Write_String("Welcome Home");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("Admin Abdelfatah");
		_delay_ms(2000);
		 recived_A();


		    break;
	case 'E':
				LCD_void_Clear_Screen();
				LCD_void_Write_String("Guest Emad");
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("Outside!!!");

			break;
	case 'H':
						LCD_void_Clear_Screen();
						LCD_void_Write_String("Guest Hamada");
						LCD_void_DDRAM_Address(1,0);
						LCD_void_Write_String("Outside!!!");

			break;

	}
}

/********************************************************************************/
static void recived_A()
{


			LCD_void_Clear_Screen();
			LCD_void_Write_String("   Slect Mode:   ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("1:Admin  2:Guest");

	u8 pressed_key;
	pressed_key=KPD_Void_GET_Status();
	if(pressed_key=='1')
	{
		AdminMode();
	}
	else if(pressed_key=='2')
	{
		GuestMode();
	}
	else
	{
		WrongChoice();
		recived_A();
	}
}

static void recived_G()
{
	recieve_order();
}
static void WrongChoice()
{
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Wrong Choice");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Choose again");
			_delay_ms(1000);
}

static void AdminMode()
{
	u8 pressed_key;
	LCD_void_Clear_Screen();
	LCD_void_Write_String("1:Room1  2:Room2");
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("3:Room3 4:+ 0:RT");

	pressed_key=KPD_Void_GET_Status();

	if(pressed_key=='1')
	{
		AdminRoomStatus(1,Room[0]);
		/*spi*/
	}
	else if(pressed_key=='2')
	{
		AdminRoomStatus(2,Room[1]);
	}
	else if(pressed_key=='3')
	{
		AdminRoomStatus(3,Room[2]);
	}
	else if(pressed_key=='4')
	{
		MoreOptions();
	}
	else if(pressed_key=='0')
	{
		recived_A();
	}
	else
	{
		WrongChoice();
		AdminMode();
	}



}

static void GuestMode()
{
	u8 pressed_key;
		LCD_void_Clear_Screen();
		LCD_void_Write_String("1:Room1 2:Room2");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("3:R3 4:R4 0:RT");
		pressed_key=KPD_Void_GET_Status();

			if(pressed_key=='1')
			{
				GuestRoomStatus(1,Room[0]);
				/*spi*/
			}
			else if(pressed_key=='2')
			{
				GuestRoomStatus(2,Room[1]);
			}
			else if(pressed_key=='3')
			{
				GuestRoomStatus(3,Room[2]);
			}
			else if(pressed_key=='4')
			{
				GuestRoomStatus(4,Room[3]);
			}
			else if(pressed_key=='0')
			{
				recived_A();
			}
			else
			{
				WrongChoice();
				GuestMode();
			}

}

static void MoreOptions()
{
	u8 pressed_key;
	LCD_void_Clear_Screen();
			LCD_void_Write_String("1:Room4  2:TV");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("3:Air_Cond. 0:RT");
			pressed_key=KPD_Void_GET_Status();
			switch(pressed_key)
			{
			case'1':
				AdminRoomStatus(4,Room[3]);
				/*room 4 spi*/
				break;
			case'2':

				/*tv  spi*/
				AdminTVStatus(5,Room[4]);

				break;
			case'3':
				/*ari condtion spi*/

				AdminAirCondStatus();
				break;
			case'0':
				/*return*/
				AdminMode();
				break;

			default:
				 WrongChoice();
				 MoreOptions();
				break;
			}
}




static void AdminRoomStatus(u8 RoomNumber , u8 status)
{
	u8 pressedkey;
	LCD_void_Clear_Screen();
	if(status==0)
	{LCD_void_Write_String("Room   S:OFF");}
	else if(status==1)
	{LCD_void_Write_String("Room   S:ON ");}
	LCD_void_DDRAM_Address(0,4);
	LCD_void_Write_Numbers(RoomNumber);
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("1:ON 2:OFF 0:RT");
	pressedkey=KPD_Void_GET_Status();
	if(pressedkey=='2')
	{
		SPI_U8_Master_TransRecieve(RoomNumber*10,&receivedData);
		Room[RoomNumber-1]=0;
		AdminRoomStatus(RoomNumber,Room[RoomNumber-1]);
	}
	else if(pressedkey=='1')
	{
		SPI_U8_Master_TransRecieve(RoomNumber,&receivedData);
		Room[RoomNumber-1]=1;
		AdminRoomStatus(RoomNumber,Room[RoomNumber-1]);
	}
	else if(pressedkey=='0')
	{
		AdminMode();
	}
	else
	{
		WrongChoice();
		AdminRoomStatus(RoomNumber , Room[RoomNumber-1]);
	}
}
static void AdminAirCondStatus()
{
	u8 pressedkey;
			LCD_void_Clear_Screen();
			if(Air_Cond==0)
			{LCD_void_Write_String("Air_Cond. S:OFF");}
			else if(Air_Cond==1)
			{LCD_void_Write_String("Air_Cond. S:ON ");}
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("1:ON 2:OFF 0:RT");
			pressedkey=KPD_Void_GET_Status();
			if(pressedkey=='2')
			{
				SPI_U8_Master_TransRecieve(60,&receivedData);
				Air_Cond=0;
				AdminAirCondStatus();
			}
			else if(pressedkey=='1')
			{
				SPI_U8_Master_TransRecieve(6,&receivedData);
				Air_Cond=1;
				AdminAirCondStatus();
			}
			else if(pressedkey=='0')
			{
				MoreOptions();
			}
			else
			{
				WrongChoice();
				AdminAirCondStatus();
			}

}

static void AdminTVStatus(u8 RoomNumber , u8 status)
{
	u8 pressedkey;
		LCD_void_Clear_Screen();
		if(status==0)
		{LCD_void_Write_String("TV  S:OFF");}
		else if(status==1)
		{LCD_void_Write_String("TV   S:ON ");}
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("1:ON 2:OFF 0:RT");
		pressedkey=KPD_Void_GET_Status();
		if(pressedkey=='2')
		{
			SPI_U8_Master_TransRecieve(RoomNumber*10,&receivedData);
			Room[RoomNumber-1]=0;
			AdminTVStatus(RoomNumber,Room[RoomNumber-1]);
		}
		else if(pressedkey=='1')
		{
			SPI_U8_Master_TransRecieve(RoomNumber,&receivedData);
			Room[RoomNumber-1]=1;
			AdminTVStatus(RoomNumber,Room[RoomNumber-1]);
		}
		else if(pressedkey=='0')
		{
			MoreOptions();
		}
		else
		{
			WrongChoice();
			AdminTVStatus(RoomNumber , Room[RoomNumber-1]);
		}
}

static void GuestRoomStatus(u8 RoomNumber , u8 status)
{
	u8 pressedkey;
	LCD_void_Clear_Screen();
	if(status==0)
	{LCD_void_Write_String("Room   S:OFF");}
	else if(status==1)
	{LCD_void_Write_String("Room   S:ON ");}
	LCD_void_DDRAM_Address(0,4);
	LCD_void_Write_Numbers(RoomNumber);
	LCD_void_DDRAM_Address(1,0);
	LCD_void_Write_String("1:ON 2:OFF 0:RT");
	pressedkey=KPD_Void_GET_Status();
	if(pressedkey=='2')
	{
		SPI_U8_Master_TransRecieve(RoomNumber*10,&receivedData);
		Room[RoomNumber-1]=0;
		GuestRoomStatus(RoomNumber,Room[RoomNumber-1]);
	}
	else if(pressedkey=='1')
	{
		SPI_U8_Master_TransRecieve(RoomNumber,&receivedData);
		Room[RoomNumber-1]=1;
		GuestRoomStatus(RoomNumber,Room[RoomNumber-1]);
	}
	else if(pressedkey=='0')
	{
		GuestMode();
	}
	else
	{
		WrongChoice();
		GuestRoomStatus(RoomNumber , Room[RoomNumber-1]);
	}
}
