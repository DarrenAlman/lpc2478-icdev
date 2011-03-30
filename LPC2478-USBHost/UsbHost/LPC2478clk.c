/*
**************************************************************************************************************
*                                           LPC2478 Clock initialize
*
* File           : LPC2478clk.h
* Programmer(s)  : fanghuaqi
* Version        : 1.0
*
**************************************************************************************************************
*/


/*
**************************************************************************************************************
*                                       INCLUDE HEADER FILES
**************************************************************************************************************
*/

#include  "LPC2478clk.h"

static void PLL_Feed(void)
{
	/* A correct feed sequence must be written to the PLLFEED register in order for changes to the PLLCON and PLLCFG registers to take effect */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;
}
void PLL_Init(void)
{
	PLLCON = 0x00;/* Disconnect the PLL with one feed sequence if PLL is already connected.*/
	PLL_Feed(); /* Disable the PLL with one feed sequence. */
	CCLKCFG = 0x00; /* Change the CPU Clock Divider setting to speed up operation without the PLL */

	// Setting Multiplier and Divider values
	/*Target clock set at max 72MHz refer to cpu feather */ /*IRC Internal RC oscillator*/
	CLKSRCSEL = 0x01;/* Selects the main oscillator as the PLL clock source. The precision of the IRC does not allow for use of the USB interface, */
  	PLLCFG = 0x0B;    /* Write to the PLLCFG and make it effective with one feed sequence */    /* M=12 N=1 PLLCLK=288MHz*/
  	PLL_Feed();

	PLLCON = 0x1; /* Enable the PLL with one feed sequence. */
	PLL_Feed();
	Delay_ms(5);
	CCLKCFG = 0x03; /*  Change the CPU Clock Divider setting for the operation with the PLL. It's critical to do this before connecting the PLL. */
	USBClk_Init(); /*set the usb clk to 48Mhz*/
	//here better delay >=500us to wait the PLOCK stable

	// Wait for the PLL to lock to set frequency
	while(!(PLLSTAT & 0x04000000)) ; /* Wait for the PLL to achieve lock by monitoring the PLOCK bit in the PLLSTAT register */

	PLLCON = 0x3; /*Connect the PLL with one feed sequence.*/
	PLL_Feed();
	while(!(PLLSTAT & 0x02000000)) ;/*wait until the pll is connected*/

	/*Setting  System Clock block PCLK_SYSCON =0x01 so sclk=cclk*/
	PCLKSEL1 &= 0xcfffffff;
	PCLKSEL1 |= 0x10000000;
}

void USBClk_Init(void)
{
	/*When the PLL is running, the output must be divided in order to bring the USB clock frequency to 48 MHz with a 50% duty cycle.*/
	USBCLKCFG = 0x05; /*PLLClk/6=48Mhz*/
}


