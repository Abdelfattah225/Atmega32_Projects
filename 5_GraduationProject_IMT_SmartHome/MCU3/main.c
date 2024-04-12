/*
 * main.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Administrator
 */


#define F_CPU  8000000UL
#include"util/delay.h"
/*LIB*/
#include"BIT_CALC.h"
#include"STD_Types.h"
/*HAL*/
#include"LCD_interface.h"
/*MCAL*/
#include"DIO_interface.h"
#include"DIO_private.h"
#include"SPI_interface.h"
#include"ADC_interface.h"
#include"EXTI_interface.h"


u8 Desired_Temp=23;


void Air_Cond()
{
	static u8 status = 1 ;
	Toggle_Bit(status,0);
	if(status==0)
	{
		LCD_void_Clear_Screen();
		DIO_U8_Set_Pin_value(PORTD_ID,1,0);
		LCD_void_Write_String("   Air_Cond.   ");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("   Turned OFF   ");
		_delay_ms(1000);
		LCD_void_Clear_Screen();
//		status=1;
	}
	else
	{
		LCD_void_Clear_Screen();
		LCD_void_Write_String("   Air_Cond.   ");
		LCD_void_DDRAM_Address(1,0);
		LCD_void_Write_String("   Turned ON   ");
		DIO_U8_Set_Pin_value(PORTD_ID,1,1);
		_delay_ms(1000);
		LCD_void_Clear_Screen();
//		status=0;
	}
}
void main(void)
{

 u8 local;
 u16 Temp;
	DIO_void_Init();
	LCD_void_Init();
	SPI_Void_Init();
	ADC_void_Init();

	EXTI_void_Set_Level(EXTI_U8_INT0, EXTI_U8_INT0_FALLING_EDGE);
	EXTI_void_Eable(EXTI_U8_INT0);
	EXTI_void_Global_EN_DIS(EXTI_U8_GLOBAL_ENABLE);
	EXTI_void_Set_CallBack(EXTI_U8_INT0,Air_Cond);



while(1)
{
	SPI_U8_Slave_TransRecieve(0xFF,&local);
	switch(local)
	{
	case 1:
			DIO_U8_Set_Pin_value(PORTD_ID,4,1);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Room1 turned ON");
			_delay_ms(1000);
			LCD_void_Clear_Screen();
			break;
	case 2:
			DIO_U8_Set_Pin_value(PORTD_ID,5,1);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Room2 turned ON");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 3:
			DIO_U8_Set_Pin_value(PORTD_ID,6,1);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Room3 turned ON");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 4:
			DIO_U8_Set_Pin_value(PORTD_ID,7,1);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Room4 turned ON");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 5:
			DIO_U8_Set_Pin_value(PORTD_ID,0,1);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("TV turned ON");
			_delay_ms(1000);
			LCD_void_Clear_Screen();
			break;
	case 6:

			Temp = ADC_U16_Read(3)/4;
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Check Temp.");
			_delay_ms(500);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Check Temp..");
			_delay_ms(500);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Check Temp...");
			_delay_ms(500);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("Desired Temp=");
			LCD_void_Write_Numbers(Desired_Temp);
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("Room Temp=");
			LCD_void_Write_Numbers(Temp);
			_delay_ms(1000);
			if(Temp>Desired_Temp)
			{
				LCD_void_Clear_Screen();
				LCD_void_Write_String("   Air_Cond.   ");
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("   Turned ON   ");
				DIO_U8_Set_Pin_value(PORTD_ID,1,1);
				_delay_ms(1000);
				LCD_void_Clear_Screen();
			}
			else
			{
				LCD_void_Clear_Screen();
				LCD_void_Write_String("Room Temp<=");
				LCD_void_Write_Numbers(Desired_Temp);
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("Conditiong OFF");
				_delay_ms(1000);
				LCD_void_Clear_Screen();

			}
			break;

	case 10:
			DIO_U8_Set_Pin_value(PORTD_ID,4,0);
			LCD_void_Clear_Screen();
			LCD_void_Write_String("    Room1       ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("   turned OFF   ");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 20:
			DIO_U8_Set_Pin_value(PORTD_ID,5,0);
			LCD_void_Write_String("    Room2       ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("   turned OFF   ");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 30:
			DIO_U8_Set_Pin_value(PORTD_ID,6,0);
			LCD_void_Write_String("    Room3       ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("   turned OFF   ");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 40:
			DIO_U8_Set_Pin_value(PORTD_ID,7,0);
			LCD_void_Write_String("    Room4       ");
			LCD_void_DDRAM_Address(1,0);
			LCD_void_Write_String("   turned OFF   ");
			_delay_ms(1000);
			LCD_void_Clear_Screen();

			break;
	case 50:
			DIO_U8_Set_Pin_value(PORTD_ID,0,0);
			LCD_void_Write_String("TV turned OFF   ");
			_delay_ms(1000);
			LCD_void_Clear_Screen();
			break;
	case 60:
				LCD_void_Clear_Screen();
				DIO_U8_Set_Pin_value(PORTD_ID,1,0);
				LCD_void_Write_String("   Air_Cond.   ");
				LCD_void_DDRAM_Address(1,0);
				LCD_void_Write_String("   Turned OFF   ");
				_delay_ms(1000);
				LCD_void_Clear_Screen();
				break;

	}

}
}
