/*
**************************************************************************************************************
*                                                 NXP USB Host Stack
*
*                                     (c) Copyright 2008, NXP SemiConductors
*                                     (c) Copyright 2008, OnChip  Technologies LLC
*                                                 All Rights Reserved
*
*                                                  www.nxp.com
*                                               www.onchiptech.com
*
* File           : usbhost_uart.h
* Programmer(s)  : Prasad.K.R.S.V
* Version        :
*
**************************************************************************************************************
*/

#ifndef USBHOST_UART_H
#define USBHOST_UART_H

/*
**************************************************************************************************************
*                                           INCLUDE HEADER FILES
**************************************************************************************************************
*/

#include <stdarg.h>
#include <stdio.h>
#include "LPC24xx.h"
#include "usbhost_inc.h"

/*
**************************************************************************************************************
*                                             UART DEFINITIONS
**************************************************************************************************************
*/

#define Fcclk	72000000
#define Fp_uartclk_div 1
#define Fp_uartclk	(Fcclk / Fp_uartclk_div)
#define UART_PORT 0
/*
**************************************************************************************************************
*                                             FUNCTION PROTOTYPES
**************************************************************************************************************
*/

void  UART_Init  (      USB_INT32U   baudrate);
void  UART_PrintChar (USB_INT08U ch);
void  UART_PrintStr (USB_INT08U *str);
void  UART_Printf(USB_INT08U  *format, ...);

#endif
