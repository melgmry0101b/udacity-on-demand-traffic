/*
 * main.c
 *
 * Created: 10/01/2023 06:01:34 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */

#include "framework.h"
#include "Application/application.h"

#ifndef TEST_MODE

int main(void)
{
	// 1. Initialize application
	APP_init();
	
	// 2. Enable interrupts
	sei();
	
    // 3. Enter the application loop
    while (1)
    {
		// 4. Call application processing
		APP_process();
    }
}

#endif // TEST_MODE
