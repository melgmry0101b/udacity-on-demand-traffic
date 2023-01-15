/*
 * button.c
 *
 * Created: 10/01/2023 09:16:14 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "button.h"

/************************************************************************/
/* Globals                                                              */
/************************************************************************/

static BUTTON_CALLBACK g_buttonInt0Callback = NULL;

/************************************************************************/
/* ISR                                                                  */
/************************************************************************/

ISR(INT0_vect)
{
	// Disable interrupts
	cli();
	
	if (g_buttonInt0Callback)
	{
		(*g_buttonInt0Callback)();
	}
	
	// Enable interrupts
	sei();
}

/************************************************************************/
/* Buttons methods                                                      */
/************************************************************************/

// =======================================
// Initialize button on INT0.
// =======================================
void BUTTON_INT0_init(void)
{
	// Set INT0 pin which is PIN2 on PORTD to input
	DIO_init(PIN_PORT_D, PIN2, PIN_MODE_IN);
	
	// Set the pin to pull down
	DIO_write(PIN_PORT_D, PIN2, PIN_STATUS_LOW);
	
	// Set interrupt mode on INT0 to falling edge -when the button is released-
	// NOTE: we are setting bits individually avoiding modifying other state saved in the register.
	SET_BIT(MCUCR, ISC01);
	CLR_BIT(MCUCR, ISC00);
	
	// Enable INT0
	SET_BIT(GICR, INT0);
}

// =======================================
// Set interrupt callback.
// =======================================
void BUTTON_INT0_set_callback(BUTTON_CALLBACK callback)
{
	g_buttonInt0Callback = callback;
}