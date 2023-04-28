/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

#include "sevenSegment.h"
#include <util/delay.h>
void main(void)
{
	sevenSegmentInit(portC);

	while(1)
	{

			DisplaytoNumber(portC,99);

		//_delay_ms(50);
	}
}

