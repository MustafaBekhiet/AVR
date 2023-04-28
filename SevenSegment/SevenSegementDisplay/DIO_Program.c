/*
 * DIO_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DioSetPinDirection(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8direction)
{

		if(Copy_u8pin <= PIN7)
		{
			if(Copy_u8direction == INPUT)
			{
				switch(Copy_u8port)
				{
				case portA:
					CLR_BIT(DDRA,Copy_u8pin);
					break;
				case portB:
					CLR_BIT(DDRB,Copy_u8pin);
					break;
				case portC:
					CLR_BIT(DDRC,Copy_u8pin);
					break;
				case portD:
					CLR_BIT(DDRD,Copy_u8pin);
					break;
				default:

					break;
				}
			}
			else if(Copy_u8direction == OUTPUT)
			{
				switch(Copy_u8port)
				{
				case portA:
					SET_BIT(DDRA,Copy_u8pin);
					break;
				case portB:
					SET_BIT(DDRB,Copy_u8pin);
					break;
				case portC:
					SET_BIT(DDRC,Copy_u8pin);
					break;
				case portD:
					SET_BIT(DDRD,Copy_u8pin);
					break;
				default:

					break;
				}
			}
			else
			{

			}
		}

		else
		{

		}
}
void DioSetPinValue(u8 Copy_u8port,u8 Copy_u8pin, u8 Copy_u8value)
{
	if(Copy_u8pin<=PIN7)
		{
			if(Copy_u8value == HIGH)
			{
				switch(Copy_u8port)
				{
				case portA:
					SET_BIT(PORTA,Copy_u8pin);
					break;
				case portB:
					SET_BIT(PORTB,Copy_u8pin);
					break;
				case portC:
					SET_BIT(PORTC,Copy_u8pin);
					break;
				case portD:
					SET_BIT(PORTD,Copy_u8pin);
					break;
				default:

					break;
				}
			}
			else if(Copy_u8value == LOW)
			{
				switch(Copy_u8port)
				{
				case portA:
					CLR_BIT(PORTA,Copy_u8pin);
					break;
				case portB:
					CLR_BIT(PORTB,Copy_u8pin);
					break;
				case portC:
					CLR_BIT(PORTC,Copy_u8pin);
					break;
				case portD:
					CLR_BIT(PORTD,Copy_u8pin);
					break;
				default:

					break;
				}

			}
			else
			{

			}
		}
		else
		{

		}


}
u8 DioGetPinValue(u8 Copy_u8port, u8 Copy_u8pin)
{

	u8 pinStatus =0;
		if(Copy_u8pin<=PIN7)
		{
			switch(Copy_u8port)
			{
			case portA:
				pinStatus = GET_BIT(PINA,Copy_u8pin);
				break;
			case portB:
				pinStatus = GET_BIT(PINB,Copy_u8pin);
				break;
			case portC:
				pinStatus = GET_BIT(PINC,Copy_u8pin);
				break;
			case portD:
				pinStatus = GET_BIT(PIND,Copy_u8pin);
				break;
			default:

				break;
			}

		}
		else
		{

		}

	return pinStatus;
}

void DioSetPortDirection(u8 Copy_u8port, u8 Copy_u8direction)
{
	switch(Copy_u8port)
		{
		case portA:
			DDRA = Copy_u8direction;
			break;
		case portB:
			DDRB = Copy_u8direction;
			break;
		case portC:
			DDRC = Copy_u8direction;
			break;
		case portD:
			DDRD = Copy_u8direction;
			break;
		default:

			break;

		}
}
void DioSetPortValue(u8 Copy_u8port, u8 Copy_u8value)
{
	switch(Copy_u8port)
			{
			case portA:
				PORTA = Copy_u8value;
				break;
			case portB:
				PORTC = Copy_u8value;
				break;
			case portC:
				PORTC = Copy_u8value;
				break;
			case portD:
				PORTD = Copy_u8value;
				break;
			default:

				break;

			}
}
u8 DioGetPortValue(u8 Copy_u8port)
{
	u8 portValue=0;
	switch(Copy_u8port)
				{
				case portA:
					portValue = PINA;
					break;
				case portB:
					portValue = PINB;
					break;
				case portC:
					portValue = PINC;
					break;
				case portD:
					portValue = PIND;
					break;
				default:

					break;

				}
	return portValue;
}





