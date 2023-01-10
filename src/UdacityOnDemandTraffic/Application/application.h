/*
 * application.h
 *
 * Created: 10/01/2023 09:12:29 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_

#define SET_BIT(X,BIT_NO) ((X) |= (1 << (BIT_NO)))
#define CLR_BIT(X,BIT_NO) ((X) &= ~(1 << (BIT_NO)))
#define READ_BIT(X,BIT_NO) (((X) & (1 << (BIT_NO))) >> (BIT_NO))
#define TOGGLE_BIT(X,BIT_NO) ((X) ^= (1 << (BIT_NO)))

/************************************************************************/
/* Including "Electronic Unit Abstraction Layer"                        */
/************************************************************************/
#include "../ECUAL/ecual.h"

#endif /* APPLICATION_H_ */