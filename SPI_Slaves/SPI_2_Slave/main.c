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
#include "SPI_2.h"

int main()
{
	//SET_BIT(DDRA,0); CLR_BIT(PORTA,0); // LED

	CLR_BIT(DDRB,7); // INPUT
	CLR_BIT(DDRB,5); // INPUT
	CLR_BIT(DDRB,4); // INPUT

	SET_BIT(DDRB,6); // OUTPUT
	SPI_SlaveInit();

	while(1)
	{

		SPI_MasterTransmit(SPI_REG->SPDR);
	}
	return 0;
}
