#ifndef _I2C_H
#define	_I2C_H

#define I2C_SCL_OUT		P10CR |= BIT6
#define I2C_SCL_IN		P10CR &= ~BIT6
#define I2C_SDA_OUT		P10CR |= BIT7
#define I2C_SDA_IN		P10CR &= ~BIT7

#define I2C_SCL_H		P10 |= BIT6
#define I2C_SCL_L		P10 &= ~BIT6
#define I2C_SDA_H		P10 |= BIT7
#define	I2C_SDA_L		P10 &= ~BIT7
#define I2C_SDA_IsH		(P10 & BIT7) ? 1 : 0

void I2C_Delay(void);
void I2C_IOInit(void);
void I2C_Start(void);
void I2C_Stop(void);
uint8 I2C_SendByte(uint8 SdByte);
uint8 I2C_RecvByte(uint8 Ack);

#endif

















