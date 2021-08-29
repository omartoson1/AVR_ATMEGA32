/*
 * LCD.c
 *
 *  Created on: Jul 31, 2021
 *      Author: omar
 */



#include "LCD.h"


void lcd_command(uint8 cmd){

	DIO_Write(lcd_rs,low);
	DIO_Write(lcd_rw,low);
	//DIO_Write(lcd_en,low);

	GET_BIT(cmd,7)?DIO_Write(lcd_d7,high):DIO_Write(lcd_d7,low);
	GET_BIT(cmd,6)?DIO_Write(lcd_d6,high):DIO_Write(lcd_d6,low);
	GET_BIT(cmd,5)?DIO_Write(lcd_d5,high):DIO_Write(lcd_d5,low);
	GET_BIT(cmd,4)?DIO_Write(lcd_d4,high):DIO_Write(lcd_d4,low);
	DIO_Write(lcd_en,high);
	_delay_us(10);
	DIO_Write(lcd_en,low);
	_delay_us(200);

	GET_BIT(cmd,3)?DIO_Write(lcd_d7,high):DIO_Write(lcd_d7,low);
	GET_BIT(cmd,2)?DIO_Write(lcd_d6,high):DIO_Write(lcd_d6,low);
	GET_BIT(cmd,1)?DIO_Write(lcd_d5,high):DIO_Write(lcd_d5,low);
	GET_BIT(cmd,0)?DIO_Write(lcd_d4,high):DIO_Write(lcd_d4,low);
	DIO_Write(lcd_en,high);
	_delay_us(10);
	DIO_Write(lcd_en,low);
	_delay_us(200);
}

void lcd_init(){
	//DDRA = 0xff;			// set port direction as output
	DIO_Write(lcd_rw,low);
	_delay_ms(20);
	lcd_command(0x33);
	lcd_command(0x32);
	lcd_command(0x28);
	lcd_command(0x0f);
	lcd_command(0x06);
	lcd_command(0x01);
	_delay_ms(20);
}

void lcd_char(uint8 data){

	DIO_Write(lcd_rs,high);
	DIO_Write(lcd_rw,low);
	//DIO_Write(lcd_en,low);

	GET_BIT(data,7)?DIO_Write(lcd_d7,high):DIO_Write(lcd_d7,low);
	GET_BIT(data,6)?DIO_Write(lcd_d6,high):DIO_Write(lcd_d6,low);
	GET_BIT(data,5)?DIO_Write(lcd_d5,high):DIO_Write(lcd_d5,low);
	GET_BIT(data,4)?DIO_Write(lcd_d4,high):DIO_Write(lcd_d4,low);

	DIO_Write(lcd_en,high);
	_delay_us(10);
	DIO_Write(lcd_en,low);
	_delay_us(200);

	GET_BIT(data,3)?DIO_Write(lcd_d7,high):DIO_Write(lcd_d7,low);
	GET_BIT(data,2)?DIO_Write(lcd_d6,high):DIO_Write(lcd_d6,low);
	GET_BIT(data,1)?DIO_Write(lcd_d5,high):DIO_Write(lcd_d5,low);
	GET_BIT(data,0)?DIO_Write(lcd_d4,high):DIO_Write(lcd_d4,low);

	DIO_Write(lcd_en,high);
	_delay_us(1);
	DIO_Write(lcd_en,low);
	_delay_us(200);
}

void lcd_str(uint8 *str){
	int i =0;
	while(str[i]!=0){
		lcd_char(str[i]);
		i++;
	}
}

void lcd_clear(){
	lcd_command(0x01); //clear the display
	_delay_ms(2);
	lcd_command(0x80); //cursor at (0,0)
}

void lcd_str_xy(uint8 x, uint8 y,uint8 *str){
	if (y==0 && x<16){
		lcd_command((x & 0x0f)|0x80);//cursor at the xy cordinates
	}else if(y==1 && x<16){
		lcd_command((x & 0x0f)|0xc0);//cursor at the xy cordinates
	}
	lcd_str(str);
}









