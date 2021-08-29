/*
 * DIO_Config.c
 *
 *  Created on: Aug 19, 2021
 *      Author: omar
 */

#include "DIO_Config.h"

DIO_PinConfig Pin_config[] = {
		// PORTA
		{dio_porta,dio_pin_0,output,low},
		{dio_porta,dio_pin_1,output,low},
		{dio_porta,dio_pin_2,output,low},
		{dio_porta,dio_pin_3,output,low},
		{dio_porta,dio_pin_4,output,low},
		{dio_porta,dio_pin_5,output,low},
		{dio_porta,dio_pin_6,output,low},
		{dio_porta,dio_pin_7,output,low},

		// PORTB
		{dio_portb,dio_pin_0,output,low},
		{dio_portb,dio_pin_1,output,low},
		{dio_portb,dio_pin_2,output,low},
		{dio_portb,dio_pin_3,output,low},
		{dio_portb,dio_pin_4,output,low},
		{dio_portb,dio_pin_5,output,low},
		{dio_portb,dio_pin_6,output,low},
		{dio_portb,dio_pin_7,output,low},

		// PORTC
		{dio_portc,dio_pin_0,output,low},
		{dio_portc,dio_pin_1,output,low},
		{dio_portc,dio_pin_2,output,low},
		{dio_portc,dio_pin_3,output,low},
		{dio_portc,dio_pin_4,output,low},
		{dio_portc,dio_pin_5,output,low},
		{dio_portc,dio_pin_6,output,low},
		{dio_portc,dio_pin_7,output,low},

		// PORTD
		{dio_portd,dio_pin_0,output,low},
		{dio_portd,dio_pin_1,output,low},
		{dio_portd,dio_pin_2,output,low},
		{dio_portd,dio_pin_3,output,low},
		{dio_portd,dio_pin_4,output,low},
		{dio_portd,dio_pin_5,output,low},
		{dio_portd,dio_pin_6,output,low},
		{dio_portd,dio_pin_7,output,low},

};

void Dio_init(void){
	int count = sizeof(Pin_config)/sizeof(Pin_config[0]);
	for(int i =0; i<count;i++){

		if(Pin_config[i].PinPort==dio_porta){
			if(Pin_config[i].PinDir==output){
				SET_BIT(DDRA,Pin_config[i].pin);
			}else{
				CLEAR_BIT(DDRA,Pin_config[i].pin);
			}
		}

		else if(Pin_config[i].PinPort==dio_portb){
			if(Pin_config[i].PinDir==output){
				SET_BIT(DDRB,Pin_config[i].pin);
		 	 }else{
		 		CLEAR_BIT(DDRB,Pin_config[i].pin);
		 	}
		}

		else if(Pin_config[i].PinPort==dio_portc){
			if(Pin_config[i].PinDir==output){
				SET_BIT(DDRC,Pin_config[i].pin);
		 	 }else{
		 		CLEAR_BIT(DDRC,Pin_config[i].pin);
		 	}
		}

		else if(Pin_config[i].PinPort==dio_portd){
			if(Pin_config[i].PinDir==output){
				SET_BIT(DDRD,Pin_config[i].pin);
		 	 }else{
		 		CLEAR_BIT(DDRD,Pin_config[i].pin);
		 	}
		}
	}
}




