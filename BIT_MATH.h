/*
 * BIT_MATH.h
 *
 *  Created on: Jul 17, 2021
 *      Author: omar
 */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(REG,INDEX)	((REG>>INDEX)&0x01)
#define TOG_BIT(REG,PIN)	REG^=(1<<(PIN))
#define SET_BIT(REG,BIT)	REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT)	REG&=(~(1<<BIT))




#endif /* BIT_MATH_H_ */
