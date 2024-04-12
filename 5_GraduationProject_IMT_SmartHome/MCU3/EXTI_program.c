/**********************************************************************************************
 *  SWC				:
 *
 *  File			: EXTI_program.c
 *
 *  Created on		: OCT 6 , 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/

/******************************************< inclusion >************************************/
/*******************************************************************************************/


#include"util/delay.h"
#define F_CPU  8000000UL
/*LIB*/
#include"STD_TYPES.h"
#include"BIT_CALC.h"
/*MCAL*/
#include"DIO_interface.h"

#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_private.h"

void (*Avoid_CallBack[3])(void);


void __vector_1(void)
{
	Avoid_CallBack[0]();
}

void __vector_2(void)
{
	Avoid_CallBack[1]();
}

void __vector_3(void)
{
	Avoid_CallBack[2]();
}
/******************************************< Functinos >************************************/
/*******************************************************************************************/

void EXTI_void_Eable(u8 Copy_U8_INT_Index)
{
	switch(Copy_U8_INT_Index)
	{
	case EXTI_U8_INT0:
		Set_Bit(EXTI_U8_GICR,DIO_U8_PIN6);
		break;
	case EXTI_U8_INT1:
			Set_Bit(EXTI_U8_GICR,DIO_U8_PIN7);
			break;
	case EXTI_U8_INT2:
			Set_Bit(EXTI_U8_GICR,DIO_U8_PIN5);
			break;


	}
}


void EXTI_void_Disable(u8 Copy_U8_INT_Index)
{
	switch(Copy_U8_INT_Index)
	{
	case EXTI_U8_INT0:
		Clear_Bit(EXTI_U8_GICR,DIO_U8_PIN6);
		break;
	case EXTI_U8_INT1:
		Clear_Bit(EXTI_U8_GICR,DIO_U8_PIN7);
		break;
	case EXTI_U8_INT2:
		Clear_Bit(EXTI_U8_GICR,DIO_U8_PIN5);
		break;
	}
}

void EXTI_void_Set_Level(u8 Copy_U8_INT_Index , u8 Copy_U8_Level_Index)
{
	switch(Copy_U8_INT_Index)
	{
		case EXTI_U8_INT0:
			Assign_Bit(EXTI_U8_MCUCR, DIO_U8_PIN0 , Get_Bit(Copy_U8_Level_Index,0));
			Assign_Bit(EXTI_U8_MCUCR, DIO_U8_PIN1 , Get_Bit(Copy_U8_Level_Index,1));
			break;
		case EXTI_U8_INT1:
			Assign_Bit(EXTI_U8_MCUCR, DIO_U8_PIN2 , Get_Bit(Copy_U8_Level_Index,0));
			Assign_Bit(EXTI_U8_MCUCR, DIO_U8_PIN3 , Get_Bit(Copy_U8_Level_Index,1));
			break;
		case EXTI_U8_INT2:
			Assign_Bit(EXTI_U8_MCUCSR, DIO_U8_PIN6 , Copy_U8_Level_Index );

			break;
		}
}
void EXTI_void_Global_EN_DIS(u8 Copy_U8_Assign_Value)
{
	Assign_Bit(EXTI_U8_SREG, DIO_U8_PIN7 , Copy_U8_Assign_Value);
}

void EXTI_void_Set_CallBack(u8 Copy_U8_INT_Index , void (*pvoidCallBack)(void))
{
	Avoid_CallBack[Copy_U8_INT_Index]= pvoidCallBack ;
}


