/*
 * sleep.c
 *
 * Created: 10/01/2023 09:13:38 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "sleep.h"

// =======================================
// Initialize sleep for usage.
// =======================================
void sleep_init(void)
{
	TIMER0_init();
}

// =======================================
// Sleep for ms.
// NOTE: interrupts has to be enabled!
// =======================================
void sleep(uint16_t ms)
{
	if (ms == 0) { return; }
	
	// Set the wait period
	TIMER0_set(ms);
	
	// Start the timer
	TIMER0_start();
	
	// Set `Sleep Enable`
	sleep_enable();
	
	// Set sleep mode to idle
	set_sleep_mode(SLEEP_MODE_IDLE);
	
	// Check timer state, and idle between interrupts
	while (TIMER0_get_state() == TIMER_RUNNING)
	{
		// Enter idle mode
		sleep_cpu();
	}
	
	// Clear `Sleep Enable`
	sleep_disable();
}