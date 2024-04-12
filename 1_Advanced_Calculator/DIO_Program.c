/*****************************************************************************/

/* File Defination :
 *
 * File 		: DIO_program.c
 *
 * Created on	: Sep 15, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/
/***********************************inclusion**********************************/
/********************************************************************************/
#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_config.h"
#include"DIO_private.h"
#include"DIO_interface.h"

/*****************************************************************************/
/***********************************fucntion**********************************/
/********************************************************************************/

u8 INTIAL_DIR(u8 p0 , u8 p1 , u8 p2 , u8 p3 , u8 p4 , u8 p5 , u8 p6 , u8 p7)
{
	u8 port = 0x00 ;
	Assign_Bit(port,DIO_U8_PIN0,p0);
	Assign_Bit(port,DIO_U8_PIN1,p1);
	Assign_Bit(port,DIO_U8_PIN2,p2);
	Assign_Bit(port,DIO_U8_PIN3,p3);
	Assign_Bit(port,DIO_U8_PIN4,p4);
	Assign_Bit(port,DIO_U8_PIN5,p5);
	Assign_Bit(port,DIO_U8_PIN6,p6);
	Assign_Bit(port,DIO_U8_PIN7,p7);
	return port;

}


void DIO_void_Init(void)
{
	/*direction*/
	DIO_U8_DDRA =INTIAL_DIR(DIO_u8_PA0_INTIAL_DIR,DIO_u8_PA1_INTIAL_DIR,DIO_u8_PA2_INTIAL_DIR,DIO_u8_PA3_INTIAL_DIR,DIO_u8_PA4_INTIAL_DIR,DIO_u8_PA5_INTIAL_DIR,DIO_u8_PA6_INTIAL_DIR,DIO_u8_PA7_INTIAL_DIR);
	DIO_U8_DDRB =INTIAL_DIR(DIO_u8_PB0_INTIAL_DIR,DIO_u8_PB1_INTIAL_DIR,DIO_u8_PB2_INTIAL_DIR,DIO_u8_PB3_INTIAL_DIR,DIO_u8_PB4_INTIAL_DIR,DIO_u8_PB5_INTIAL_DIR,DIO_u8_PB6_INTIAL_DIR,DIO_u8_PB7_INTIAL_DIR);
	DIO_U8_DDRC =INTIAL_DIR(DIO_u8_PC0_INTIAL_DIR,DIO_u8_PC1_INTIAL_DIR,DIO_u8_PC2_INTIAL_DIR,DIO_u8_PC3_INTIAL_DIR,DIO_u8_PC4_INTIAL_DIR,DIO_u8_PC5_INTIAL_DIR,DIO_u8_PC6_INTIAL_DIR,DIO_u8_PC7_INTIAL_DIR);
	DIO_U8_DDRD =INTIAL_DIR(DIO_u8_PD0_INTIAL_DIR,DIO_u8_PD1_INTIAL_DIR,DIO_u8_PD2_INTIAL_DIR,DIO_u8_PD3_INTIAL_DIR,DIO_u8_PD4_INTIAL_DIR,DIO_u8_PD5_INTIAL_DIR,DIO_u8_PD6_INTIAL_DIR,DIO_u8_PD7_INTIAL_DIR);
}

u8 DIO_U8_Set_Pin_Dir(u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 Copy_U8_Pin_Dir)
{
	if((Copy_U8_Port_ID>=DIO_MIN_U8_PROT_ID)&&(Copy_U8_Port_ID<=DIO_MAX_U8_PROT_ID))
	{
		if((Copy_U8_Pin_ID>=DIO_MIN_U8_PIN_ID)&&(Copy_U8_Pin_ID<=DIO_MAX_U8_PIN_ID))
		{
			if((Copy_U8_Pin_Dir==PIN_INPUT)||(Copy_U8_Pin_Dir==PIN_OUTPUT))
			{
				switch(Copy_U8_Port_ID)
				{
				case PORTA_ID:
					Assign_Bit(DIO_U8_DDRA,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
					break;
				case PORTB_ID:
					Assign_Bit(DIO_U8_DDRB,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
					break;
				case PORTC_ID:
					Assign_Bit(DIO_U8_DDRC,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
					break;
				case PORTD_ID:
					Assign_Bit(DIO_U8_DDRD,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
					break;

				}
			}
			else
			{
				return WRONG_PIN_DIR;
			}
		}
		else{
			return WRONG_PIN;
		}


	}
	else
	{
		return WRONG_PORT;
	}

	return NO_ERRORS;
}





u8 DIO_U8_Set_Port_Dir(u8 Copy_U8_Port_ID  , u16 Copy_U8_PORT_Dir)
{
	if((Copy_U8_Port_ID>=DIO_MIN_U8_PROT_ID)&&(Copy_U8_Port_ID<=DIO_MAX_U8_PROT_ID))
	{
		if((Copy_U8_PORT_Dir)>=MIN_DIR_OR_VALUE&&(Copy_U8_PORT_Dir)<=MAX_DIR_OR_VALUE)
		{
				switch(Copy_U8_Port_ID)
				{
				case PORTA_ID:
					DIO_U8_DDRA=Copy_U8_PORT_Dir;
					break;
				case PORTB_ID:
					DIO_U8_DDRB=Copy_U8_PORT_Dir;
					break;
				case PORTC_ID:
					DIO_U8_DDRC=Copy_U8_PORT_Dir;
					break;
				case PORTD_ID:
					DIO_U8_DDRD=Copy_U8_PORT_Dir;
					break;

				}
		}
		else
		{
			return WRONG_PORT_DIR;
		}

	}
	else
	{
		return WRONG_PORT;
	}

	return NO_ERRORS;
}







u8 DIO_U8_Set_Pin_value(u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 Copy_U8_Pin_value)
{
	if((Copy_U8_Port_ID>=DIO_MIN_U8_PROT_ID)&&(Copy_U8_Port_ID<=DIO_MAX_U8_PROT_ID))
	{
		if((Copy_U8_Pin_ID>=DIO_MIN_U8_PIN_ID)&&(Copy_U8_Pin_ID<=DIO_MAX_U8_PIN_ID))
		{
			if((Copy_U8_Pin_value==PIN_LOW)||(Copy_U8_Pin_value==PIN_HIGH))
			{
				switch(Copy_U8_Port_ID)
				{
				case PORTA_ID:
					Assign_Bit(DIO_U8_PORTA,Copy_U8_Pin_ID,Copy_U8_Pin_value);
					break;
				case PORTB_ID:
					Assign_Bit(DIO_U8_PORTB,Copy_U8_Pin_ID,Copy_U8_Pin_value);
					break;
				case PORTC_ID:
					Assign_Bit(DIO_U8_PORTC,Copy_U8_Pin_ID,Copy_U8_Pin_value);
					break;
				case PORTD_ID:
					Assign_Bit(DIO_U8_PORTD,Copy_U8_Pin_ID,Copy_U8_Pin_value);
					break;

				}
			}
			else
			{
				return WRONG_PIN_value;
			}
		}
		else{
			return WRONG_PIN;
		}


	}
	else
	{
		return WRONG_PORT;
	}

	return NO_ERRORS;
}










u8 DIO_U8_Set_Port_Value(u8 Copy_U8_Port_ID  , u16 Copy_U8_PORT_value)
{
	if((Copy_U8_PORT_value>=DIO_MIN_U8_PROT_ID)&&(Copy_U8_PORT_value<=DIO_MAX_U8_PROT_ID))
	{
			if((Copy_U8_PORT_value)>=MIN_DIR_OR_VALUE&&(Copy_U8_PORT_value)<=MAX_DIR_OR_VALUE)
			{
				switch(Copy_U8_Port_ID)
				{
				case PORTA_ID:
					DIO_U8_PORTA=Copy_U8_PORT_value;
					break;
				case PORTB_ID:
					DIO_U8_PORTB=Copy_U8_PORT_value;
					break;
				case PORTC_ID:
					DIO_U8_PORTC=Copy_U8_PORT_value;
					break;
				case PORTD_ID:
					DIO_U8_PORTD=Copy_U8_PORT_value;
					break;

				}
			}
			else
			{
				return WRONG_PORT_VALUE;
			}


	}
	else
	{
		return WRONG_PORT;
	}

	return NO_ERRORS;
}




u8 DIO_U8_Get_pin_value(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID , u8 *Copy_U8_Pin_Value)
{
	if((Copy_U8_Port_ID>=DIO_MIN_U8_PROT_ID)&&(Copy_U8_Port_ID<=DIO_MAX_U8_PROT_ID))
	{
		if((Copy_U8_Pin_ID>=DIO_MIN_U8_PIN_ID)&&(Copy_U8_Pin_ID<=DIO_MAX_U8_PIN_ID))
		{

			switch(Copy_U8_Port_ID)
							{
				case PORTA_ID:
					*Copy_U8_Pin_Value = Get_Bit(DIO_U8_PINA,Copy_U8_Pin_ID);
					break;
				case PORTB_ID:
					*Copy_U8_Pin_Value = Get_Bit(DIO_U8_PINB,Copy_U8_Pin_ID);
					break;
				case PORTC_ID:
					*Copy_U8_Pin_Value = Get_Bit(DIO_U8_PINC,Copy_U8_Pin_ID);
					break;
				case PORTD_ID:
					*Copy_U8_Pin_Value = Get_Bit(DIO_U8_PIND,Copy_U8_Pin_ID);
					break;
							}
		}
		else
		{
			return WRONG_PIN;
		}
	}
	else
	{
		return WRONG_PORT;
	}
}
