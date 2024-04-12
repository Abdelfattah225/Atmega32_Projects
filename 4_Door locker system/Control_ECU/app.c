/*
 * app.c
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

///*MCAL*/
#include"DIO_interface.h"
#include"UART_interface.h"
/**/
#include"app.h"

u8 password[]="1234";
u8 checkPass[5];


static void APP_CheckPass();


void APP_voidInit()
{
	DIO_void_Init();
	UART_void_Init();
}

void APP_voidStart_Work()
{
	APP_CheckPass();
}


static void APP_CheckPass()
{
	u8 state = CORRECT_PASSWORD ;
	UART_void_Receive_String(checkPass);

	 /*check password*/
	 for(u8 j = 0 ; j<4 ; j++)
	 {
		 if(checkPass[j]!=password[j])
		 {
			state = WRONG_PASSWORD ;
			break;
		 }
	 }
	 UART_void_Send_Char(state);
}








