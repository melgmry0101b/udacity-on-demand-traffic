/*
 * button.h
 *
 * Created: 10/01/2023 09:16:22 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

/************************************************************************/
/* Types                                                                */
/************************************************************************/

typedef void (*BUTTON_CALLBACK)(void);

/************************************************************************/
/* Buttons methods                                                      */
/************************************************************************/

// =======================================
// Initialize button on INT0.
// =======================================
void BUTTON_INT0_init(void);

// =======================================
// Set interrupt callback.
// =======================================
void BUTTON_INT0_set_callback(BUTTON_CALLBACK callback);

#endif /* BUTTON_H_ */