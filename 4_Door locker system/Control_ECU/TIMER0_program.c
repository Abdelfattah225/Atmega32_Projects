/**********************************************************************************************
 *  SWC				:
 *
 *  File			: TIMER0_program.c
 *
 *  Created on		: OCT 14 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

#include"util/delay.h"
#define F_CPU  8000000UL
/*LIB*/
#include"STD_TYPES.h"
#include"BIT_CALC.h"
/*MCAL*/
#include"DIO_interface.h"
/**/
#include"TIMER0_interface.h"
#include"TIMER0_config.h"
#include"TIMER0_private.h"

static u8 TIMER0_U8_Cal_Preload(void);
static u32 ciel_num(f32 num);
static u8 TIMER0_U8_CTC_OCR0_VAL(void);
static u8 TIMER0_U8_FAST_PWM_OCR0_VAL(void);

//f32 Number_ovf  ;
u8 var  = 4;
f64 Number_ovf  ;
 u32 num ;
f64  Time_ovf;
u8 pre = 5 ;// TIMER0_U8_Cal_Preload() ;
/*FUNCTIONS*/



void __vector_11(void)
{
#if TIMER0_MODE == OVF_MODE
	static u16 counter = 0 ;
	static u8 state = 0 ;
if (Number_ovf > 1)
	{
		counter++;
		num =Number_ovf;
		if(counter== num)
		{
			TIMER_U8_TCNT0 = TIMER0_U8_Cal_Preload() ;
			counter=0;
			DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN0,Toggle_Bit(state,0));
		}
	}

	else if( Number_ovf <1)
	{
			TIMER_U8_TCNT0 = TIMER0_U8_Cal_Preload() ;
			DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN0,Toggle_Bit(state,0));
	}
	else if( Number_ovf == 1)
			DIO_U8_Set_Pin_value(PORTA_ID,DIO_U8_PIN0,Toggle_Bit(state,0));
#elif TIMER0_MODE == FAST
DIO_U8_Set_Pin_value(PORTB_ID,DIO_U8_PIN0,PIN_OUTPUT);
#endif

}


void __vector_10(void)
{
	#if TIMER0_MODE == FAST
	DIO_U8_Set_Pin_value(PORTB_ID,DIO_U8_PIN0,PIN_INPUT);
	#endif

//
//static u8 state = 0;
//DIO_U8_Set_Pin_value(PORTB_ID,DIO_U8_PIN0,Toggle_Bit(state,0));

#if TIMER0_MODE == PHASE_SHIFT
	static flag = 0 ;
	if(flag==0)
	{
		DIO_U8_Set_Pin_value(PORTB_ID,DIO_U8_PIN0,PIN_LOW);
		flag=1;
	}
	else if(flag==1)
	{
		DIO_U8_Set_Pin_value(PORTB_ID,DIO_U8_PIN0,PIN_HIGH);
		flag=0;
	}
#endif

}



void TIMER0_void_Init(void)
{
#if TIMER0_MODE == OVF_MODE

	/*waveform generation mode*/
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN3 , Get_Bit(OVF_MODE,0));
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN6 , Get_Bit(OVF_MODE,1));

	/*preload value*/
	TIMER_U8_TCNT0 = TIMER0_U8_Cal_Preload() ;
    //enable interrupt falg for OVF_mode
#if TIMER0_OVERFLOW_INTERRUPT == Enable
	Set_Bit(TIMER_U8_TIMSK0 , 0);
	Set_Bit(TIMER_U8_SREG,7);
#elif TIMER0_OVERFLOW_INTERRUPT == Disable
	Clear_Bit(TIMER_U8_TIMSK0 , 0);
#endif
									/*TCCR0*/
	/*set prescaler*/
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN0 , Get_Bit(TIMER0_PRESCALER,0));
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN1 , Get_Bit(TIMER0_PRESCALER,1));
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN2 , Get_Bit(TIMER0_PRESCALER,2));
	/*Control output of OC0 pin */
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));
	/*force ctc */
	Clear_Bit(TIMER_U8_TCCR0,7);

#elif TIMER0_MODE == CTC_MODE

		/*waveform generation mode*/
		Set_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN3 );
		Clear_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN6);
		/*compare match value*/
		 TIMER_U8_OCR0 = TIMER0_U8_CTC_OCR0_VAL();
	   //enable interrupt falg for CTC_mode
	#if TIMER0_CTC_INTERRUPT == Enable
		Set_Bit(TIMER_U8_TIMSK0 ,1);
		Set_Bit(TIMER_U8_SREG,7);
	#elif TIMER0_CTC_INTERRUPT == Disable
		Clear_Bit(TIMER_U8_TIMSK0 , 1);
	#endif

	/*TCCR0*/
	/*set prescaler*/
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN0 , Get_Bit(TIMER0_PRESCALER,0));
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN1 , Get_Bit(TIMER0_PRESCALER,1));
	Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN2 , Get_Bit(TIMER0_PRESCALER,2));
	/*Control output of OC0 pin in 	CTC mode */
	#if TIMER0_OUTPUT_OF_OC0 == OC0_disconnected
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));
	#else
			DIO_U8_Set_Pin_Dir(PORTB_ID,DIO_U8_PIN3,PIN_OUTPUT);
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));

	#endif

	/*force ctc */
	Clear_Bit(TIMER_U8_TCCR0,7);


#elif TIMER0_MODE == FAST


	/*waveform generation mode*/
	Set_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN3 );
	Set_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN6);

	/*compare match value*/
		#if TIMER0_OUTPUT_OF_OC0 == Clear_OC0_on_compare_match_set_OC0_at_TOP
		TIMER_U8_OCR0 = (TIMER0_DUTY_CYCLE_VAL * TIMER0_TOP_VAL)/100 ;
		#elif TIMER0_OUTPUT_OF_OC0 == Set_OC0_on_compare_match_clear_OC0_at_TOP
		TIMER_U8_OCR0 = (TIMER0_TOP_VAL - ((TIMER0_DUTY_CYCLE_VAL * TIMER0_TOP_VAL )/100))  ;
		#endif

	   //enable or disable interrupt falg for CTC_mode and OVF_mode
	#if TIMER0_CTC_INTERRUPT == Enable && TIMER0_OVERFLOW_INTERRUPT == Enable
		Set_Bit(TIMER_U8_TIMSK0 , 0);
		Set_Bit(TIMER_U8_TIMSK0 , 1);
		Set_Bit(TIMER_U8_SREG,7);
	#elif TIMER0_CTC_INTERRUPT == Disable && TIMER0_OVERFLOW_INTERRUPT == Disable
		Clear_Bit(TIMER_U8_TIMSK0 , 0);
		Clear_Bit(TIMER_U8_TIMSK0 , 1);
	#endif

		/*Presclaer*/
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN0 , Get_Bit(TIMER0_PRESCALER,0));
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN1 , Get_Bit(TIMER0_PRESCALER,1));
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN2 , Get_Bit(TIMER0_PRESCALER,2));

		/*Control output of OC0 pin in 	pwm fast  mode */
	#if TIMER0_OUTPUT_OF_OC0 == OC0_disconnected
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));
	#else
		DIO_U8_Set_Pin_Dir(PORTB_ID,DIO_U8_PIN3,PIN_OUTPUT);
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
		Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));

	#endif
			/*force ctc */
		Clear_Bit(TIMER_U8_TCCR0,7);


#elif TIMER0_MODE == PHASE_SHIFT

		/*waveform generation mode*/
		Clear_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN3 );
		Set_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN6);
		/*compare match value*/
		#if TIMER0_OUTPUT_OF_OC0 == Clear_OC0_when_up_counting_Set_OC0_when_downcounting
		TIMER_U8_OCR0 = (TIMER0_DUTY_CYCLE_VAL * TIMER0_TOP_VAL)/100 ;
		#elif TIMER0_OUTPUT_OF_OC0 == Set_OC0_when_up_counting_Clear_OC0_when_downcounting
		TIMER_U8_OCR0 = (TIMER0_TOP_VAL - ((TIMER0_DUTY_CYCLE_VAL * TIMER0_TOP_VAL )/100))  ;
		#endif

	    //enable or disable interrupt falg for CTC_mode
		#if TIMER0_CTC_INTERRUPT == Enable
			Set_Bit(TIMER_U8_TIMSK0 , 1);
			Set_Bit(TIMER_U8_SREG,7);
		#elif TIMER0_CTC_INTERRUPT == Disable
			Clear_Bit(TIMER_U8_TIMSK0 , 1);
		#endif

			/*Presclaer*/
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN0 , Get_Bit(TIMER0_PRESCALER,0));
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN1 , Get_Bit(TIMER0_PRESCALER,1));
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN2 , Get_Bit(TIMER0_PRESCALER,2));
			/*Control output of OC0 pin in 	pwm phase_correct  mode */
		#if TIMER0_OUTPUT_OF_OC0 == OC0_disconnected
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));
		#else
			DIO_U8_Set_Pin_Dir(PORTB_ID,DIO_U8_PIN3,PIN_OUTPUT);
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN4 , Get_Bit(TIMER0_OUTPUT_OF_OC0,0));
			Assign_Bit(TIMER_U8_TCCR0 , DIO_U8_PIN5 , Get_Bit(TIMER0_OUTPUT_OF_OC0,1));
		#endif
			/*force ctc */
			Clear_Bit(TIMER_U8_TCCR0,7);


#endif
}


#if TIMER0_MODE == OVF_MODE
static u8 TIMER0_U8_Cal_Preload(void)
{
	u8 preload ;

	f64 Copy_f32_float_val ;

	Time_ovf = (256.000 * prescaler_val) /(Freq_system);
	Number_ovf = (Time_desired_in_sec/Time_ovf) ;

	if(Number_ovf > 1)
	{
			if(Number_ovf - (u32)Number_ovf == 0)  // integer
			{
				preload = 0;
			}
			else 									// float
			{
				Copy_f32_float_val = Number_ovf - (u32)Number_ovf ;

				preload = (256 - ((u8)(256 * Copy_f32_float_val))) ;
			}
	}
	else if (Number_ovf < 1)
	{
		//Copy_f32_float_val = Number_ovf  ;
		preload = (256 - ((u8)(256 * Number_ovf))) ;

	}

	else if(Number_ovf == 1)
	{
		preload = 0;
	}

	return preload ;
}
#endif

//
//static u32 ciel_num(f32 num)
//{
//	if(num - (u32)num ==0)
//	{
//		var =  5;
//	}
//	else
//	{
//		num = (((u32)num)+1) ;
//		var = 6 ;
//	}
//	return (u32)num ;
//}


#if TIMER0_MODE == CTC_MODE
static u8 TIMER0_U8_CTC_OCR0_VAL(void)
{

	    u8 Copy_u8_OCR0_val = 0;
		Time_ovf = (256.000 * prescaler_val) /(Freq_system);
		Number_ovf = (Time_desired_in_sec/Time_ovf) ;

		if(Number_ovf<1)
		{
			Copy_u8_OCR0_val = (Number_ovf * 256);
		}
		else
		{
		}

		return Copy_u8_OCR0_val ;

}
#endif


void TIMER0_SET_OCR0(u8 value)
{
	TIMER_U8_OCR0 = value ;
}
