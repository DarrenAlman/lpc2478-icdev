/**
 * @file   lpc2478_lcd.c
 * @author fanghuaqi <578567190@qq.com>
 * @date   Sun Apr 10 20:44:12 2011
 * 
 * @brief  lm6800 lcd driver for lpc2478
 * 
 * 
 */

#include "lpc2478_lcd.h"

uint16_t gl_curRow = 0;
uint16_t gl_curCol = 0;

/** 
 * 
 * 
 * 
 * @return 
 */
ERCD LCD_Init(void)
{
    uint8_t i ;
    LCD_RST_LOW();                  /*RST must keep low at least 1us then go high*/
    Delay(100);
    LCD_RST_HIGH();
    Delay(10);
    for (i = 0; i < 4; i++){
        LCD_Chip_Select(i);
        LCD_Write_CMD(LCD_DISPLAY_ON);/*Display on*/
        LCD_Write_CMD(LCD_DISPLAY_START_ADDR|0x0);/*display startline register 0*/
    }
    return ERCD_OK;
}
/** 
 * 
 * 
 * @param cmdcode 
 * 
 * @return 
 */
ERCD LCD_Write_CMD(uint8_t cmdcode)
{
    while(LCD_Read_Status() & 0x90);
	
	LCD_RS_LOW();                   /*when RS=0 R/W=0,cmd write the data bus*/
    LCD_R_W_LOW();
    LCD_OUT_DATA(cmdcode);          /*output cmd  on the bus*/
    LCD_E_HIGH_LOW();               /*when E high->low data appear on the bus*/
    return ERCD_OK;
}
/** 
 * 
 * 
 * @param char_data 
 * 
 * @return 
 */
ERCD LCD_Write_Char(uint8_t char_data)
{
    while(LCD_Read_Status() & 0x90);
	//LCD_E_LOW();
	LCD_RS_HIGH();                  /*when RS=1 R/W=0,cmd write the data bus*/
    LCD_R_W_LOW();
    LCD_OUT_DATA(char_data);        /*output data on the bus*/
    LCD_E_HIGH_LOW();               /*when E high->low(falling edge) data appear on the bus*/
    return ERCD_OK;
}
/** 
 * 
 * 
 * 
 * @return 
 */
uint8_t LCD_Read_Char(void)
{
    uint8_t data_read;
    /*when read data ,a dummy read is needed*/
    LCD_RS_HIGH();                   /*when RS=1 R/W=1,read data from the displayram*/
    LCD_R_W_HIGH();
	LCD_E_HIGH();                    /*when E=1 and device is selected data appear*/
    data_read = LCD_IN_DATA();       /*in data on the bus*/
    LCD_E_LOW(); 
    return data_read;				 /*must pull low here*/
}
/** 
 * 
 * 
 * 
 * @return 
 */
uint8_t LCD_Read_Status(void)
{
    uint8_t status;
    /*when read status ,a dummy read is not needed*/
	//LCD_OUT_DATA(0xff);
    LCD_RS_LOW();                  /*when RS=0 R/W=1,read status ofthe l*/
    LCD_R_W_HIGH();
	LCD_E_HIGH();                   /*when E=1 and device is selecte dat ppear*/
    status= LCD_IN_DATA();         /*n data on the bus*/    
	LCD_E_LOW();    			/*must pull low here*/
    return status;
}
/** 
  
  * 
  * param cipsel 
  * 
  * @return 
  */
ERCD LCD_Chip_Select(uint8_t chipsel)
{
    if (chipsel > 3){
        return ERCD_ARG_ERR;
    }
	//LCD_CHIP_SEL_OUTPUT();
	//Delay(1);
    switch (chipsel){
        case 0:
            LCD_CHIP_SEL_0();
            break;
        case 1:
            LCD_CHIP_SEL_1();
            break;
        case 2:
            LCD_CHIP_SEL_2();
            break;
        case 3:
            LCD_CHIP_SEL_3();
            break;
        default:
            break;
    }
	//Delay(1);
    return ERCD_OK;
}
/* 
* 
* 
* @ara row 
 * @param col 
 * 
 * @return 
 */
ERCD LCD_Locate(uint16_t row, uint16_t col)
{
    uint8_t chipsel = 0;
	gl_curRow = row;
	gl_curCol = col;
    if ( (col < LCD_COLS) && (row < LCD_ROWS) ){ /*check if the row and col is over range */
        chipsel = col / LCD_CHIP_WIDTH;
        LCD_Chip_Select(chipsel);
    } else {
        return ERCD_ARG_ERR;
    }
    LCD_Write_CMD(LCD_SET_X_ADDRESS|(row>>3)); /*Page address*/
    LCD_Write_CMD(LCD_SET_Y_ADDRESS|(col%LCD_CHIP_WIDTH));
    return ERCD_OK;
}


/*-----------------------------------------------------------------------*/
/* Put a character                                                       */
/*-----------------------------------------------------------------------*/



ERCD LCD_PutDot(uint16_t row, uint16_t col, uint8_t dot_state)
{
	
	uint8_t ram;
	LCD_Locate(row,col);
	ram = LCD_Read_Char();
	ram = LCD_Read_Char();
	ram = (ram & (~(1<<(row%8)))) | (dot_state<<(row%8));
    LCD_Write_Char(ram);
}

ERCD LCD_ClrScreen(void)
{
	uint16_t i ,j, k;
	for(k=0;k<4;k++)
	{
		LCD_Chip_Select(k);
		//芯片选择
		for(j=0;j<8;j++)
		{
			LCD_Write_CMD(0xb8+j);
			//页地址设置
			LCD_Write_CMD(0x40);
			//列地址设置
			for(i=0;i<64;i++)
				LCD_Write_Char(0x00);
		}
	}
	LCD_Locate(0,0);	
}
