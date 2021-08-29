/*
 * DIO_Types.h
 *
 *  Created on: Aug 19, 2021
 *      Author: omar
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

typedef enum {
	// PORTA
	pina_0,
	pina_1,
	relay,
	buzzer,
	lcd_d4,
	lcd_d5,
	lcd_d6,
	lcd_d7,


	//PORTB
	button0,
	lcd_rs,
	lcd_rw, 	slave1 = 10,
	lcd_en, 	slave2 = 11,
	button_1,
	pinb_5,
	pinb_6,
	pinb_7,

	//PORTC
	pinc_0,
	pinc_1,
	led_0,
	hbridge_1,
	hbridge_2,
	hbridge_3,
	hbridge_4,
	led_1,

	//PORTD
	pind_0,
	pind_1,
	button_2,
	led_2,
	hbridge_e1,
	hbridge_e2,
	pind_6,
	pind_7
}channel_type;

typedef enum{
	dio_pin_0,
	dio_pin_1,
	dio_pin_2,
	dio_pin_3,
	dio_pin_4,
	dio_pin_5,
	dio_pin_6,
	dio_pin_7
}DIO_Pin;

typedef enum{
	dio_porta,
	dio_portb,
	dio_portc,
	dio_portd
}DIO_Port;

typedef enum{
	low,
	high
}DIO_Level;

typedef enum {
	input,
	output
}DIO_Dir;

#endif /* MCAL_DIO_DIO_TYPES_H_ */
