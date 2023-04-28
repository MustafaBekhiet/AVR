/*
 * sevenSegment.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include <util/delay.h>

void sevenSegmentInit(u8 Copy_u8port)
{
	DioSetPinDirection(portB,PIN0,OUTPUT);
	DioSetPinDirection(portB,PIN1,OUTPUT);
	switch(Copy_u8port)
	{
	case portA:
		DioSetPortDirection(portA,PORTA | 0x01);
		break;
	case portB:
		DioSetPortDirection(portB,PORTB | 0x01);
		break;
	case portC:
		DioSetPortDirection(portC,PORTC | 0x01);
		break;
	case portD:
		DioSetPortDirection(portD,PORTD | 0x01);
		break;
	}
}
void DisplaytoNumber(u8 Copy_u8port,u16 Copy_u8number)
{
	static int count =0;
	count++;
	if(count == Copy_u8number)
		{
			count =0;
		}
	switch(Copy_u8port)
	{
	case portA:
		DioSetPinValue(portB,PIN0,LOW);
			DioSetPortValue(portA,count/10 );//left
			_delay_ms(10);
			DioSetPinValue(portB,PIN0,HIGH);

			DioSetPinValue(portB,PIN1,LOW);
			DioSetPortValue(portA,count%10 );//Right
			_delay_ms(10);
			DioSetPinValue(portB,PIN1,HIGH);
		break;
	case portB:
		DioSetPinValue(portB,PIN0,LOW);
			DioSetPortValue(portB,count/10 );//left
			_delay_ms(10);
			DioSetPinValue(portB,PIN0,HIGH);

			DioSetPinValue(portB,PIN1,LOW);
			DioSetPortValue(portB,count%10 );//Right
			_delay_ms(10);
			DioSetPinValue(portB,PIN1,HIGH);
		break;
	case portC:
		DioSetPinValue(portB,PIN0,LOW);
		DioSetPortValue(portC,count/10 );//left
		_delay_ms(10);
		DioSetPinValue(portB,PIN0,HIGH);

		DioSetPinValue(portB,PIN1,LOW);
		DioSetPortValue(portC,count%10 );//Right
		_delay_ms(10);
		DioSetPinValue(portB,PIN1,HIGH);

		break;
	case portD:
		DioSetPinValue(portB,PIN0,LOW);
			DioSetPortValue(portD,count/10 );//left
			_delay_ms(10);
			DioSetPinValue(portB,PIN0,HIGH);

			DioSetPinValue(portB,PIN1,LOW);
			DioSetPortValue(portD,count%10 );//Right
			_delay_ms(10);
			DioSetPinValue(portB,PIN1,HIGH);
			break;
	default:
		break;
	}

}
