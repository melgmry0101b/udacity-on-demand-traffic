/*
 * timer.c
 *
 * Created: 10/01/2023 09:11:39 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "timer.h"

/************************************************************************/
/* Globals                                                              */
/************************************************************************/

// Private for saving the required overflows before stopping the timer.
static uint16_t g_requiredOverflows = 0;

// Private global for the current timer state.
static TIMER_STATE g_timer0State = TIMER_STOPPED;

/************************************************************************/
/* ISR                                                                  */
/************************************************************************/

ISR(TIMER0_OVF_vect)
{
	// Disable interrupts
	cli();
	
	// if we are already at 0 required overflows, stop the timer
	if (g_requiredOverflows == 0)
	{
		TIMER0_stop();
		sei(); // Re-enable interrupts
		return; // The compiler will do the proper ISR clean up here.
	}
	
	// decrement the counter and check if we reached 0
	if (--g_requiredOverflows == 0)
	{
		TIMER0_stop();
		sei(); // Re-enable interrupts
		return; // The compiler will do the proper ISR clean up here.
	}
}

/************************************************************************/
/* Functions                                                            */
/************************************************************************/

// =======================================
// Initialize Timer0.
// =======================================
void TIMER0_init(void)
{
	// Enable Timer0 overflow interrupts,
	//	we will use interrupts to count overflow
	//	rather than using busy-waits; thus saving
	//	power for embedded applications.
	SET_BIT(TIMSK, TOIE0);
}

// =======================================
// Set Timer0 wait period.
// =======================================
void TIMER0_set(uint16_t ms)
{
	// Stop the timer when setting the wait period
	TIMER0_stop();
	
	if (ms == 0)
	{
		// setting the timer to 0ms only equals to stop.
		return;
	}
	
	if (ms == TIMER0_MAX)
	{
		g_requiredOverflows = 1; // One overflow
	}
	else if (ms < TIMER0_MAX)
	{
		// This calculation will be slow as heck! and will take much space of the program memory.
		// We should optimize these calculations using only integers.
		// NOTE: This calculation should not go over 255.
		uint8_t initialValue = (uint8_t)floor((TIMER0_MAX - ms) / (TIMER0_TICK));
		
		// Set the initial value register
		TCNT0 = initialValue;
		
		// Set the overflows required
		g_requiredOverflows = 1;
	}
	else // ms > TIMER0_MAX
	{
		// NOTE: we could've used `floor` and set and initial value for the remaining
		//	required time, but we opted in `ceil` for brevity.
		g_requiredOverflows = (uint16_t)ceil(ms / TIMER0_MAX);
	}
}

// =======================================
// Start Timer0.
// =======================================
void TIMER0_start(void)
{
	// Start the timer in normal mode with 1024 prescalar.
	TCCR0 = (1 << CS02) | (1 << CS00);
	
	// Set the status
	g_timer0State = TIMER_RUNNING;
}

// =======================================
// Stop Timer0.
// =======================================
void TIMER0_stop(void)
{
	// Stop the timer by setting Timer Control Register to 0.
	TCCR0 = 0;
	
	// Reset the timer counter
	TCNT0 = 0;
	
	// Clear timer flags
	CLR_BIT(TIFR, TOV0);
	CLR_BIT(TIFR, OCF0);
	
	// Set the overflow counter to 0
	g_requiredOverflows = 0;
	
	// Set the status
	g_timer0State = TIMER_STOPPED;
}

// =======================================
// Get Timer0 current state.
// =======================================
TIMER_STATE TIMER0_get_state(void)
{
	return g_timer0State;
}