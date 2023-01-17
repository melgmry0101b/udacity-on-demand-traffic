/*
 * main.c
 *
 * Created: 17/01/2023 02:27:48 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "framework.h"
#include "MCAL/mcal.h"
#include "ECUAL/ecual.h"

#ifdef TEST_MODE

// =======================================
// Callback for button press.
// =======================================
void ButtonPressTestHandler(void)
{
	LED_toggle(PIN_PORT_A, PIN0);
}

/************************************************************************/
/* Test Methods                                                         */
/************************************************************************/

// =======================================
// Test DIO.
// =======================================
void TestDIO(void)
{
	// 1. Initialize a pin as output
	// Expected: DDRB:0 => Set
	DIO_init(PIN_PORT_B, PIN0, PIN_MODE_OUT);
	
	// 2. Write high to initialized port
	// Expected: PORTB:0 => Set
	DIO_write(PIN_PORT_B, PIN0, PIN_STATUS_HIGH);
	
	// 3. Write low to initialized port
	// Expected: PORTB:0 => Cleared
	DIO_write(PIN_PORT_B, PIN0, PIN_STATUS_LOW);
	
	// 4. Toggle initialized port
	// Expected: PORTB:0 => Set
	DIO_toggle(PIN_PORT_B, PIN0);
	
	// 5. Toggle initialized port again
	// Expected: PORTB:0 => Cleared
	DIO_toggle(PIN_PORT_B, PIN0);
	
	// 6. Initialize port as input
	// Expected: DDRB:0 => Cleared
	DIO_init(PIN_PORT_B, PIN0, PIN_MODE_IN);
	
	// 7. Read from the initialized port
	// Expected: exits loop on PINB:0 => set
	while (DIO_read(PIN_PORT_B, PIN0) != PIN_STATUS_HIGH);
}

// =======================================
// Test timer.
// =======================================
void TestTimer(void)
{
	// 1. Initialize Timer0
	// Expected: TIMSK:TOIE(0) => Set
	TIMER0_init();
	
	// 2. Set the timer to 250ms
	// Expected: Stopwatch increases by 250,000 microsec after the wait
	TIMER0_set(250);
	TIMER0_start();
	while (TIMER0_get_state() == TIMER_RUNNING);
	
	// 3. Set the timer to 1000ms
	// Expected: Stopwatch increases by 1,000,000 microsec after the wait
	TIMER0_set(1000);
	TIMER0_start();
	while (TIMER0_get_state() == TIMER_RUNNING);
}

// =======================================
// Test LED.
// =======================================
void TestLED(void)
{
	// 1. Initialize LED pin
	// Expected: DDRA:0 => Set
	LED_init(PIN_PORT_A, PIN0);
	
	// 2. Set the LED to on
	// Expected: PORTA:0 => Set
	LED_on(PIN_PORT_A, PIN0);
	
	// 3. Set the LED to off
	// Expected: PORTA:0 => Cleared
	LED_off(PIN_PORT_A, PIN0);
	
	// 4. Toggle LED
	// Expected: PORTA:0 => Set
	LED_toggle(PIN_PORT_A, PIN0);
	
	// 5. Toggle LED again
	// Expected: PORTA:0 => Cleared
	LED_toggle(PIN_PORT_A, PIN0);
}

// =======================================
// Test sleep.
// =======================================
void TestSleep(void)
{
	// 1. Sleep for 1000ms
	// Expected: Stopwatch increases by 1,000,000 microsec
	sleep_init();
	sleep(1000);
}

// =======================================
// Test Button.
// =======================================
void TestButton(void)
{
	// 1. Initialize button on INT0
	// Expected:
	//	DDRD:2 => Cleared
	//	PORTD:2 => Cleared
	//	MCUCR:ISC00(0) => Cleared, MCUCR:ISC01(1) => Set
	//  GICR:INT0(6) => Set
	BUTTON_INT0_init();
	
	// 2. Set the callback
	// Expected: The callback should be invoked on falling edge, toggling LED on PORTA:0
	BUTTON_INT0_set_callback(&ButtonPressTestHandler);
}

/************************************************************************/
/* Main Test Function                                                   */
/************************************************************************/

int main(void)
{
	// 0. Enable interrupts
	sei();
	
	// 1. Test DIO
	TestDIO();
	
	// 2. Test Timer
	TestTimer();
	
	// 3.Test LED
	TestLED();
	
	// 4. Test Sleep
	TestSleep();
	
	// 5. Test Button
	TestButton();
	
	while (1);
}

#endif // TEST_MODE