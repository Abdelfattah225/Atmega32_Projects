/*
 * SPI_program.c
 *
 *  Created on: Sep 17, 2019
 *      Author: Z.50
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "SPI_private.h"
#include "SPI_interface.h"
#include"SPI_Config.h"
#include"DIO_interface.h"






void SPI_Void_Init()
{
#if SPI_u8_Mode==SPI_u8_Master_Mode
	/*SPCR*/

	DIO_U8_Set_Pin_Dir(PORTB_ID,4,1); // SS
	DIO_U8_Set_Pin_Dir(PORTB_ID,5,1); // MOSI
	DIO_U8_Set_Pin_Dir(PORTB_ID,6,0); // MISO
	DIO_U8_Set_Pin_Dir(PORTB_ID,7,1); // SCK

	/*SET PIN SS TO HIGH*/
	DIO_U8_Set_Pin_value(PORTB_ID,4,1);

	/*data order = MSB*/
	Clear_Bit(SPI_U8_SPCR,5);
	/*master-->1/slave-->0*/
	Set_Bit(SPI_U8_SPCR,4);
	/*Clock Polarity CPOL And Clock phase CPHA ==> falling , rising / setup , sample*/
	Set_Bit(SPI_U8_SPCR,3);
	Set_Bit(SPI_U8_SPCR,2);
	/*choose any clock*/
	Set_Bit(SPI_U8_SPCR,1);
	Clear_Bit(SPI_U8_SPCR,0);
	Clear_Bit(SPI_U8_SPSR,0);

#elif SPI_u8_Mode==SPI_u8_Slave_Mode

	DIO_U8_Set_Pin_Dir(PORTB_ID,4,0); // SS
	DIO_U8_Set_Pin_Dir(PORTB_ID,5,0); // MOSI
	DIO_U8_Set_Pin_Dir(PORTB_ID,6,1); // MISO
	DIO_U8_Set_Pin_Dir(PORTB_ID,7,0); // SCK

	/*data order = MSB*/
	Clear_Bit(SPI_U8_SPCR,5);
	/*master-->1/slave-->0*/
	Clear_Bit(SPI_U8_SPCR,4);
	/*Clock Polarity CPOL And Clock phase CPHA ==> falling , rising / setup , sample*/
	Set_Bit(SPI_U8_SPCR,3);
	Set_Bit(SPI_U8_SPCR,2);
	/*choose any clock*/
	Set_Bit(SPI_U8_SPCR,1);
	Clear_Bit(SPI_U8_SPCR,0);
	Clear_Bit(SPI_U8_SPSR,0);

#else
#error"error in SPI_Config to select SPI_mode"

#endif

	/*Enable SPI*/
		Set_Bit(SPI_U8_SPCR,6);
}


u8 SPI_U8_Master_TransRecieve(u8 copy_U8TranmitedByte , u8 * copy_pu8RecievedByte)
{
	/*SET PIN SS TO LOW*/
	DIO_U8_Set_Pin_value(PORTB_ID,4,0);
	u8 LocalErrorState=0;
	if(copy_pu8RecievedByte!=Null)
	{
		/*send byte*/
		SPI_U8_SPDR=copy_U8TranmitedByte;
		/*check if the transmission is completed*/
		while(Get_Bit(SPI_U8_SPSR,7)==0);
		/*Read byte*/
		*copy_pu8RecievedByte=SPI_U8_SPDR;
		LocalErrorState=1;
	}
	DIO_U8_Set_Pin_value(PORTB_ID,4,1);
	return LocalErrorState;
}

void SPI_Void_SlaveSendByte(u8 copy_U8TranmitedByte)
{
	u8 flush;
	/*Notify master by dio pin*/
	DIO_U8_Set_Pin_Dir(PORTA_ID,7,1);
	DIO_U8_Set_Pin_value(PORTA_ID,7,1);
	/*send byte*/
	SPI_U8_SPDR=copy_U8TranmitedByte;
	/*check if the transmission is completed*/
	while(Get_Bit(SPI_U8_SPSR,7)==0);
	flush = SPI_U8_SPDR;


}

u8 SPI_U8_Slave_TransRecieve(u8 data , u8 * copy_pu8RecievedByte)
{
	SPI_U8_SPDR=data;
	u8 LocalErrorState=0;
	if(copy_pu8RecievedByte!=Null)
	{
		while(Get_Bit(SPI_U8_SPSR,7)==0);
		/*Read byte*/
		* copy_pu8RecievedByte=SPI_U8_SPDR;
		LocalErrorState=1;
	}
	return LocalErrorState;
}










