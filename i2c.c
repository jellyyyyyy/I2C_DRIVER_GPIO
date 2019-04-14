#include "config.h"

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�I2C_Delay				
//��������: I2C��Ҫ����ʱʱ�䣬����EEPROMоƬ�ֲ�ȷ����С��ʱʱ��
//��ڲ���: 
//���ڲ���: 
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
void I2C_Delay()
{
	NOP;NOP;NOP;NOP;NOP;
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�I2C_IOInit				
//��������: I2C���߳�ʼ��
//��ڲ���: 
//���ڲ���: 
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
void I2C_IOInit(void)
{
	I2C_SCL_H;
	I2C_SDA_H;
	I2C_SCL_OUT;
	I2C_SDA_OUT;
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�I2C_Start				
//��������: ����I2C�����ź�
//��ڲ���: 
//���ڲ���: 
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
void I2C_Start(void)
{
	I2C_SCL_H;
	I2C_SDA_H;
	I2C_SCL_OUT;
	I2C_SDA_OUT;

	I2C_Delay();
	I2C_SDA_L;
	I2C_Delay();
	I2C_SCL_L;
	I2C_Delay();
} 

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�I2C_Stop				
//��������: ����I2C�����ź�
//��ڲ���: 
//���ڲ���: 
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
void I2C_Stop(void)
{
	I2C_SCL_H;
	I2C_SDA_L;
	I2C_SCL_OUT;
	I2C_SDA_OUT;
	I2C_Delay();
	I2C_SDA_H;
	I2C_Delay();
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�I2C_SendByte				
//��������: ͨ��I2C����һ���ֽ�
//��ڲ���: SdByte��Ҫ���͵��ֽ�
//���ڲ���: ����Ӧ������0--Ӧ��Ϊ0������Ӧ��Ϊ��0��
//˵    ��������ֵΪ�������ݣ���ֹĳ��IO�ڷ��ڸ�λ����û�н��յ�Ӧ������
//---------------------------------------------------------------------------------------------------------------//
uint8 I2C_SendByte(uint8 SdByte)
{
	uint8 temp;
	uint8 Ack;

	I2C_SCL_OUT;
	I2C_SDA_OUT;

	for(temp = 0; temp < 8; temp++)
	{
		I2C_SCL_L;
		I2C_Delay();
		if(SdByte & 0x80)
		{
			I2C_SDA_H;
		}
		else
		{
			I2C_SDA_L;
		}
		I2C_Delay();
		I2C_SCL_H;
		I2C_Delay();
		SdByte <<= 1;	
	}

	//ACK
	I2C_SCL_L;
	I2C_SDA_IN;
	I2C_Delay();
	I2C_SCL_H;
	I2C_Delay();
	Ack = I2C_SDA_IsH;
	I2C_Delay();
	I2C_SCL_L;
	return Ack;
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�I2C_RecvByte				
//��������: ͨ��I2C��ȡһ���ֽ�
//��ڲ���: ACK---ָ�����պ����Ƿ���Ӧ��0--����Ӧ�𣬷��򲻷���Ӧ��
//���ڲ���: ���ض�ȡ�õ����ֽ�
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
uint8 I2C_RecvByte(uint8 Ack)
{
	uint8 temp = 0;
	uint8 RecvByte = 0x00;

	I2C_SDA_IN;
	I2C_SCL_OUT;

	for(temp = 0; temp < 8; temp++)
	{
		I2C_SCL_L;
		I2C_Delay();
		I2C_SCL_H;
		I2C_Delay();
		RecvByte <<= 1;
		if(I2C_SDA_IsH)
		{
			RecvByte |=	0x01;
		}
		else
		{
			RecvByte &= 0xfe;
		}
		I2C_Delay();
	}

	I2C_SCL_L;
	I2C_Delay();
	I2C_SDA_OUT;
	if(Ack == 0)
	{
		I2C_SDA_L;
	}
	else
	{
		I2C_SDA_H;
	}

	I2C_Delay();
	I2C_SCL_H;
	I2C_Delay();
	I2C_SCL_L;

	return RecvByte;
}