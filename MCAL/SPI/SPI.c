/*
 * SPI.c
 *
 *  Created on: Aug 21, 2021
 *      Author: omar
 */
#include "SPI.h"
void SPI_MasterInit(void){
	/* Set MOSI and SCK output, all others input */
	//DDRB = (1<<DD_MOSI)|(1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(char data)
{
/* Start transmission */
SPDR = data;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
}
