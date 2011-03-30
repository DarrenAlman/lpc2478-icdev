/**
 * @file   lpc_i2c.h
 * @author fanghuaqi <578567190@qq.com>
 * @date   Fri Mar 25 11:33:43 2011
 *
 * @brief
 *
 *
 */
#ifndef __LPC_I2C_H
#define __LPC_I2C_H

#define BUFSIZE			0x20
#define MAX_TIMEOUT		0x00FFFFFF

#define WCH452_ADDR     0x60

#define I2CMASTER		0x01
#define I2CSLAVE		0x02

#define RD_BIT			0x01

#define I2C_IDLE			0
#define I2C_STARTED			1
#define I2C_RESTARTED		2
#define I2C_REPEATED_START	3
#define DATA_ACK			4
#define DATA_NACK			5

#define I2CONSET_I2EN		0x00000040  /* I2C Control Set Register */
#define I2CONSET_AA			0x00000004
#define I2CONSET_SI			0x00000008
#define I2CONSET_STO		0x00000010
#define I2CONSET_STA		0x00000020

#define I2CONCLR_AAC		0x00000004  /* I2C Control clear Register */
#define I2CONCLR_SIC		0x00000008
#define I2CONCLR_STAC		0x00000020
#define I2CONCLR_I2ENC		0x00000040

#define I2DAT_I2C			0x00000000  /* I2C Data Reg */
#define I2ADR_I2C			0x00000000  /* I2C Slave Address Reg */
#define I2SCLH_SCLH			0x00000080  /* I2C SCL Duty Cycle High Reg */
#define I2SCLL_SCLL			0x00000080  /* I2C SCL Duty Cycle Low Reg */

unsigned int  I2CInit( unsigned int I2cMode );
unsigned char I2CReadByte(unsigned char sla);
unsigned char I2CWriteByte(unsigned char sla, unsigned char data);


#endif /* end __I2C_H */
/****************************************************************************
**                            End Of File
*****************************************************************************/
