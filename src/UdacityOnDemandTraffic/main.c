/*
 * main.c
 *
 * Created: 10/01/2023 06:01:34 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */

#include "framework.h"
#include "Application/application.h"

int main(void)
{
	APP_init();
	
	// Enable interrupts for the processing.
	sei();
	
    /* Replace with your application code */
    while (1)
    {
		APP_process();
    }
}
