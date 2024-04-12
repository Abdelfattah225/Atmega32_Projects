/**********************************************************************************************
 *  SWC				: keypad
 *
 *  File			:ADC.private.h
 *
 *  Created on		:  OCT 7 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/



#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_U8_ADMUX	 *((volatile u8*)0x27)
#define ADC_U8_ADCSRA	 *((volatile u8*)0x26)
#define ADC_U8_ADCH	 	 *((volatile u8*)0x25)
#define ADC_U8_ADCL	 	 *((volatile u8*)0x24)
#define ADC_U8_SFIOR	 *((volatile u8*)0x50)
#endif /* ADC_PRIVATE_H_ */
