/*
 * timer.h
 *
 * Created: 10/01/2023 09:11:30 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef TIMER_H_
#define TIMER_H_

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

// We are using Timer0 in normal mode with 1024 prescalar and a 1 MHz CPU Clock,
//	we should calculate this dynamically or use compile time constant expressions (C++),
//	but for the sake of brevity, we will hard code the values.
#define TIMER0_TICK 1.024 // ms

// This is the max delay for TIMER0 in ms.
#define TIMER0_MAX 262.144 // ms

/************************************************************************/
/* Types                                                                */
/************************************************************************/

typedef enum _TIMER_STATE
{
	TIMER_STOPPED,
	TIMER_RUNNING
} TIMER_STATE;

/************************************************************************/
/* Timer0 functions                                                      */
/************************************************************************/

// =======================================
// Initialize Timer0.
// =======================================
void TIMER0_init(void);

// =======================================
// Set Timer0 wait period.
// =======================================
void TIMER0_set(uint16_t ms);

// =======================================
// Start Timer0.
// =======================================
void TIMER0_start(void);

// =======================================
// Stop Timer0.
// =======================================
void TIMER0_stop(void);

// =======================================
// Get Timer0 current state.
// =======================================
TIMER_STATE TIMER0_get_state(void);

#endif /* TIMER_H_ */