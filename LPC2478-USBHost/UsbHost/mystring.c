/*
 * mystring.c
 *
 *  Created on: 2011-2-14
 *      Author: Eric Yeh
 */
#include "mystring.h"
void *MemCpy(void *dest, const void *src, unsigned int count)
{
    char *tmp = dest;
    const char *s = src;

    while (count--)
        *tmp++ = *s++;
    return dest;
}
int*  _sbrk(int incr)
{
	extern int _end; /* Defined by the linker */
	static int *heap_end;
	int *prev_heap_end;
	if (heap_end == 0) {
	heap_end = &_end;
	}
	prev_heap_end = heap_end;
	/*if ((heap_end + incr) > (int *)(0xA2000000)) {
		return -1;
	}*/
	heap_end += incr;
	return (int*) prev_heap_end;
	}



