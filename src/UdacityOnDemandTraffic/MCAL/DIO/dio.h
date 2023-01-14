/*
 * dio.h
 *
 * Created: 10/01/2023 09:09:45 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef DIO_H_
#define DIO_H_

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

/************************************************************************/
/* DIO Methods                                                          */
/************************************************************************/

// =======================================
// Initialize a pin setting its mode.
// =======================================
void DIO_init(uint8_t port, uint8_t pin, PIN_MODE mode);

// =======================================
// Read pin's status.
// =======================================
PIN_STATUS DIO_read(uint8_t port, uint8_t pin);

// =======================================
// Write to pin setting its status.
// =======================================
void DIO_write(uint8_t port, uint8_t pin, PIN_STATUS status);

// =======================================
// Toggle pin's status.
// =======================================
void DIO_toggle(uint8_t port, uint8_t pin);

#endif /* DIO_H_ */