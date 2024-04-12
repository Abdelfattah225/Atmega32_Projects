/**********************************************************************************************
 *  SWC				: keypad
 *
 *  File			:ADC_interface.h
 *
 *  Created on		:  OCT 7 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*Choose channel*/
#define ADC_U8_ADC0 0
#define ADC_U8_ADC1 1
#define ADC_U8_ADC2 2
#define ADC_U8_ADC3 3
#define ADC_U8_ADC4 4
#define ADC_U8_ADC5 5
#define ADC_U8_ADC6 6
#define ADC_U8_ADC7 7


u16 ADC_U16_Read(u8 channel);
void ADC_void_Init(void);


#endif /* ADC_INTERFACE_H_ */
