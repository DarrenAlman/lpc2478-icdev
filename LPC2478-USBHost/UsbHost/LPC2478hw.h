/*
 * LPC2478hw.h
 *
 *  Created on: 2011-2-25
 *      Author: fanghuaqi
 */

#ifndef LPC2478HW_H_
#define LPC2478HW_H_

#include  "usbhost_inc.h"

void LED_Init(void);
void LED_Output(unsigned char ledvalue);
void Delay_ms(unsigned long ms);
#endif /* LPC2478HW_H_ */
