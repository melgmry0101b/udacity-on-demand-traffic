/*
 * button.c
 *
 * Created: 10/01/2023 09:16:14 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "../../MCAL/mcal.h"
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
	// 1. Disable interrupts
	cli();
	
	// 2. Call the callback if set
	if (g_buttonInt0Callback)
	{
		(*g_buttonInt0Callback)();
	}
	
	// 3. Enable interrupts
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
	// 1. Set INT0 pin which is PIN2 on PORTD to input
	DIO_init(PIN_PORT_D, PIN2, PIN_MODE_IN);
	
	// 2. Set the pin to pull down
	DIO_write(PIN_PORT_D, PIN2, PIN_STATUS_LOW);
	
	// 3. Set interrupt mode on INT0 to falling edge -when the button is released-
	// NOTE: we are setting bits individually avoiding modifying other state saved in the register.
	SET_BIT(MCUCR, ISC01);
	CLR_BIT(MCUCR, ISC00);
	
	// 4. Enable INT0
	SET_BIT(GICR, INT0);
}

// =======================================
// Set interrupt callback.
// =======================================
void BUTTON_INT0_set_callback(BUTTON_CALLBACK callback)
{
	// 1. Set the function pointer
	g_buttonInt0Callback = callback;
}