/*
 * Servo_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Administrator
 */


#include"BIT_CALC.h"
#include"STD_TYPES.h"
/*MCAL*/
#include"DIO_interface.h"
#include"Servo_interface.h"
#include"Timer1_config.h"
#include"Timer1_private.h"
#include"ADC_interface.h"

f64 Time_OVF ;
u16 TOP ;
u16 Counts ;
f32 Seconds ;

void SERVO_void_Enable(u8 Copy_U8_Angle , u8 Copy_u8_OC_PIN)
{
	Seconds = (2*Copy_U8_Angle)/180 ;
	Counts = (Seconds * 65536)/Time_OVF ;
	if( Copy_u8_OC_PIN == SERVO_OC1A )
	{
		DIO_U8_Set_Pin_Dir(PORTD_ID,DIO_U8_PIN5,PIN_OUTPUT);
		TIMER_U8_OCR1AL = Counts;
	}

	else if (Copy_u8_OC_PIN == SERVO_OC1B)
	{
		DIO_U8_Set_Pin_Dir(PORTD_ID,DIO_U8_PIN4,PIN_OUTPUT);
		TIMER_U8_OCR1BL = Counts;
	}


}
void SERVO_void_Init(void)
{
	Time_OVF = (65536*TIMER1_PRESCALER_VAL)*1000/Freq_System ;
	TOP = (20*65536)/Time_OVF ;
	TIMER1_void_Init();
	TIMER_U8_ICR1L = TOP ;
}
