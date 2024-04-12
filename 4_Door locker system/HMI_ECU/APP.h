/*
 * APP.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Administrator
 */

#ifndef APP_H_
#define APP_H_


#define LONG_DELAY   		 4000
#define SHORT_DELAY 		 2000
#define SHORT_SHORT_DELAY    1000

#define WRONG_PASSWORD	    0
#define CORRECT_PASSWORD	1

#define BUZZER_PORT  PORTC_ID
#define BUZZER_PIN   7
void APP_voidInit();
void APP_voidWelcomeScreen();

#endif /* APP_H_ */
