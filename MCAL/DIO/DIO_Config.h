/*
 * DIO_Config.h
 *
 *  Created on: Aug 19, 2021
 *      Author: omar
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

#include <avr/io.h>
#include "DIO_Types.h"
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"

#define PIN_Count 4

typedef struct{
	DIO_Port PinPort;
	DIO_Pin pin;
	DIO_Dir PinDir;
	DIO_Level PinLevel;
}DIO_PinConfig;

void Dio_init(void);

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
