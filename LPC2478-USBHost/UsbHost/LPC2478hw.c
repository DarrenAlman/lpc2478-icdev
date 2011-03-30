/*
 * LPC2478hw.c
 *
 *  Created on: 2011-2-25
 *      Author: fanghuaqi
 */
#include  "LPC2478hw.h"

void LED_Init(void)
{
	/* P3[20] - p3[27] =>LEDS*/
	PINSEL7 &= 0xff0000ff; /*select P320-P327 as GPIOs*/
	PINSEL7 |= 0x00000000;

	PINMODE7 &= 0xff0000ff;/*select P320 - P327  pull_up*/
	PINMODE7 |= 0x00000000;

	FIO3DIR2 |= 0xf0; /* P320-P327 as output */
	FIO3DIR3 |= 0x0f;
}
void LED_Output(unsigned char ledvalue)
{
	FIO3SET2 = (0xf0 & (ledvalue<<4));
	FIO3SET3 = (0x0f & (ledvalue>>4));

	FIO3CLR2 = (0xf0 & ((~ledvalue)<<4));
	FIO3CLR3 = (0x0f & ((~ledvalue)>>4));
}
void Delay_ms(unsigned long ms)
{
	volatile unsigned long i,j,k;
	for(i=0;i<50;i++)
	{
		for(j=0;j<100;j++)
		{
			for(k=0;k<ms;k++);
		}
	}
}
