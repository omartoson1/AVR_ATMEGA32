/*
 * TIMER_Config.h
 *
 *  Created on: Aug 28, 2021
 *      Author: omar
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

#define timer0_TCNT_init 0 //(0->255)
#define timer0_OCR_init	 0 //(0->255)
#define timer0_compar_match_interrupt 0 //(0 ro 1)
#define timer2_OCR_init  0 //(0->255)
#define timer2_TCNT_init 0 //(0->255)
#define timer2_compar_match_interrupt 0 //(0 ro 1)
typedef enum {
	no_source_0,
	sys_clk_0,
	div_8_0,
	div_64_0,
	div_256_0,
	div_1024_0,
	external_falling_0,
	external_rising_0
}Prescaler0;
typedef enum {
	no_source_2,
	sys_clk_2,
	div_8_2,
	div_32_2,
	div_64_2,
	div_128_2,
	div_256_2,
	div_1024_2
}Prescaler2;
typedef enum {
	normal,
	phase_correct_pwm,
	ctc,
	fast_pwm
}Mode;
typedef enum {
	disconnect,
	toggle,
	clear,
	set
}Comp_match_mode;
typedef struct Timer0_config{
	Prescaler0 prescaler;
	Mode mode;
	Comp_match_mode comp_match_mode;
}Timer0_config;
typedef struct Timer2_config{
	Prescaler2 prescaler;
	Mode mode;
	Comp_match_mode comp_match_mode;
}Timer2_config;
#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
