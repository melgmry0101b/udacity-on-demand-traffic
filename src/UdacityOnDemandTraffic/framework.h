/*
 * framework.h
 *
 * Created: 14/01/2023 02:48:07 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

/************************************************************************/
/* Bit manipulation macros                                              */
/************************************************************************/

#define SET_BIT(X,BIT_NO) ((X) |= (1 << (BIT_NO)))
#define CLR_BIT(X,BIT_NO) ((X) &= ~(1 << (BIT_NO)))
#define READ_BIT(X,BIT_NO) (((X) & (1 << (BIT_NO))) >> (BIT_NO))
#define TOGGLE_BIT(X,BIT_NO) ((X) ^= (1 << (BIT_NO)))

/************************************************************************/
/* Here we include our standard library stuff                           */
/************************************************************************/
#include <stddef.h>
#include <stdint.h>
#include <math.h>

/************************************************************************/
/* Include the standard `io.h` provided for avr                         */
/************************************************************************/
// I opted into using `io.h` rather defining my own `registers.h` as this
//	embraces portability and reduces errors copying addresses from the
//	datasheets and fiddling around with `*(volatile uint8_t*)`.

#define F_CPU 1000000UL // 1 MHz

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

/************************************************************************/
/* Including "Microcontroller Abstraction Layer"                        */
/************************************************************************/
#include "MCAL/mcal.h"

/************************************************************************/
/* Including "Electronic Unit Abstraction Layer"                        */
/************************************************************************/
#include "ECUAL/ecual.h"

#endif /* FRAMEWORK_H_ */