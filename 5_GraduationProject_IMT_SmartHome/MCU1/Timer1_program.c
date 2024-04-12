/*
 * Timer_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Administrator
 */

#include"BIT_CALC.h"
#include"STD_TYPES.h"
/*MCAL*/
#include"DIO_interface.h"
#include"Timer1_interface.h"
#include"Timer1_config.h"
#include"Timer1_private.h"






void TIMER1_void_Init(void)
{
#if TIMER1_MODE == FAST_MODE_WITH_ICR1
	/*waveform generatoin mode*/
	Assign_Bit(TIMER_U8_TCCR1A,DIO_U8_PIN0,Get_Bit(FAST_MODE_WITH_ICR1,0));
	Assign_Bit(TIMER_U8_TCCR1A,DIO_U8_PIN1,Get_Bit(FAST_MODE_WITH_ICR1,1));
	Assign_Bit(TIMER_U8_TCCR1B,DIO_U8_PIN3,Get_Bit(FAST_MODE_WITH_ICR1,2));
	Assign_Bit(TIMER_U8_TCCR1B,DIO_U8_PIN4,Get_Bit(FAST_MODE_WITH_ICR1,3));
	/*forec compare match*/
	Clear_Bit(TIMER_U8_TCCR1A,2);
	Clear_Bit(TIMER_U8_TCCR1A,3);
	/*output of oc1a and oc1b*/
	Assign_Bit(TIMER_U8_TCCR1A,DIO_U8_PIN4,Get_Bit(TIMER1_OUTPUT_OC1B,0));
	Assign_Bit(TIMER_U8_TCCR1A,DIO_U8_PIN5,Get_Bit(TIMER1_OUTPUT_OC1B,1));
	Assign_Bit(TIMER_U8_TCCR1A,DIO_U8_PIN6,Get_Bit(TIMER1_OUTPUT_OC1A,0));
	Assign_Bit(TIMER_U8_TCCR1A,DIO_U8_PIN7,Get_Bit(TIMER1_OUTPUT_OC1A,1));
	/*set prescaler*/
	Assign_Bit(TIMER_U8_TCCR1B,DIO_U8_PIN0,Get_Bit(TIMER1_PRESCALER,0));
	Assign_Bit(TIMER_U8_TCCR1B,DIO_U8_PIN1,Get_Bit(TIMER1_PRESCALER,1));
	Assign_Bit(TIMER_U8_TCCR1B,DIO_U8_PIN2,Get_Bit(TIMER1_PRESCALER,2));

	TIMER_U8_ICR1L=2500;
	TIMER_U8_OCR1AL=125;




#endif
}
