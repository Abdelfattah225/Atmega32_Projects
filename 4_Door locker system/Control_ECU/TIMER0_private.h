/**********************************************************************************************
 *  SWC				: LCD
 *
 *  File			: TIMER0_private.h
 *
 *  Created on		: OCT 14 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));


#define TIMER_U8_TCCR0    *((volatile u8*)0x53)
#define TIMER_U8_TCNT0    *((volatile u8*)0x52)  // COUNTER
#define TIMER_U8_TIMSK0   *((volatile u8*)0x59)
#define TIMER_U8_SREG 	  *((volatile u8*)0x5F)
#define TIMER_U8_TIFR0    *((volatile u8*)0x58)
#define TIMER_U8_OCR0     *((volatile u8*)0x5C)


#define No_Clk 						  0b000				//-->(meaning disable timer)
#define No_Prescaler			   	  0b001				//	-->(meaning clk but no prescaler)
#define Prescaler_8                   0b010
#define Prescaler_64                  0b011
#define Prescaler_256                 0b100
#define Prescaler_1024                0b101
#define Eevent_Timer_Falling_Edge     0b110
#define Eevent_Timer_Rising_Edge      0b111

/*
 * * 1- OVF_MODE
 * 2- PHASE_SHIFT
 * 3- CTC MODE
 * 4- FAST
 * */
#define  OVF_MODE            0b00
#define  PHASE_SHIFT         0b01
#define  CTC_MODE            0b10
#define  FAST                0b11

/*Enable / disable OVF_mode interrupt
 * 1- Enable
 * 2- Disable
 *  */
#define Enable	1
#define Disable	0



/*choose output of OC0 in CTC MODE
 * 1-OC0_disconnected
 * 2-Toggle_OC0_CTC
 * 3-Clear_OC0_CTC
 * 4-Set_OC0_CTC
 **/
#define OC0_disconnected  0b00
#define Toggle_OC0_CTC    0b01
#define Clear_OC0_CTC	  0b10
#define Set_OC0_CTC		  0b11

/*choose output of OC0 in pwm fast MODE
	 * 1-OC0_disconnected
	 * 2- reserved
	 * 3-Clear_OC0_on_compare_match_set_OC0_at_TOP
	 * 4-Set_OC0_on_compare_match_clear_OC0_at_TOP
	 **/
#define OC0_disconnected 							 0b00
#define  reserved                                    0b01
#define Clear_OC0_on_compare_match_set_OC0_at_TOP    0b10
#define Set_OC0_on_compare_match_clear_OC0_at_TOP    0b11

/*choose output of OC0 in pwm phase_correct MODE
	 * 1- OC0_disconnected
	 * 2- reserved
	 * 3- Clear_OC0_when_up_counting_Set_OC0_when_downcounting
     * 4- Set_OC0_when_up_counting_Clear_OC0_when_downcounting
     * */
#define OC0_disconnected 								     	0b00
#define  reserved                                			    0b01
#define Clear_OC0_when_up_counting_Set_OC0_when_downcounting    0b10
#define Set_OC0_when_up_counting_Clear_OC0_when_downcounting    0b11






#endif /* TIMER0_PRIVATE_H_ */
