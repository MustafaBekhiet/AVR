/*
 * SPI_1.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: EL CONSUL
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "GPIO_registers.h"
#include "SPI_2.h"

void SPI_MasterInit(void)
{

	// Enable MOSI  Set MOSI as an output
	SET_BIT(SPI_REG->SPCR,5);
	CLR_BIT(SPI_REG->SPCR,3);
	CLR_BIT(SPI_REG->SPCR,2);
	CLR_BIT(SPI_REG->SPSR,0);
	CLR_BIT(SPI_REG->SPCR,0);
	SET_BIT(SPI_REG->SPCR,1);
	SET_BIT(SPI_REG->SPCR,4);
	SET_BIT(SPI_REG->SPCR,6);

}
void SPI_MasterTransmit(u8 cData){
	u8 Transfere_Data = cData;
	SPI_REG->SPDR = Transfere_Data;
	while(!(GET_BIT(SPI_REG->SPSR,7)));

}
void SPI_SlaveInit(void){

	// Set MISO as an output
	SET_BIT(SPI_REG->SPCR,5);
	CLR_BIT(SPI_REG->SPCR,3);
	CLR_BIT(SPI_REG->SPCR,2);
	CLR_BIT(SPI_REG->SPCR,4);
	SET_BIT(SPI_REG->SPCR,6);
}
u8 SPI_SlaveReceive(void){
	u8 returned_Data = SPI_REG->SPDR;

	while(!(GET_BIT(SPI_REG->SPSR,7)));
	return returned_Data;
}

