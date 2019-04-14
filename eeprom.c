#include "config.h"

unsigned char xdata memBuffer[100];

//---------------------------------------------------------------------------------------------------------------//
//函数名称：EEPROM_WritePage
//函数功能: 写一帧数据到EEPROM,页内写
//入口参数: Dst------EEPROM目标地址；
//          src------要写的数据地址指针；
//          Len------要写的数据字节长度；
//出口参数: 正常返回0,写失败返回-1值
//说    明：
//---------------------------------------------------------------------------------------------------------------//
signed char EEPROM_WritePage(unsigned char Dst, unsigned char *Src, unsigned int Len)
{
	unsigned char temp = 0;

	// ---------------------------------------------------------
	I2C_Start();              //启动I2C通信
	temp = 0;	
	while((I2C_SendByte(EE_Write_Add(Src))) && (temp<13))	//发送应答为0时发送正常，否则再起启动发送
	{
		I2C_Stop();
		I2C_Delay();   //延时一段时间保证EEP页写能够完成,这里必须要，页写完成后需要延时才能进行下个页写
		I2C_Start();
		temp++;
	}
	if(temp >= 13)             //连续13次发送失败，器件可能不正常
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
//函数名称：EEPROM_Write
//函数功能: 写一帧数据到EEPROM,可跨页写
//入口参数: Dst------要写的EEPROM目标地址；
//          Src------要写的数据地址指针；
//          Len------要写的数据字节长度；
//出口参数: 正常返回0,写失败返回-1值
//说    明：
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
		Tmp = Dst & (EEPROM_PageSize - 1);		//计算在当前页中从Dst开始到页末的空间
		if(Tmp != 0)							//Dst不是PageSize的整数倍，需要从页中间开始写
		{
			Length = EEPROM_PageSize - Tmp;		//先将当前页写满
		}
		else
		{
			Length = EEPROM_PageSize;			//从该页首开始写
		}

		if(Len < Length) 						//如果要写长度在该页之内
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

	if(EEPROM_ReadOnce(memBuffer,Dst,Len))	//读取数据到缓存
	{
		return -1;
	}
	cmp = memcmp(Src,memBuffer,Len);
	return cmp;
}

//---------------------------------------------------------------------------------------------------------------//
//函数名称：EEPROM_ReadOnce
//函数功能: 从EEPROM读一帧数据，不进行比对
//入口参数: Dst------读出来的数据存放目标地址；
//          Src------要读取的数据在EEP中的地址；
//          Len------要读取的数据字节长度
//出口参数: 正常返回0,读失败返回-1值
//说    明：
//---------------------------------------------------------------------------------------------------------------//
signed char EEPROM_ReadOnce(unsigned char *Dst, unsigned char Src, unsigned int Len)
{
	unsigned char temp = 0;

	// ---------------------------------------------------------
	I2C_Start();              //启动I2C通信
	temp = 0;	
	while((I2C_SendByte(EE_Write_Add(Src))) && (temp<13))	//发送应答为0时发送正常，否则再起启动发送
	{
		I2C_Stop();
		I2C_Delay();   //延时一段时间保证EEP页写能够完成
		I2C_Start();
		temp++;
	}
	if(temp >= 13)             //连续13次发送失败，器件可能不正常
	{
		I2C_Stop();
		return(-1);
	}
	// ------------------------------------------------------------
	if(I2C_SendByte((unsigned char)Src))      //发送子地址低位
	{
		I2C_Stop();
		return(-1);
	}
	// -----------------------------------------
	I2C_Start();
	if(I2C_SendByte((EE_Write_Add(Src))|0x01))//发送器件地址 读命令
	{
		I2C_Stop();
		return(-1);
	}
	//-------------------------------------------------
	while (Len-->0)
	{
		temp = (Len!=0?0x00 : 0x01);      //如果是接收最后一个字节，则不发送应答位
		*Dst = I2C_RecvByte( temp );  //读取一个字节后芯片内部地址自动加1
		Dst++;
	}
	I2C_Stop();
	return(0x00);
}

//---------------------------------------------------------------------------------------------------------------//
//函数名称：EEPROM_Read
//函数功能: 从EEPROM读一帧数据，根据条件进行数据比对
//入口参数: Dst-----要读的数据在RAM中的地址指针；
//          src-----要读的EEPROM目标地址；
//          Len-----要读的数据字节长度；
//出口参数: 正常返回0,读失败返回-1值
//说    明：
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