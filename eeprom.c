#include "config.h"

unsigned char xdata memBuffer[100];

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�EEPROM_WritePage
//��������: дһ֡���ݵ�EEPROM,ҳ��д
//��ڲ���: Dst------EEPROMĿ���ַ��
//          src------Ҫд�����ݵ�ַָ�룻
//          Len------Ҫд�������ֽڳ��ȣ�
//���ڲ���: ��������0,дʧ�ܷ���-1ֵ
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
signed char EEPROM_WritePage(unsigned char Dst, unsigned char *Src, unsigned int Len)
{
	unsigned char temp = 0;

	// ---------------------------------------------------------
	I2C_Start();              //����I2Cͨ��
	temp = 0;	
	while((I2C_SendByte(EE_Write_Add(Src))) && (temp<13))	//����Ӧ��Ϊ0ʱ��������������������������
	{
		I2C_Stop();
		I2C_Delay();   //��ʱһ��ʱ�䱣֤EEPҳд�ܹ����,�������Ҫ��ҳд��ɺ���Ҫ��ʱ���ܽ����¸�ҳд
		I2C_Start();
		temp++;
	}
	if(temp >= 13)             //����13�η���ʧ�ܣ��������ܲ�����
	{
		I2C_Stop();
		return(-1);
	}
	if(I2C_SendByte(Dst))
	{
		I2C_Stop();
		return -1;	
	}
	while(Len-- > 0)
	{
		I2C_SendByte(*Src);
		Src++;
	}
	I2C_Stop();
	return 0;
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�EEPROM_Write
//��������: дһ֡���ݵ�EEPROM,�ɿ�ҳд
//��ڲ���: Dst------Ҫд��EEPROMĿ���ַ��
//          Src------Ҫд�����ݵ�ַָ�룻
//          Len------Ҫд�������ֽڳ��ȣ�
//���ڲ���: ��������0,дʧ�ܷ���-1ֵ
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
signed char EEPROM_Write(unsigned char Dst, unsigned char *Src, unsigned int Len)
{
	unsigned int Length = 0;
	unsigned int Tmp = 0;
	unsigned int Dsttemp = 0;
	unsigned int Lentemp = 0;
	unsigned char *Srctemp;
	signed char cmp = 0;

	Dsttemp = Dst;
	Srctemp = Src;
	Lentemp	= Len;

	while(Len > 0)
	{
		Tmp = Dst & (EEPROM_PageSize - 1);		//�����ڵ�ǰҳ�д�Dst��ʼ��ҳĩ�Ŀռ�
		if(Tmp != 0)							//Dst����PageSize������������Ҫ��ҳ�м俪ʼд
		{
			Length = EEPROM_PageSize - Tmp;		//�Ƚ���ǰҳд��
		}
		else
		{
			Length = EEPROM_PageSize;			//�Ӹ�ҳ�׿�ʼд
		}

		if(Len < Length) 						//���Ҫд�����ڸ�ҳ֮��
		{
			Length = Len;
		}

		if(EEPROM_WritePage(Dst,Src,Length))
		{
			return -1;
		}

		Dst += Length;
		Src += Length;
		Len -= Length;
	}

	Dst = Dsttemp;
	Src = Srctemp;
	Len = Lentemp;

	if(EEPROM_ReadOnce(memBuffer,Dst,Len))	//��ȡ���ݵ�����
	{
		return -1;
	}
	cmp = memcmp(Src,memBuffer,Len);
	return cmp;
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�EEPROM_ReadOnce
//��������: ��EEPROM��һ֡���ݣ������бȶ�
//��ڲ���: Dst------�����������ݴ��Ŀ���ַ��
//          Src------Ҫ��ȡ��������EEP�еĵ�ַ��
//          Len------Ҫ��ȡ�������ֽڳ���
//���ڲ���: ��������0,��ʧ�ܷ���-1ֵ
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
signed char EEPROM_ReadOnce(unsigned char *Dst, unsigned char Src, unsigned int Len)
{
	unsigned char temp = 0;

	// ---------------------------------------------------------
	I2C_Start();              //����I2Cͨ��
	temp = 0;	
	while((I2C_SendByte(EE_Write_Add(Src))) && (temp<13))	//����Ӧ��Ϊ0ʱ��������������������������
	{
		I2C_Stop();
		I2C_Delay();   //��ʱһ��ʱ�䱣֤EEPҳд�ܹ����
		I2C_Start();
		temp++;
	}
	if(temp >= 13)             //����13�η���ʧ�ܣ��������ܲ�����
	{
		I2C_Stop();
		return(-1);
	}
	// ------------------------------------------------------------
	if(I2C_SendByte((unsigned char)Src))      //�����ӵ�ַ��λ
	{
		I2C_Stop();
		return(-1);
	}
	// -----------------------------------------
	I2C_Start();
	if(I2C_SendByte((EE_Write_Add(Src))|0x01))//����������ַ ������
	{
		I2C_Stop();
		return(-1);
	}
	//-------------------------------------------------
	while (Len-->0)
	{
		temp = (Len!=0?0x00 : 0x01);      //����ǽ������һ���ֽڣ��򲻷���Ӧ��λ
		*Dst = I2C_RecvByte( temp );  //��ȡһ���ֽں�оƬ�ڲ���ַ�Զ���1
		Dst++;
	}
	I2C_Stop();
	return(0x00);
}

//---------------------------------------------------------------------------------------------------------------//
//�������ƣ�EEPROM_Read
//��������: ��EEPROM��һ֡���ݣ����������������ݱȶ�
//��ڲ���: Dst-----Ҫ����������RAM�еĵ�ַָ�룻
//          src-----Ҫ����EEPROMĿ���ַ��
//          Len-----Ҫ���������ֽڳ��ȣ�
//���ڲ���: ��������0,��ʧ�ܷ���-1ֵ
//˵    ����
//---------------------------------------------------------------------------------------------------------------//
signed char EEPROM_Read(unsigned char *Dst, unsigned char Src, unsigned int Len)
{
	signed char cmp = 0;

	if(EEPROM_ReadOnce(Dst,Src,Len))
	{
		return -1;
	}

	if(EEPROM_ReadOnce(memBuffer,Src,Len))
	{
		return -1;
	}
	cmp = memcmp(Dst,memBuffer,Len);
	return cmp;
}