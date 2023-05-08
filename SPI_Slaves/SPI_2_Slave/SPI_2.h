
#ifndef SPI_2_H_
#define SPI_2_H_

typedef struct{
	volatile u8 SPCR;
	volatile u8 SPSR;
	volatile u8 SPDR;
}SPI_St;

#define SPI_REG ((SPI_St *)0x2D)
/*
#define SPCR	(*(volatile u8*) 0x2D)
#define SPSR	(*(volatile u8*) 0x2E)
#define SPDR	(*(volatile u8*) 0x2F)
*/



void SPI_MasterInit(void);
void SPI_MasterTransmit(u8 cData);
void SPI_SlaveInit(void);
u8 SPI_SlaveReceive(void);

#endif
