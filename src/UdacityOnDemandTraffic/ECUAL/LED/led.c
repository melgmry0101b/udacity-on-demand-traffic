/*
 * led.c
 *
 * Created: 10/01/2023 09:16:06 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "../../MCAL/mcal.h"
#include "../Sleep/sleep.h"
#include "led.h"

/************************************************************************/
/* LED Methods                                                          */
/************************************************************************/

// =======================================
// Initialize a pin for driving LED.
// =======================================
void LED_init(PIN_PORT port, uint8_t pin)
{
	// 1. Initializes the LED pin to OUT
	DIO_init(port, pin, PIN_MODE_OUT);
	// 2. Check the port is low after initialization
	LED_off(port, pin); // Make sure initialized LED is low
}

// =======================================
// Turn LED on.
// =======================================
void LED_on(PIN_PORT port, uint8_t pin)
{
	// 1. Write high on the requested pin
	DIO_write(port, pin, PIN_STATUS_HIGH);	
}

// =======================================
// Turn LED off.
// =======================================
void LED_off(PIN_PORT port, uint8_t pin)
{
	// 1. Write low in the requested pin
	DIO_write(port, pin, PIN_STATUS_LOW);
}

// =======================================
// Toggle LED.
// =======================================
void LED_toggle(PIN_PORT port, uint8_t pin)
{
	// 1. Toggle the requested pin
	DIO_toggle(port, pin);
}

// =======================================
// Blink LED.
// =======================================
void LED_blink(PIN_PORT port, uint8_t pin, uint16_t cycle_ms, uint16_t cycles, LED_BLINK_CANCELLATION_CALLBACK cancellationCallback)
{
	// I developed this method to be used for interrupting a blinking LEDs if needed,
	//	but wasn't suitable for multiple blinking LEDs. It is not used, but left it
	//	here for the sake of completeness.
	
	// 1. Do nothing if cycles or cycle_ms is 0
	if (cycles == 0) { return; }
	if (cycle_ms == 0) { return; }
	
	while (cycles-- > 0)
	{
		// 2. Check if cancellation requested.
		if (cancellationCallback && (*cancellationCallback)()) { break; }
		
		// 3. Toggle the LED
		LED_toggle(port, pin);
		// 4. Sleep between toggles
		sleep(cycle_ms);	
	}
}
