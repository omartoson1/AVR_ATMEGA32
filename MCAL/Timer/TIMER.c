/*
 * TIMER_Config.c
 *
 *  Created on: Aug 26, 2021
 *      Author: omar
 */
#include "TIMER.h"

Timer0_config timer0 = {div_256_0,fast_pwm,clear};
Timer2_config timer2 = {div_256_2,fast_pwm,clear};
// timer 0 and 2 have different clock prescaler
void (*timer0_OVF_CallBack)(void);
void (*timer0_CompareMatch_CallBack)(void);
void (*timer2_OVF_CallBack)(void);
void (*timer2_CompareMatch_CallBack)(void);
void timer0_OVF(void){

}
void timer0_CompareMatch(void){

}
void timer2_OVF(void){

}
void timer2_CompareMatch(void){

}
ISR(TIMER0_OVF_vect){
	timer0_OVF_CallBack();
}
ISR(TIMER0_COMP_vect){
	timer0_CompareMatch_CallBack();
}
ISR(TIMER2_OVF_vect){
	timer2_OVF_CallBack();
}
ISR(TIMER2_COMP_vect){
	timer2_CompareMatch_CallBack();
}
void timer0_init(){
	timer0_OVF_CallBack=timer0_OVF;
	timer0_CompareMatch_CallBack=timer0_CompareMatch;

	TCNT0= timer0_TCNT_init;
	OCR0 = timer0_OCR_init;

	if (timer0.comp_match_mode == disconnect) {
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);}
	else if (timer0.comp_match_mode == toggle){
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);}
	else if (timer0.comp_match_mode == clear){
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);}
	else if (timer0.comp_match_mode == set){
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);}

	if (timer0.mode ==normal){
		CLEAR_BIT(TCCR0,WGM00);// timer mode
		CLEAR_BIT(TCCR0,WGM01);}
	else if (timer0.mode ==phase_correct_pwm){
		SET_BIT(TCCR0,WGM00);// timer mode
		CLEAR_BIT(TCCR0,WGM01);}
	else if (timer0.mode ==ctc){
		CLEAR_BIT(TCCR0,WGM00);// timer mode
		SET_BIT(TCCR0,WGM01);}
	else if (timer0.mode ==fast_pwm){
		SET_BIT(TCCR0,WGM00);// timer mode
		SET_BIT(TCCR0,WGM01);}

	if (timer0.prescaler ==no_source_0){
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);// prescaler
	} else if (timer0.prescaler ==sys_clk_0){
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);//no prescale
	} else if (timer0.prescaler ==div_8_0){
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);// prescaler
	} else if (timer0.prescaler ==div_64_0){
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);// prescaler
	} else if (timer0.prescaler ==div_256_0){
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);// prescaler
	} else if (timer0.prescaler ==div_1024_0){
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);// prescaler
	} else if (timer0.prescaler ==external_falling_0){
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);// prescaler
	} else if (timer0.prescaler ==external_rising_0){
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);}
}
void timer0_set_OCR(uint8 val){
	OCR0 = val;
}
void timer0_set_TCNT(uint8 val){
	TCNT0 = val;
}
void timer0_OVF_interrupt_state(uint8 state){
	if (state==enable){
		SET_BIT(TIMSK,TOIE0);
	} else if (state == disable){
		CLEAR_BIT(TIMSK,TOIE0);}
}
void timer0_CompareMatch_interrupt_state(uint8 state){
	if (state==enable){
		SET_BIT(TIMSK,OCIE0);
	} else if (state == disable){
		CLEAR_BIT(TIMSK,OCIE0);}
}
void timer0_ForceOutputCompare(uint8 state){
	if (state == enable){
		SET_BIT(TCCR0,FOC0);
	}else if(state == disable){
		CLEAR_BIT(TCCR0,FOC0);}
}
void timer0_set_OVF_CallBack(void (*CallBack_P2F)(void)){
	timer0_OVF_CallBack = CallBack_P2F;
}
void timer0_set_CompareMatch_CallBack(void (*CallBack_P2F)(void)){
	timer0_CompareMatch_CallBack = CallBack_P2F;
}
void timer2_init(){
	timer2_OVF_CallBack=timer2_OVF;
	timer2_CompareMatch_CallBack=timer2_CompareMatch;

	TCNT2= timer2_TCNT_init;
	OCR2= timer2_OCR_init;

	if (timer2.comp_match_mode == disconnect) {
		CLEAR_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);}
	else if (timer2.comp_match_mode == toggle){
		SET_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);}
	else if (timer2.comp_match_mode == clear){
		CLEAR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);}
	else if (timer2.comp_match_mode == set){
		SET_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);}

	if (timer2.mode ==normal){
		CLEAR_BIT(TCCR2,WGM20);// timer mode
		CLEAR_BIT(TCCR2,WGM21);}
	else if (timer2.mode ==phase_correct_pwm){
		SET_BIT(TCCR2,WGM20);// timer mode
		CLEAR_BIT(TCCR2,WGM21);}
	else if (timer2.mode ==ctc){
		CLEAR_BIT(TCCR2,WGM20);// timer mode
		SET_BIT(TCCR2,WGM21);}
	else if (timer2.mode ==fast_pwm){
		SET_BIT(TCCR2,WGM20);// timer mode
		SET_BIT(TCCR2,WGM21);}

	if (timer2.prescaler ==no_source_2){
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);// prescaler
	} else if (timer2.prescaler ==sys_clk_2){
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);//no prescale
	} else if (timer2.prescaler ==div_8_2){
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS02);// prescaler
	} else if (timer2.prescaler ==div_32_2){
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);// prescaler
	} else if (timer2.prescaler ==div_64_2){
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);// prescaler
	} else if (timer2.prescaler ==div_128_2){
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);// prescaler
	} else if (timer2.prescaler ==div_256_2){
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);// prescaler
	} else if (timer2.prescaler ==div_1024_2){
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);}
}
void timer2_set_OCR(uint8 val){
	OCR2 = val;
}
void timer2_set_TCNT(uint8 val){
	TCNT2 = val;
}
void timer2_OVF_interrupt_state(uint8 state){
	if (state==enable){
		SET_BIT(TIMSK,TOIE2);
	} else if (state == disable){
		CLEAR_BIT(TIMSK,TOIE2);}
}
void timer2_CompareMatch_interrupt_state(uint8 state){
	if (state==enable){
		SET_BIT(TIMSK,OCIE2);
	} else if (state == disable){
		CLEAR_BIT(TIMSK,OCIE2);}
}
void timer2_ForceOutputCompare(uint8 state){
	if (state == enable){
		SET_BIT(TCCR2,FOC2);
	}else if(state == disable){
		CLEAR_BIT(TCCR2,FOC2);}
}
void timer2_set_OVF_CallBack(void (*CallBack_P2F)(void)){
	timer2_OVF_CallBack = CallBack_P2F;
}
void timer2_set_CompareMatch_CallBack(void (*CallBack_P2F)(void)){
	timer2_CompareMatch_CallBack = CallBack_P2F;
}






