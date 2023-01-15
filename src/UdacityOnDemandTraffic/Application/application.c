/*
 * application.c
 *
 * Created: 10/01/2023 09:12:41 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../framework.h"
#include "application.h"

/************************************************************************/
/* Globals                                                              */
/************************************************************************/

/************************************************************************/
/* Pedestrian Button Handler                                            */
/************************************************************************/

void PedestrianButtonHandler(void)
{
	
}

/************************************************************************/
/* Yellow LED Blink Cancellation Checker                                */
/************************************************************************/

bool YellowLedCancellationCheckHandler(void)
{
	return false;
}

/************************************************************************/
/* Application Methods                                                  */
/************************************************************************/

// =======================================
// Initializes the application.
// =======================================
void APP_init(void)
{
	// Initialize sleep
	sleep_init();
	
	// Initialize pedestrian button
	BUTTON_INT0_init();
	
	// Set the button interrupt callback
	BUTTON_INT0_set_callback(&PedestrianButtonHandler);
	
	// Initialize LEDs
	LED_init(LED_CARS_PORT, LED_CARS_GREEN_PIN);
	LED_init(LED_CARS_PORT, LED_CARS_YELLOW_PIN);
	LED_init(LED_CARS_PORT, LED_CARS_RED_PIN);
	
	LED_init(LED_PEDS_PORT, LED_PEDS_GREEN_PIN);
	LED_init(LED_PEDS_PORT, LED_PEDS_YELLOW_PIN);
	LED_init(LED_PEDS_PORT, LED_PEDS_RED_PIN);
}

// =======================================
// Called within the main loop.
// =======================================
void APP_process(void)
{
	
}