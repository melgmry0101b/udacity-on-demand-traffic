/*
 * led.c
 *
 * Created: 10/01/2023 09:16:06 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "led.h"

/************************************************************************/
/* LED Methods                                                          */
/************************************************************************/

// =======================================
// Initialize a pin for driving LED.
// =======================================
void LED_init(PIN_PORT port, uint8_t pin)
{
	DIO_init(port, pin, PIN_MODE_OUT);
}

// =======================================
// Turn LED on.
// =======================================
void LED_on(PIN_PORT port, uint8_t pin)
{
	DIO_write(port, pin, PIN_STATUS_HIGH);	
}

// =======================================
// Turn LED off.
// =======================================
void LED_off(PIN_PORT port, uint8_t pin)
{
	DIO_write(port, pin, PIN_STATUS_LOW);
}

// =======================================
// Toggle LED.
// =======================================
void LED_toggle(PIN_PORT port, uint8_t pin)
{
	DIO_toggle(port, pin);
}

// =======================================
// Blink LED.
// =======================================
void LED_blink(PIN_PORT port, uint8_t pin, uint16_t cycle_ms, uint16_t cycles, LED_BLINK_CANCELLATION_CALLBACK cancellationCallback)
{
	if (cycles == 0) { return; }
	if (cycle_ms == 0) { return; }
	
	while (cycles-- > 0)
	{
		// Check if cancellation requested.
		if (cancellationCallback && (*cancellationCallback)()) { break; }
		
		LED_toggle(port, pin);
		sleep(cycle_ms);	
	}
}
