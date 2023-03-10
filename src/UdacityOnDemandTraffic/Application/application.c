/*
 * application.c
 *
 * Created: 10/01/2023 09:12:41 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#include "../framework.h"
#include "../ECUAL/ecual.h"
#include "application.h"

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

#define SLEEP_CYCLES_TOP		20
#define SLEEP_CYCLE_DURATION	250

#define APP_STATE_GREEN_CARS					0
#define APP_STATE_YELLOW_MOVING_TO_RED_CARS		1
#define APP_STATE_RED_CARS						2
#define APP_STATE_YELLOW_MOVING_TO_GREEN_CARS	3

typedef enum _PEDS_MODE
{
	PEDS_MODE_DISABLED,     // The application is running in normal mode
	PEDS_MODE_REQUESTED,    // Pedestrians mode requested
	PEDS_MODE_HANDLED		// Pedestrians mode handled
} PEDS_MODE;

/************************************************************************/
/* Globals                                                              */
/************************************************************************/

// Global private variable tells the state of the application.
//	0: Green for cars, Red for pedestrians
//	1: Blinking Yellow for cars and pedestrians
//	2: Red for card, Green for pedestrians
//  3: Blinking Yellow for cars and pedestrians
static uint8_t g_appState = APP_STATE_GREEN_CARS;

// Global private variable that indicates if the application entered pedestrian mode.
static PEDS_MODE g_pedestrianMode = PEDS_MODE_DISABLED;

/************************************************************************/
/* Pedestrian Button Handler                                            */
/************************************************************************/

void PedestrianButtonHandler(void)
{
	// 1. set the pedestrian mode flag
	if (g_pedestrianMode == PEDS_MODE_DISABLED)
	{
		g_pedestrianMode = PEDS_MODE_REQUESTED;
	}
}

/************************************************************************/
/* Private methods                                                      */
/************************************************************************/

static void TurnAllLedsOff(void)
{
	// 1. Turn all LEDs off.
	
	LED_off(LED_CARS_PORT, LED_CARS_GREEN_PIN);
	LED_off(LED_CARS_PORT, LED_CARS_YELLOW_PIN);
	LED_off(LED_CARS_PORT, LED_CARS_RED_PIN);
	
	LED_off(LED_PEDS_PORT, LED_PEDS_GREEN_PIN);
	LED_off(LED_PEDS_PORT, LED_PEDS_YELLOW_PIN);
	LED_off(LED_PEDS_PORT, LED_PEDS_RED_PIN);
}

/************************************************************************/
/* Application Methods                                                  */
/************************************************************************/

// =======================================
// Initializes the application.
// =======================================
void APP_init(void)
{
	// 1. Initialize sleep
	sleep_init();
	
	// 2. Initialize pedestrian button
	BUTTON_INT0_init();
	
	// 3. Set the button interrupt callback
	BUTTON_INT0_set_callback(&PedestrianButtonHandler);
	
	// 4. Initialize LEDs
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
	uint8_t sleepCycles;
	
	TurnAllLedsOff();

	sleepCycles = SLEEP_CYCLES_TOP;
	
	// 1. If we are in pedestrian mode, don't change the state, the logic in switch will handle that
	if (g_pedestrianMode == PEDS_MODE_DISABLED)
	{
		// 2. Go to the next state
		if (++g_appState > APP_STATE_YELLOW_MOVING_TO_GREEN_CARS) { g_appState = APP_STATE_GREEN_CARS; }
	}

	// 3. Reset pedestrian mode if it has been handled
	if (g_pedestrianMode == PEDS_MODE_HANDLED)
	{
		g_pedestrianMode = PEDS_MODE_DISABLED;
	}
	
	switch (g_appState)
	{
	case APP_STATE_GREEN_CARS: // 4. Green for cars, Red for pedestrians
		// 5. set the cars to green and pedestrians to red.
		LED_on(LED_CARS_PORT, LED_CARS_GREEN_PIN);
		LED_on(LED_PEDS_PORT, LED_PEDS_RED_PIN);
		// 5 seconds sleep = sleepCycles * SLEEP_CYCLE_DURATION.
		while (sleepCycles-- > 0)
		{
			sleep(SLEEP_CYCLE_DURATION);
			
			// 6. Check if pedestrian mode has been requested
			if (g_pedestrianMode == PEDS_MODE_REQUESTED)
			{
				g_pedestrianMode = PEDS_MODE_HANDLED;
				g_appState = APP_STATE_YELLOW_MOVING_TO_RED_CARS; // Set the next app state to be yellow moving to red
				break;
			}
		}
		// Set next state
		break;
	case APP_STATE_YELLOW_MOVING_TO_RED_CARS: // 7. Blinking Yellow for cars and pedestrians
	case APP_STATE_YELLOW_MOVING_TO_GREEN_CARS:
		while (sleepCycles-- > 0)
		{
			// 8. Toggle the yellow LEDs for both sides every 250 ms as blinking
			LED_toggle(LED_CARS_PORT, LED_CARS_YELLOW_PIN);
			LED_toggle(LED_PEDS_PORT, LED_PEDS_YELLOW_PIN);
			sleep(SLEEP_CYCLE_DURATION);
			
			// 9. If requested during yellow, reset and move back to red
			if (g_pedestrianMode == PEDS_MODE_REQUESTED)
			{
				g_pedestrianMode = PEDS_MODE_HANDLED;
				g_appState = APP_STATE_RED_CARS; // Set the next app state to be red for cars
				sleepCycles = SLEEP_CYCLES_TOP;
			}
		}
		break;
	case APP_STATE_RED_CARS: // 10. Red for card, Green for pedestrians
		// 11. Set red for cars and green for pedestrians.
		LED_on(LED_CARS_PORT, LED_CARS_RED_PIN);
		LED_on(LED_PEDS_PORT, LED_PEDS_GREEN_PIN);
		// 5 seconds sleep.
		while (sleepCycles-- > 0)
		{
			sleep(SLEEP_CYCLE_DURATION);
			
			// 12. Check if we entered pedestrian mode while the car red is on, reset the 5 seconds
			if (g_pedestrianMode == PEDS_MODE_REQUESTED)
			{
				g_pedestrianMode = PEDS_MODE_HANDLED;
				g_appState = APP_STATE_YELLOW_MOVING_TO_GREEN_CARS; // Set the next app state
				sleepCycles = SLEEP_CYCLES_TOP;
			}
		}
		break;
	}
}