/*
 * main.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "GPIO_registers.h"
#include "Global_Interface.h"
#include "SPI_3.h"

int main()
{
	SET_BIT(DDRA,0); CLR_BIT(PORTA,0); // LED

	CLR_BIT(DDRB,7); // INPUT
	CLR_BIT(DDRB,5); // INPUT
	CLR_BIT(DDRB,4); // INPUT

	SET_BIT(DDRB,6); // OUTPUT
	SPI_SlaveInit();
	u8 LED_Spi;
	while(1)
	{
		LED_Spi = SPI_SlaveReceive();
		if(LED_Spi){
			SET_BIT(PORTA,0);
		}
		else
		{
			CLR_BIT(PORTA,0);
		}
	}
	return 0;
}
