/*
 * DIO.c
 *
 *  Created on: Jul 30, 2021
 *      Author: omar
 */

#include "../../BIT_MATH.h"
#include <avr/io.h>
void DIO_Write(uint8_t pin, uint8_t status ){

	uint8_t port = pin/8;
	pin = pin%8;
	if (port == 0){
		if(status == 1){
			SET_BIT(PORTA, pin);
		}else if(status == 0){
			CLEAR_BIT(PORTA, pin);
		}
	}else if(port == 1){
		if(status == 1){
			SET_BIT(PORTB, pin);
		}else if(status == 0){
			CLEAR_BIT(PORTB, pin);
		}
	}else if(port == 2){
		if(status == 1){
			SET_BIT(PORTC, pin);
		}else if(status == 0){
			CLEAR_BIT(PORTC, pin);
		}
	}else if(port == 3){
		if(status == 1){
			SET_BIT(PORTD, pin);
		}else if(status == 0){
			CLEAR_BIT(PORTD, pin);
		}
	}
}

void DIO_Write_Port(uint8_t port, uint8_t data){
	if (port == 0){
		PORTA = data;
	}else if(port == 1){
		PORTB = data;
	}else if(port == 2){
		PORTC = data;
	}else if(port == 3){
		PORTD = data;
	}
}



void PORT_Dir(uint8_t pin, uint8_t status ){

	uint8_t port = pin/8;
	pin = pin%8;
	if (port == 0){
		if(status == 1){
			SET_BIT(DDRA, pin);
		}else if(status == 0){
			CLEAR_BIT(DDRA, pin);
		}
	}else if(port == 1){
		if(status == 1){
			SET_BIT(DDRB, pin);
		}else if(status == 0){
			CLEAR_BIT(DDRB, pin);
		}
	}else if(port == 2){
		if(status == 1){
			SET_BIT(DDRC, pin);
		}else if(status == 0){
			CLEAR_BIT(DDRC, pin);
		}
	}else if(port == 3){
		if(status == 1){
			SET_BIT(DDRD, pin);
		}else if(status == 0){
			CLEAR_BIT(DDRD, pin);
		}
	}
}


uint8_t DIO_Read(uint8_t pin){
	if ((pin/8) == 0){
		return GET_BIT(PINA, pin%8);
	}else if((pin/8) == 1){
		return GET_BIT(PINB, pin%8);
	}else if((pin/8) == 2){
		return GET_BIT(PINC, pin%8);
	}else{
		return GET_BIT(PIND, pin%8);
	}
}
