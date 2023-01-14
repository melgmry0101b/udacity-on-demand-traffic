/*
 * framework.h
 *
 * Created: 14/01/2023 02:48:07 PM
 * Author : Mohammed Elghamry <elghamry.connect[at]outlook[dot]com>
 */ 

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#define SET_BIT(X,BIT_NO) ((X) |= (1 << (BIT_NO)))
#define CLR_BIT(X,BIT_NO) ((X) &= ~(1 << (BIT_NO)))
#define READ_BIT(X,BIT_NO) (((X) & (1 << (BIT_NO))) >> (BIT_NO))
#define TOGGLE_BIT(X,BIT_NO) ((X) ^= (1 << (BIT_NO)))

/************************************************************************/
/* Here we include our standard library stuff                           */
/************************************************************************/
#include <stdint.h>

#endif /* FRAMEWORK_H_ */