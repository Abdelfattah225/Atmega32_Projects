/*
 * Timer_config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Administrator
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define Freq_System 8000000.000
/*choose prescaler
 *
 * 	No_Clk
	No_Prescaler
	Prescaler_8
	Prescaler_64
	Prescaler_256
	Prescaler_1024
	Eevent_Timer_Falling_Edge
	Eevent_Timer_Rising_Edge
 * */
#define TIMER1_PRESCALER  Prescaler_64
#define TIMER1_PRESCALER_VAL 64
/*choose mode
 * 14- FAST_MODE_WITH_ICR1 */
#define TIMER1_MODE FAST_MODE_WITH_ICR1



#if TIMER1_MODE == FAST_MODE_WITH_ICR1

/* choose output of oc1a and oc2b
 * 1-disconnected
 * 2-
 * 3-Clear_on_compare_match_set_at_TOP
 * 4-Set_on_compare_match_Clear_at_TOP
 * */
#define TIMER1_OUTPUT_OC1A Clear_on_compare_match_set_at_TOP
#define TIMER1_OUTPUT_OC1B Clear_on_compare_match_set_at_TOP















#endif
#endif /* TIMER1_CONFIG_H_ */
