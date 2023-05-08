/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "SPI_1.h"

#include "GPIO_registers.h"
#include "Global_Interface.h"

#include <util/delay.h>

int main()
{
	CLR_BIT(DDRA,0); SET_BIT(PORTA,0); // PB_Button

	SET_BIT(DDRB,7); // output
	CLR_BIT(DDRB,6); // input
	SET_BIT(DDRB,5);// output
	SET_BIT(DDRB,4);  // SS active low
	CLR_BIT(PORTB,4);
	SPI_MasterInit();
	u8 PB_1;
	while(1)
	{
		PB_1 = GET_BIT(PINA,0);

		if(!PB_1){
			SPI_MasterTransmit(1);
			SPI_MasterTransmit(1);
		}
		else if(PB_1)
		{
			SPI_MasterTransmit(0);
			SPI_MasterTransmit(0);
		}

	}
	return 0;
}
