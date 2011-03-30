/*
 * mystring.h
 *
 *  Created on: 2011-2-14
 *      Author: Eric Yeh
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include  "usbhost_inc.h"

extern void *MemCpy(void *dest, const void *src, unsigned int count);
extern int*  _sbrk(int incr);
#endif /* MYSTRING_H_ */
