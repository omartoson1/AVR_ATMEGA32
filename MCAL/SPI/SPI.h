/*
 * SPI.h
 *
 *  Created on: Aug 21, 2021
 *      Author: omar
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_
#include <avr/io.h>
void SPI_MasterInit(void);
void SPI_MasterTransmit(char data);

#endif /* MCAL_SPI_SPI_H_ */
