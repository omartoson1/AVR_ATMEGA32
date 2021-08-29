/*
 * DIO.h
 *
 *  Created on: Jul 30, 2021
 *      Author: omar
 */

#ifndef DIO_H_
#define DIO_H_
#include <avr/io.h>
#include "DIO_Types.h"
#include "../../STD_Types.h"
#include "../../BIT_MATH.h"

void DIO_Write(unsigned char pin, unsigned char status );

uint8_t DIO_Read(uint8_t pin);
void PORT_Dir(uint8_t pin, uint8_t status);
void DIO_Write_Port(uint8_t port, uint8_t data);
#endif /* DIO_H_ */
