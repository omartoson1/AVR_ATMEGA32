/*
 * TIMER_Config.h
 *
 *  Created on: Aug 26, 2021
 *      Author: omar
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../../BIT_MATH.h"
#include "../../STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TIMER_Config.h"

void timer0_init(void);
void timer0_set_OCR(uint8 val);
void timer0_set_TCNT(uint8 val);
void timer0_OVF_interrupt_state(uint8 state);
void timer0_CompareMatch_interrupt_state(uint8 state);
void timer0_ForceOutputCompare(uint8 state);
void timer0_set_OVF_CallBack(void (*CallBack_P2F)(void));
void timer0_set_CompareMatch_CallBack(void (*CallBack_P2F)(void));

void timer2_init(void);
void timer2_set_OCR(uint8 val);
void timer2_set_TCNT(uint8 val);
void timer2_OVF_interrupt_state(uint8 state);
void timer2_CompareMatch_interrupt_state(uint8 state);
void timer2_ForceOutputCompare(uint8 state);
void timer2_set_OVF_CallBack(void (*CallBack_P2F)(void));
void timer2_set_CompareMatch_CallBack(void (*CallBack_P2F)(void));

#endif /* MCAL_TIMER_TIMER_H_ */
