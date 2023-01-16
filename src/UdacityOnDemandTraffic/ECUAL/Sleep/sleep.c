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
	// 1. Initialize the timer.
	TIMER0_init();
}

// =======================================
// Sleep for ms.
// NOTE: interrupts has to be enabled!
// =======================================
void sleep(uint16_t ms)
{
	// 1. Do nothing if the requested interval is 0
	if (ms == 0) { return; }
	
	// 2. Set the wait period
	TIMER0_set(ms);
	
	// 3. Start the timer
	TIMER0_start();
	
	// 4 .Set `Sleep Enable`
	sleep_enable();
	
	// 5. Set sleep mode to idle
	set_sleep_mode(SLEEP_MODE_IDLE);
	
	// 6. Check timer state, and idle between interrupts
	while (TIMER0_get_state() == TIMER_RUNNING)
	{
		//7.  Enter idle mode
		sleep_cpu();
	}
	
	// 8. Clear `Sleep Enable`
	sleep_disable();
}