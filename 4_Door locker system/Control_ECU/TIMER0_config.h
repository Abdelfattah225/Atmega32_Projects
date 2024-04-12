/**********************************************************************************************
 *  SWC				: LCD
 *
 *  File			: TIMER0_config.h
 *
 *  Created on		: OCT 14 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include"TIMER0_private.h"

/*system ferquency*/
#define Freq_system 8000000.000

/*choose prescaler*/
/* options :
 * 0- No_Clk 											-->(meaning disable timer)
 * 1- No_Prescaler										-->(meaning clk but no prescaler)
 * 2- Prescaler_8
 * 3- Prescaler_64
 * 4- Prescaler_256
 * 5- Prescaler_1024
 * 6- Eevent_Timer_Falling_Edge
 * 7- Eevent_Timer_Rising_Edge
 */

#define  TIMER0_PRESCALER 	Prescaler_8
#define  prescaler_val		8


/* Choose mode
 * options :
 *
 * 1- OVF_MODE
 * 2- PHASE_SHIFT
 * 3- CTC_MODE
 * 4- FAST
 * */
#define TIMER0_MODE	 PHASE_SHIFT






/*Control output of OC0 pin */
#if TIMER0_MODE == OVF_MODE
	#define TIMER0_OUTPUT_OF_OC0  0b00
	/*Freq_system*/
	#define Time_desired_in_sec  1.0
	/*Enable / disable OVF_mode interrupt
	 * 1- Enable
	 * 2- Disable
	 *  */
	#define TIMER0_OVERFLOW_INTERRUPT	Enable


#elif TIMER0_MODE == CTC_MODE


/*desired time*/
	#define Time_desired_in_sec  0.0001      // 100us

	/*choose output of OC0 in CTC MODE
	 * 1-OC0_disconnected
	 * 2-Toggle_OC0_CTC
	 * 3-Clear_OC0_CTC
	 * 4-Set_OC0_CTC
	 **/
	#define TIMER0_OUTPUT_OF_OC0 Set_OC0_CTC

	/*Enable / disable CTC_mode interrupt
	 * 1- Enable
	 * 2- Disable
	 *  */
	#define TIMER0_CTC_INTERRUPT	Enable




#elif TIMER0_MODE == FAST
/*Parameter (non inverting):
 * ON_Time = OCR0 * T tick ,
 * OFF_Time = Peroid_Time- ON_Time,
 * Peroid_Time = ON_Time + OFF_Time  =  TOP * T tick  ,
 * Period_Frequency = 1/ Peroid_Time  ,
 * Duty_Cycle = ON_Time / Peroid_Time  = OCR0/TOP ,
 * Effective_Voltage = A root(D)
 */
/************************************************************************************/

	// --> (2^resolution) -1
	#define TIMER0_TOP_VAL  255
	/*set Duty cycle in range --> (0:100)  */
	#define TIMER0_DUTY_CYCLE_VAL		50
	/*choose output of OC0 in pwm fast MODE
	 * 1-OC0_disconnected
	 * 2- reserved
	 * 3-Clear_OC0_on_compare_match_set_OC0_at_TOP     ---> non_inverting pwm(OCR0 increase , duty cycle increase , on-time increase)
	 * 4-Set_OC0_on_compare_match_clear_OC0_at_TOP     ---> inverting pwm(OCR0 increase , duty cycle decrease , on-time decrease	 */
	#define TIMER0_OUTPUT_OF_OC0   Clear_OC0_on_compare_match_set_OC0_at_TOP

	/*Enable / disable CTC_mode interrupt
	 * 1- Enable
	 * 2- Disable
	 *  */
	#define TIMER0_CTC_INTERRUPT	Enable
	/*Enable / disable OVF_mode interrupt
	 * 1- Enable
	 * 2- Disable
	 *  */
	#define TIMER0_OVERFLOW_INTERRUPT	Enable





#elif TIMER0_MODE == PHASE_SHIFT

	#define TIMER0_TOP_VAL 255
	#define TIMER0_DUTY_CYCLE_VAL  50

	/*Enable / disable CTC_mode interrupt
	 * 1- Enable
	 * 2- Disable
	 *  */
	#define TIMER0_CTC_INTERRUPT	Enable

/*choose output of OC0 in pwm phase_correct MODE
	 * 1- OC0_disconnected
	 * 2- reserved
	 * 3- Clear_OC0_when_up_counting_Set_OC0_when_downcounting     //--> non_inverting
     * 4- Set_OC0_when_up_counting_Clear_OC0_when_downcounting     //--> inverting
     * */
	#define TIMER0_OUTPUT_OF_OC0   Clear_OC0_when_up_counting_Set_OC0_when_downcounting

#endif
#endif /* TIMER0_CONFIG_H_ */
