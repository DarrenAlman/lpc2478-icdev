/**
 * @file   lpc2478_lcd.h
 * @author fanghuaqi <578567190@qq.com>
 * @date   Sun Apr 10 20:42:56 2011
 *
 * @brief  the lm6800 lcd driver
 *
 *
 */

#ifndef  LPC2478_LCD_H
#define  LPC2478_LCD_H

#include "SST89x5xxRD2.H"
#include "INTRINS.H"
#include "monitor.h"
#include <stdarg.h>

typedef  unsigned long   uint32_t;
typedef  signed   long   int32_t;
typedef  unsigned int    uint16_t;
typedef  signed   int    int16_t;
typedef  unsigned char   uint8_t;
typedef  signed   char   int8_t;
typedef  unsigned char   ERCD;

#define	ERCD_OK	    		0
#define ERCD_ARG_ERR		1
#define ERCD_I2C_BUS_ERR	2

sbit RST_PIN = P0^0;
sbit CSA_PIN = P0^1;
sbit CSB_PIN = P0^3;
sbit CSC_PIN = P0^2;
sbit RS_PIN = P0^5;
sbit RW_PIN = P0^6;
sbit E_PIN = P0^4;
/*pin assignment*/
#define LCD_RST RST_PIN
#define LCD_RS RS_PIN
#define LCD_R_W RW_PIN
#define LCD_E E_PIN
#define LCD_CSA CSA_PIN
#define LCD_CSB CSB_PIN
#define LCD_CSC CSC_PIN
#define LCD_DATA_BUS P2

#define LCD_DISPLAY_ON  0x3f
#define LCD_DISPLAY_START_ADDR 0xc0
#define LCD_SET_X_ADDRESS 0xb8
#define LCD_SET_Y_ADDRESS 0x40
#define LCD_CHIP_WIDTH 64
#define LCD_ROWS 64
#define LCD_COLS 256
/*marco operation instruction*/
#define LCD_RST_LOW()     LCD_RST = 0 /*RST:Reset signal high*/
#define LCD_RST_HIGH()    LCD_RST = 1 /*reset signal low*/
#define LCD_RS_HIGH()     LCD_RS = 1  /*RS:data or instruction select signal high*/
#define LCD_RS_LOW()      LCD_RS = 0  /*RS:data or instruction select signal low*/
#define LCD_R_W_HIGH()    LCD_R_W = 1 /*read or write signal high*/
#define LCD_R_W_LOW()     LCD_R_W = 0 /*read or write signal low*/
#define LCD_E_HIGH()      LCD_E = 1   /*Enable signal high*/
#define LCD_E_LOW()       LCD_E = 0   /*Enable signal low*/
#define LCD_E_HIGH_LOW()  {LCD_E_HIGH();_nop_();LCD_E_LOW();} /*E falling edge*/
#define LCD_IN_DATA()     LCD_DATA_BUS /*the lcd data bus*/
#define LCD_OUT_DATA(c)   LCD_DATA_BUS = (c) /*output data on the data bus*/
#define DELAY_US()    {}                   /*delay 1 us*/
#define LCD_CHIP_SEL_0()   {LCD_CSA = 0;LCD_CSB = 0;LCD_CSC=0;} /*select the left-most section*/
#define LCD_CHIP_SEL_1()   {LCD_CSA = 1;LCD_CSB = 0;LCD_CSC=0;} /*select the left-most section*/
#define LCD_CHIP_SEL_2()   {LCD_CSA = 0;LCD_CSB = 1;LCD_CSC=0;} /*select the left-most section*/
#define LCD_CHIP_SEL_3()   {LCD_CSA = 1;LCD_CSB = 1;LCD_CSC=0;} /*select the left-most section*/
#define LCD_CHIP_SEL_OUTPUT()   {LCD_CSA = 1;LCD_CSB = 1;LCD_CSC=1;} /*select the left-most section*/
#define LCD_CHIP_DISABLE_ALL() {LCD_CSC = 1}           /*Disable all the access to the LCD module*/

#define ASC_CODE_START 0
#define ASC_16X16 	2
#define ASC_8X16	1
#define ASC_8X8 	0
#define _LCM_PUT_8X8 1

extern uint16_t gl_curRow;
extern uint16_t gl_curCol ;
extern uint8_t code gl_asckey8X8[];
extern uint8_t code gl_asckey8X16[];
extern uint8_t code gl_asckey16X16[];

/*function declaration*/
ERCD LCD_Init(void);
ERCD LCD_Write_CMD(uint8_t cmdcode);
ERCD LCD_Write_Char(uint8_t char_data);
uint8_t LCD_Read_Char(void);
uint8_t LCD_Read_Status(void);
ERCD LCD_Chip_Select(uint8_t chipsel);
ERCD LCD_Locate(uint16_t row, uint16_t col);
void Delay(uint16_t t);
ERCD LCD_ClrScreen(void);
ERCD LCD_PutDot(uint16_t row, uint16_t col, uint8_t dot_state);
ERCD LCD_PutAsc(uint8_t asc_type,uint8_t asc_code);
ERCD LCD_PutAscStr(uint8_t asc_type,uint8_t *asc_str);
void LCD_PutCode(uint8_t asc_code);

#endif
