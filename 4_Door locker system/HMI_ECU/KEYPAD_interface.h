/******************** **************************************************************************
 *  SWC				: keypad
 *
 *  File			: KWYPAD_interface.h
 *
 *  Created on		: Sep 28, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


#define KPD_ROWS     4
#define KPD_COLS     4

#define KPD_Key_Pressed       0
#define KPD_Key_NotPressed    1




void KPD_Init();

u8 KPD_Void_GET_Status();

#endif /* KEYPAD_INTERFACE_H_ */
