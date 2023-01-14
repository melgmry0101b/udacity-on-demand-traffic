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
void DIO_init(uint8_t port, uint8_t pin, PIN_MODE mode)
{
	switch (mode)
	{
	case PIN_MODE_IN:
		CLR_BIT(port, pin);
		break;
	case PIN_MODE_OUT:
		SET_BIT(port, pin);
		break;
	}
}

// =======================================
// Read pin's status.
// =======================================
PIN_STATUS DIO_read(uint8_t port, uint8_t pin)
{
	return (PIN_STATUS)READ_BIT(port, pin);
}

// =======================================
// Write to pin setting its status.
// =======================================
void DIO_write(uint8_t port, uint8_t pin, PIN_STATUS status)
{
	switch (status)
	{
	case PIN_STATUS_LOW:
		CLR_BIT(port, pin);
		break;
	case PIN_STATUS_HIGH:
		SET_BIT(port, pin);
		break;
	}
}

// =======================================
// Toggle pin's status.
// =======================================
void DIO_toggle(uint8_t port, uint8_t pin)
{
	TOGGLE_BIT(port, pin);
}