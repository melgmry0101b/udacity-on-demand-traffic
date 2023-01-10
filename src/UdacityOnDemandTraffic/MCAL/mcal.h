/*
 * mcal.h
 *
 * Created: 10/01/2023 09:13:58 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef MCAL_H_
#define MCAL_H_

/************************************************************************/
/* Include the standard `io.h` provided for avr                         */
/************************************************************************/
// I opted into using `io.h` rather defining my own `registers.h` as this
//	embraces portability and reduces errors copying addresses from the
//	datasheets and fiddling around with `*(volatile uint8_t*)`.
#include <avr/io.h>
#include <avr/interrupt.h>

/************************************************************************/
/* Include our drivers                                                  */
/************************************************************************/
#include "DIO/dio.h"
#include "Interrupts/interrupts.h"
#include "Timer/timer.h"

#endif /* MCAL_H_ */