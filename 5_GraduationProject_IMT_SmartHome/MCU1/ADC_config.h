/**********************************************************************************************
 *  SWC				: keypad
 *
 *  File			:ADC.config.h
 *
 *  Created on		:  OCT 7 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*choose prescaler
 * OPTIONS :
 * 2  	 --> division Factor	2
 * 2  	 --> division Factor	2
 * 4  	 --> division Factor	4
 * 8  	 --> division Factor	8
 * 16 	 --> division Factor	16
 * 32    --> division Factor	32
 * 64 	 --> division Factor	64
 * 128 	 --> division Factor	128
 */
#define PRESCALER	128





#if(PRESCALER==0 || PRESCALER == 2)

#define PRESCALER_U8_ADPS0	1
#define PRESCALER_U8_ADPS1	0
#define PRESCALER_U8_ADPS2	0


#elif(PRESCALER==4)

#define PRESCALER_U8_ADPS0	0
#define PRESCALER_U8_ADPS1	1
#define PRESCALER_U8_ADPS2	0


#elif(PRESCALER==8)

#define PRESCALER_U8_ADPS0	1
#define PRESCALER_U8_ADPS1	1
#define PRESCALER_U8_ADPS2	0


#elif(PRESCALER==16)

#define PRESCALER_U8_ADPS0	0
#define PRESCALER_U8_ADPS1	0
#define PRESCALER_U8_ADPS2	1


#elif(PRESCALER==32)

#define PRESCALER_U8_ADPS0	1
#define PRESCALER_U8_ADPS1	0
#define PRESCALER_U8_ADPS2	1


#elif(PRESCALER==64)

#define PRESCALER_U8_ADPS0	0
#define PRESCALER_U8_ADPS1	1
#define PRESCALER_U8_ADPS2	1



#elif(PRESCALER==128)

#define PRESCALER_U8_ADPS0	1
#define PRESCALER_U8_ADPS1	1
#define PRESCALER_U8_ADPS2	1

#endif





/*Choose ref. voltage
 * option :
 *  0 --> AREF
 * 	1 --> AVCC (5V)
 * 	3 --> 2.56 V INTERNAL
 *
 * */

#define ADMUX_U8_AREF	   0
#define ADMUX_U8_AVCC 	   1
#define ADMUX_U8_INTERNAL  3




#define REF_VOLTAGE	  ADMUX_U8_AVCC

#if(REF_VOLTAGE == ADMUX_U8_AREF )

#define REF_VOLTAGE_REFS0	0
#define REF_VOLTAGE_REFS1	0

#elif (REF_VOLTAGE == ADMUX_U8_AVCC )

#define REF_VOLTAGE_REFS0	1
#define REF_VOLTAGE_REFS1	0


#elif (REF_VOLTAGE == ADMUX_U8_INTERNAL )

#define REF_VOLTAGE_REFS0	1
#define REF_VOLTAGE_REFS1	1


#endif


/*adjustment
 *options:
 * LEFT_ADJUSTMENT
 * RIGHT_ADJUSTMENT
 * */

#define LEFT_ADJUSTMENT		1
#define RIGHT_ADJUSTMENT	0
#define ADMUX_U8_ADLAR   LEFT_ADJUSTMENT

/*Choose channel
 */

#endif /* ADC_CONFIG_H_ */
