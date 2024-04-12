/**********************************************************************************************
 *  SWC				: keypad
 *
 *  File			: KWYPAD_program.c
 *
 *  Created on		: Sep 28, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

/****************************************< INCLUDES >**********************************/
/**************************************************************************************/
#include<avr/delay.h>
#define F_CPU  8000000UL

/*LIB*/
#include"STD_TYPES.h"
#include"BIT_CALC.h"
/*HAL*/
#include"LCD_interface.h"
#include"KEYPAD_interface.h"
#include"KEYPAD_config.h"
#include"KEYPAD_private.h"
/*MCAL*/
#include"DIO_interface.h"





static u8 KPD_AU8_ROWS_PINS [KPD_ROWS]= { KPD_U8_ROW0_PIN , KPD_U8_ROW1_PIN , KPD_U8_ROW2_PIN , KPD_U8_ROW3_PIN } ;
static u8 KPD_AU8_COLS_PINS [KPD_COLS]= { KPD_U8_COL0_PIN , KPD_U8_COL1_PIN , KPD_U8_COL2_PIN , KPD_U8_COL3_PIN } ;


/****************************************< GLOABAL FUNCTION DEFINTION >****************************/
/**************************************************************************************/


void KPD_Init()
{
	u8 COL_Index , ROW_Index ;

	for( COL_Index = 0 ; COL_Index < KPD_COLS ; COL_Index ++ )
	{
		DIO_U8_Set_Pin_Dir( KPD_U8_COLS_PORT  , KPD_AU8_COLS_PINS[COL_Index] , PIN_OUTPUT  ) ;
	}

	for ( ROW_Index = 0 ; ROW_Index < KPD_ROWS ; ROW_Index ++ )
	{
		DIO_U8_Set_Pin_Dir( KPD_U8_ROWS_PORT  , KPD_AU8_ROWS_PINS[ROW_Index] , PIN_INPUT ) ;
		DIO_U8_Set_Pin_value( KPD_U8_ROWS_PORT  , KPD_AU8_ROWS_PINS[ROW_Index] , PIN_HIGH ) ;
	}
}




u8 KPD_Void_GET_Status ( void )
{
	u8 COL_Index , ROW_Index ;
	u8  KPD_Status , Presskey = KPD_Key_NotPressed ;
	static u8 KPD_ARR [KPD_ROWS][KPD_COLS] = KPD_KEYS ;
while(1)
{
	for( COL_Index = 0 ; COL_Index < KPD_COLS ; COL_Index ++ )
	{
		DIO_U8_Set_Pin_value( KPD_U8_COLS_PORT , KPD_AU8_COLS_PINS[COL_Index] , PIN_LOW  ) ;

		for ( ROW_Index = 0 ; ROW_Index < KPD_ROWS ; ROW_Index ++ )
		{
			// Key_Num = COL_Index + ( ROW_Index * KPD_ROWS ) ;
			DIO_U8_Get_pin_value ( KPD_U8_ROWS_PORT , KPD_AU8_ROWS_PINS[ROW_Index] , &KPD_Status ) ;

			if ( KPD_Status == KPD_Key_Pressed )
			{
				Presskey = KPD_ARR[ROW_Index][COL_Index] ;

			while (KPD_Status == KPD_Key_Pressed)
			{
				DIO_U8_Get_pin_value( KPD_U8_ROWS_PORT , KPD_AU8_ROWS_PINS[ROW_Index] , &KPD_Status ) ;
			}
			return Presskey ;
			}

		}

		DIO_U8_Set_Pin_value( KPD_U8_COLS_PORT , KPD_AU8_COLS_PINS[COL_Index] , PIN_HIGH ) ;
	}
}
}

