/**
 * @file   lpc_i2c.c
 * @author fanghuaqi <578567190@qq.com>
 * @date   Fri Mar 25 11:36:32 2011
 * 
 * @brief  
 * 
 * 
 */

#include  "LPC2478hw.h"

/** 
 * 
 * 
 * @param I2cMode 
 * 
 * @return 
 */
unsigned int  I2CInit( unsigned int I2cMode ) 
{
  PCONP |= (1 << 19);
  PINSEL1 &= ~0x03C00000;
  PINSEL1 |= 0x01400000;	/* set PIO0.27 and PIO0.28 to I2C0 SDA and SCK */
							/* function to 01 on both SDA and SCK. */
  /*--- Clear flags ---*/
  I20CONCLR = I2CONCLR_AAC | I2CONCLR_SIC | I2CONCLR_STAC | I2CONCLR_I2ENC;    

  /*--- Reset registers ---*/
  I20SCLL   = I2SCLL_SCLL;
  I20SCLH   = I2SCLH_SCLH;
  if ( I2cMode == I2CSLAVE )
  {
	I20ADR = WCH452_ADDR;
  }    

  /* Install interrupt handler */	
  /*if ( install_irq( I2C0_INT, (void *)I2C0MasterHandler, HIGHEST_PRIORITY ) == FALSE )
  {
	return( FALSE );
  }*/
  I20CONSET = I2CONSET_I2EN;
  return 1;
}

/** 
 * 
 * 
 * @param sla 
 * 
 * @return 
 */
unsigned char I2CReadByte(unsigned char sla)
{
  char data;

  I20CONCLR = (I2CONCLR_STAC|I2CONCLR_SIC|I2CONCLR_AAC);
  I20CONSET = I2CONSET_I2EN;//使能I2C作为主机

  I20CONSET = I2CONSET_STA;//发送一个起始状态位
  I20CONSET = I2CONSET_STA;//test restart!!

  while(I20STAT != 0x8);//起始字必须为0x8
  I20DAT = sla+1;//设置 SLA+R
  I20CONCLR = 0x8|0x20;//清零SI位，以传输SLA+R
          
  while(I20STAT != 0x40);//起始字0x40
  I20CONCLR = I2CONCLR_SIC;//清零SI位，以读取EEPROM
  while(I20STAT != 0x58);//接受数据，无ACK
  data = I20DAT;//读数据
          
   
  I20CONCLR = (I2CONCLR_SIC|I2CONCLR_AAC);        
  I20CONSET = I2CONSET_STO;//设置ST0位为1，以停止传输
  return data;
}

/** 
 * 
 * 
 * @param sla 
 * @param data 
 * 
 * @return 
 */
unsigned char I2CWriteByte(unsigned char sla, unsigned char data)
{
   int i; 
   I20CONCLR = (I2CONCLR_STAC|I2CONCLR_SIC|I2CONCLR_AAC);
   I20CONSET = I2CONSET_I2EN;		//使能I2C主机模式e
   I20CONSET = I2CONSET_STA;		//发送起始状态
      
   while(I20STAT != 0x8);
   I20DAT = sla;			//设置 SLA+W:1010000+0
   I20CONCLR = (I2CONCLR_SIC|I2CONCLR_STAC);//对SI清零以发送SLA+W
     
   while(I20STAT != 0x18);
   I20DAT = data;//写入数据
   I20CONCLR = I2CONCLR_SIC;//清零SI位，发送地址值
   
   while(I20STAT != 0x28);//起始值必为0x28
   I20CONCLR = I2CONCLR_SIC;   
   I20CONSET = I2CONSET_STO;//置ST0位为1，以停止传输   

   for(i = 0;i<8000;i++);
   return 1;
}
