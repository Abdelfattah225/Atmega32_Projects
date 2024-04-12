/**********************************************************************************************
 *  SWC				: LCD
 *
 *  File			: LCD_config.h
 *
 *  Created on		: Sep 24, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/*options :
 * 			1-LCD_U8_8_BIT_MODE
 * 			2-LCD_U8_4_BIT_MODE
 **/
#define LCD_U8_MODE					LCD_U8_8_BIT_MODE

#if LCD_U8_MODE==LCD_U8_8_BIT_MODE

/*Control pins*/
#define LCD_U8_CTRL_PORT			PORTA_ID
#define LCD_U8_RS_PIN				DIO_U8_PIN0
#define LCD_U8_RW_PIN				DIO_U8_PIN1
#define LCD_U8_E_PIN				DIO_U8_PIN2
/*DATA control*/
#define LCD_u8_DATA_PORT			PORTC_ID
#define LCD_u8_DATA_PIN0			DIO_U8_PIN0
#define LCD_u8_DATA_PIN1			DIO_U8_PIN1
#define LCD_u8_DATA_PIN2			DIO_U8_PIN2
#define LCD_u8_DATA_PIN3			DIO_U8_PIN3
#define LCD_u8_DATA_PIN4			DIO_U8_PIN4
#define LCD_u8_DATA_PIN5			DIO_U8_PIN5
#define LCD_u8_DATA_PIN6			DIO_U8_PIN6
#define LCD_u8_DATA_PIN7			DIO_U8_PIN7

#elif LCD_U8_MODE==LCD_U8_4_BIT_MODE

/*Control pins*/
#define LCD_U8_CTRL_PORT			PORTC_ID
#define LCD_U8_RS_PIN				DIO_U8_PIN0
#define LCD_U8_RW_PIN				DIO_U8_PIN1
#define LCD_U8_E_PIN				DIO_U8_PIN2

/*DATA control*/
#define LCD_u8_DATA_PORT			PORTB_ID
#define LCD_u8_DATA_PIN4			DIO_U8_PIN4
#define LCD_u8_DATA_PIN5			DIO_U8_PIN5
#define LCD_u8_DATA_PIN6			DIO_U8_PIN6
#define LCD_u8_DATA_PIN7			DIO_U8_PIN7

#endif


#endif /* HAL_LCD_LCD_CONFIG_H_ */
