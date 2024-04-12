/**********************************************************************************************
 *  SWC				: keypad
 *
 *  File			: KWYPAD_config.h
 *
 *  Created on		: Sep 28, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/



#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
/*ROWS*/
#define KPD_U8_ROWS_PORT		PORTC_ID
#define KPD_U8_ROW0_PIN			DIO_U8_PIN0
#define KPD_U8_ROW1_PIN			DIO_U8_PIN1
#define KPD_U8_ROW2_PIN			DIO_U8_PIN2
#define KPD_U8_ROW3_PIN			DIO_U8_PIN3


/*COLUMNS*/
#define KPD_U8_COLS_PORT		PORTC_ID
#define KPD_U8_COL0_PIN			DIO_U8_PIN4
#define KPD_U8_COL1_PIN			DIO_U8_PIN5
#define KPD_U8_COL2_PIN			DIO_U8_PIN6
#define KPD_U8_COL3_PIN			DIO_U8_PIN7


#define KPD_KEYS	{ {'7','8','9','/'}, \
					  {'4','5','6','*'}, \
					  {'1','2','3','-'}, \
					  {'%','0','=','+',}}

#endif /* KEYPAD_CONFIG_H_ */
