/**********************************************************************************************
 *  SWC				: keypad
 *
 *  File			:ADC.program.c
 *
 *  Created on		:  OCT 7 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/
#include<avr/io.h>
#include"util/delay.h"
#define F_CPU  8000000UL
/*LIB*/
#include"STD_TYPES.h"
#include"BIT_CALC.h"
/*MCAL*/
#include"DIO_interface.h"

#include"ADC_interface.h"
#include"ADC_config.h"
#include"ADC_private.h"

void ADC_void_Init(void)
{
	// ADC enable
	Set_Bit(ADC_U8_ADCSRA,DIO_U8_PIN7);
	// PRESCALER = 128
	Assign_Bit(ADC_U8_ADCSRA,DIO_U8_PIN0 ,PRESCALER_U8_ADPS0);
	Assign_Bit(ADC_U8_ADCSRA,DIO_U8_PIN1 ,PRESCALER_U8_ADPS1);
	Assign_Bit(ADC_U8_ADCSRA,DIO_U8_PIN2 ,PRESCALER_U8_ADPS2);
    //REF. VOLATAGE -->5v
	Assign_Bit(ADC_U8_ADMUX,DIO_U8_PIN6,REF_VOLTAGE_REFS0);
	Assign_Bit(ADC_U8_ADMUX,DIO_U8_PIN7,REF_VOLTAGE_REFS1);
	// LEFT ADUSTMENT
	Assign_Bit(ADC_U8_ADMUX,DIO_U8_PIN5 ,ADMUX_U8_ADLAR);

}

u16 ADC_U16_Read(u8 channel)
{
	// choose channel
	ADC_U8_ADMUX &=0b11100000;
	ADC_U8_ADMUX |=channel;
	// Start conversion
	Set_Bit(ADC_U8_ADCSRA, DIO_U8_PIN6);
	while(Get_Bit(ADC_U8_ADCSRA,DIO_U8_PIN4)!=1);
	Set_Bit(ADC_U8_ADCSRA,DIO_U8_PIN4);

	u16 result = (ADC_U8_ADCL>>6);
	result|=((u16)(ADC_U8_ADCH<<2));
	return result;
}
