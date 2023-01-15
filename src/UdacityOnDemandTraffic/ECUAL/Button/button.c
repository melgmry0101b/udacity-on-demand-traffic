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
	if (g_buttonInt0Callback)
	{
		(*g_buttonInt0Callback)();
	}
}

/************************************************************************/
/* Buttons methods                                                      */
/************************************************************************/

// =======================================
// Initialize button on INT0.
// =======================================
void BUTTON_INT0_init(void)
{
	// Set interrupt mode on INT0 to falling edge -when the button is released-
	// NOTE: we are `OR`ing with the value of MCUCR avoiding changes on other bits.
	MCUCR |= (1 << ISC01) | (1 << ISC00);
	
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