/*
 * app.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Administrator
 */

#ifndef APP_H_
#define APP_H_

#define LONG_DELAY   		 4000
#define SHORT_DELAY 		 2000
#define SHORT_SHORT_DELAY    1000

#define WRONG_PASSWORD	    0
#define CORRECT_PASSWORD	1


#define LED_RED_PORT	PORTA_ID
#define LED_RED_PIN		DIO_U8_PIN0
#define LED_GREEN_PORT	PORTA_ID
#define LED_GREEN_PIN	DIO_U8_PIN1
#define BUZZER_PORT		PORTA_ID
#define BUZZER_PIN		DIO_U8_PIN2




void APP_voidInit();

void APP_voidWelcomeScreen();


#endif /* APP_H_ */
