/*
 * application.h
 *
 * Created: 10/01/2023 09:12:29 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

// Cars LEDs
#define LED_CARS_PORT		PORTA
#define LED_CARS_GREEN_PIN	PIN0
#define LED_CARS_YELLOW_PIN PIN1
#define LED_CARS_RED_PIN	PIN2

// Pedestrians LEDs
#define LED_PEDS_PORT PORTB
#define LED_PEDS_GREEN_PIN	PIN0
#define LED_PEDS_YELLOW_PIN PIN1
#define LED_PEDS_RED_PIN	PIN2

/************************************************************************/
/* Application Methods                                                  */
/************************************************************************/

// =======================================
// Initializes the application.
// =======================================
void APP_init(void);

// =======================================
// Called within the main loop.
// =======================================
void APP_process(void);

#endif /* APPLICATION_H_ */