/*
 * main.c
 *
 * Created: 10/01/2023 06:01:34 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */

#include "framework.h"
#include "Application/application.h"

// #define TEST_MODE

#ifndef TEST_MODE

int main(void)
{
	APP_init();
	
	// Enable interrupts for the processing.
	sei();
	
    /* Replace with your application code */
    while (1)
    {
		APP_process();
    }
}

#else

// These are our testing methods.

void ButtonPressTestHandler(void)
{
	LED_toggle(PIN_PORT_A, PIN0);
}

int main(void)
{
	// Enable interrupts
	sei();
	
	// 1. Test timer through sleep
	// After sleep_init, TIMSK:TOIE0(0) should be set.
	sleep_init();
	// After this sleep, the watchdog timer should increase by 1,000,000.
	sleep(1000); // 1s = 1,000,000 microsec
	
	// 2. Test DIO through LED
	// After this, DDRA:0 should be set.
	LED_init(PIN_PORT_A, PIN0);
	// After this, PORTA:0 should be set.	
	LED_on(PIN_PORT_A, PIN0);
	// After this, PORTA:0 should be cleared.
	LED_off(PIN_PORT_A, PIN0);

	// 3. Test button
	// Here we should see:
	//	DDRD:2 => cleared
	//	PORTD:2 => cleared
	//	MCUCR:ISC00(0) => cleared, MCUCR:ISC01(1) => set
	//  GICR:INT0(6) => cleared
	BUTTON_INT0_init();
	// Set the callback
	BUTTON_INT0_set_callback(&ButtonPressTestHandler);
	// Now, on the falling edge (button up), we should jump into the `ButtonPressTestHandler`
	
	while (1);
}

#endif // TEST_MODE
