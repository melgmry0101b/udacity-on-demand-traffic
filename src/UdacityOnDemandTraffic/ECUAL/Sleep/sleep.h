/*
 * sleep.h
 *
 * Created: 10/01/2023 09:13:49 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef SLEEP_H_
#define SLEEP_H_

/************************************************************************/
/* Sleep methods                                                        */
/************************************************************************/

// =======================================
// Initialize sleep for usage.
// =======================================
void sleep_init(void);

// =======================================
// Sleep for ms.
// NOTE: interrupts has to be enabled!
// =======================================
void sleep(uint16_t ms);

#endif /* SLEEP_H_ */