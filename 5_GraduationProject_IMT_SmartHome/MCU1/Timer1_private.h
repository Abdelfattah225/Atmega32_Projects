/*
 * Timer_program.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Administrator
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TIMER_U8_TCCR1A    *((volatile u8*)0x4F)
#define TIMER_U8_TCCR1B    *((volatile u8*)0x4E)
//#define TIMER_U8_OCR1AH    *((volatile u8*)0x4B)
#define TIMER_U8_OCR1AL    *((volatile u16*)0x4A)
//#define TIMER_U8_OCR1BH    *((volatile u8*)0x49)
#define TIMER_U8_OCR1BL    *((volatile u16*)0x48)
//#define TIMER_U8_ICR1H     *((volatile u8*)0x47)
#define TIMER_U8_ICR1L     *((volatile u16*)0x46)



#define FAST_MODE_WITH_ICR1 14
/* choose output of oc1a and oc2b
 * 1-disconnected
 * 2-
 * 3-Clear_on_compare_match_set_at_TOP
 * 4-Set_on_compare_match_Clear_at_TOP
 * */
#define disconnected  					  0
#define Clear_on_compare_match_set_at_TOP 2
#define Set_on_compare_match_Clear_at_TOP 3


/*PRESCALER*/
#define No_Clk 						  0b000				//-->(meaning disable timer)
#define No_Prescaler			   	  0b001				//	-->(meaning clk but no prescaler)
#define Prescaler_8                   0b010
#define Prescaler_64                  0b011
#define Prescaler_256                 0b100
#define Prescaler_1024                0b101
#define Eevent_Timer_Falling_Edge     0b110
#define Eevent_Timer_Rising_Edge      0b111

#endif /* TIMER1_PRIVATE_H_ */
