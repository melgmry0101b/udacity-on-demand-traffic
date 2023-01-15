/*
 * dio.h
 *
 * Created: 10/01/2023 09:09:45 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef DIO_H_
#define DIO_H_

/************************************************************************/
/* Types                                                                */
/************************************************************************/

typedef enum _PIN_MODE
{
	PIN_MODE_IN,
	PIN_MODE_OUT
} PIN_MODE;

typedef enum _PIN_STATUS
{
	PIN_STATUS_LOW,
	PIN_STATUS_HIGH
} PIN_STATUS;

typedef enum _PIN_PORT
{
	PIN_PORT_A,
	PIN_PORT_B,
	PIN_PORT_C,
	PIN_PORT_D
} PIN_PORT;

/************************************************************************/
/* DIO Methods                                                          */
/************************************************************************/

// =======================================
// Initialize a pin setting its mode.
// =======================================
void DIO_init(PIN_PORT port, uint8_t pin, PIN_MODE mode);

// =======================================
// Read pin's status.
// =======================================
PIN_STATUS DIO_read(PIN_PORT port, uint8_t pin);

// =======================================
// Write to pin setting its status.
// =======================================
void DIO_write(PIN_PORT port, uint8_t pin, PIN_STATUS status);

// =======================================
// Toggle pin's status.
// =======================================
void DIO_toggle(PIN_PORT port, uint8_t pin);

#endif /* DIO_H_ */