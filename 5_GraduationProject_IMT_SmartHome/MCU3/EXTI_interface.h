/**********************************************************************************************
 *  SWC				:
 *
 *  File			:EXTI_interface.h
 *
 *  Created on		: OCT 6 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_U8_INT0	 0
#define EXTI_U8_INT1	 1
#define EXTI_U8_INT2	 2
/*CONTROL INT0*/
#define EXTI_U8_INT0_LOW_LEVEL			    0b00
#define EXTI_U8_INT0_LOGICAL_CHANGE   		0b01
#define EXTI_U8_INT0_FALLING_EDGE	 		0b10
#define EXTI_U8_INT0_RASING_EDGE		    0b11
//#define MCUCR_U8_PIN0

/*CONTROL INT1*/
#define EXTI_U8_INT1_LOW_LEVEL			    0b00
#define EXTI_U8_INT1_LOGICAL_CHANGE   		0b01
#define EXTI_U8_INT1_FALLING_EDGE	 		0b10
#define EXTI_U8_INT1_RASING_EDGE		    0b11
/*CONTROL INT2*/
#define EXTI_U8_INT2_FALLING_EDGE	 		 0
#define EXTI_U8_INT2_RASING_EDGE		     1

#define EXTI_U8_GLOBAL_ENABLE		1
#define EXTI_U8_GLOBAL_DISENABLE	0
/******************************************< Global Functinos >************************************/
/*******************************************************************************************/

void EXTI_void_Eable(u8 Copy_U8_INT_Index);

void EXTI_void_Disable(u8 Copy_U8_INT_Index);

void EXTI_void_Set_Level(u8 Copy_U8_INT_Index , u8 Copy_U8_Level_Index);

void EXTI_void_Set_CallBack(u8 Copy_U8_INT_Index , void (*pvoidCallBack)(void));

void EXTI_void_Global_EN_DIS(u8 Copy_U8_Assign_Value);


#endif /* EXTI_INTERFACE_H_ */
