/*
 * led.h
 *
 * Created: 10/01/2023 09:15:58 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef LED_H_
#define LED_H_

/************************************************************************/
/* LED Methods                                                          */
/************************************************************************/

// =======================================
// Initialize a pin for driving LED.
// =======================================
void LED_init(PIN_PORT port, uint8_t pin);

// =======================================
// Turn LED on.
// =======================================
void LED_on(PIN_PORT port, uint8_t pin);

// =======================================
// Turn LED off.
// =======================================
void LED_off(PIN_PORT port, uint8_t pin);

// =======================================
// Toggle LED.
// =======================================
void LED_toggle(PIN_PORT port, uint8_t pin);

// =======================================
// Blink LED.
// =======================================
void LED_blink(PIN_PORT port, uint8_t pin, uint16_t cycle_ms, uint16_t cycles);

#endif /* LED_H_ */