/*
 * dio.c
 *
 * Created: 10/01/2023 09:09:57 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../../framework.h"
#include "dio.h"

// =======================================
// Initialize a pin setting its mode.
// =======================================
void DIO_init(PIN_PORT port, uint8_t pin, PIN_MODE mode)
{
	switch (port)
	{
	case PIN_PORT_A:
		if (mode == PIN_MODE_IN) { CLR_BIT(DDRA, pin); } else { SET_BIT(DDRA, pin); }
		break;
	case PIN_PORT_B:
		if (mode == PIN_MODE_IN) { CLR_BIT(DDRB, pin); } else { SET_BIT(DDRB, pin); }
		break;
	case PIN_PORT_C:
		if (mode == PIN_MODE_IN) { CLR_BIT(DDRC, pin); } else { SET_BIT(DDRC, pin); }
		break;
	case PIN_PORT_D:
		if (mode == PIN_MODE_IN) { CLR_BIT(DDRD, pin); } else { SET_BIT(DDRD, pin); }
		break;
	}
}

// =======================================
// Read pin's status.
// =======================================
PIN_STATUS DIO_read(PIN_PORT port, uint8_t pin)
{
	switch (port)
	{
	case PIN_PORT_A:
		return (PIN_STATUS)READ_BIT(PINA, pin);
	case PIN_PORT_B:
		return (PIN_STATUS)READ_BIT(PINB, pin);
	case PIN_PORT_C:
		return (PIN_STATUS)READ_BIT(PINC, pin);
	case PIN_PORT_D:
		return (PIN_STATUS)READ_BIT(PIND, pin);
	}
	
	// Avoiding warning for falling out of function with no return.
	return PIN_STATUS_LOW;
}

// =======================================
// Write to pin setting its status.
// =======================================
void DIO_write(PIN_PORT port, uint8_t pin, PIN_STATUS status)
{
	switch (port)
	{
	case PIN_PORT_A:
		if (status == PIN_STATUS_LOW) { CLR_BIT(PORTA, pin); } else { SET_BIT(PORTA, pin); }
		break;
	case PIN_PORT_B:
		if (status == PIN_STATUS_LOW) { CLR_BIT(PORTB, pin); } else { SET_BIT(PORTB, pin); }
		break;
	case PIN_PORT_C:
		if (status == PIN_STATUS_LOW) { CLR_BIT(PORTC, pin); } else { SET_BIT(PORTC, pin); }
		break;
	case PIN_PORT_D:
		if (status == PIN_STATUS_LOW) { CLR_BIT(PORTD, pin); } else { SET_BIT(PORTD, pin); }
		break;
	}
}

// =======================================
// Toggle pin's status.
// =======================================
void DIO_toggle(PIN_PORT port, uint8_t pin)
{
	switch (port)
	{
	case PIN_PORT_A:
		TOGGLE_BIT(PORTA, pin);
		break;
	case PIN_PORT_B:
		TOGGLE_BIT(PORTB, pin);
		break;
	case PIN_PORT_C:
		TOGGLE_BIT(PORTC, pin);
		break;
	case PIN_PORT_D:
		TOGGLE_BIT(PORTD, pin);
		break;
	}
}