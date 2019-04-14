#include "config.h"

uint8 init[20] = {0x99,0x44,0x21,0x11,0x03,0x03,0x09,0x10,0x99,0x44,0x21,0x11,0x03,0x03,0x09,0x10,0x99,0x44,0x21,0x00};
uint8 recv[20];

void Switch_RC12MCLK(void)
{
	OSCLO = 0x55;
	CLKCON1 = 0x80;
	while((CLKCON1 & 0x40) != 0x40);
	OSCLO = 0x55;
	CLKCON = 0x00;
}

void PortInit()
{
	 //关闭所有端口上拉
    P0PCR  = Bin(00000000);
    P1PCR  = Bin(00000000);
    P2PCR  = Bin(00000000);
    P3PCR  = Bin(00000000);
    P4PCR  = Bin(00000000);
    P5PCR  = Bin(00000000);
    P6PCR  = Bin(00000000);
    P7PCR  = Bin(00000000);
    P8PCR  = Bin(00000000);
    P9PCR  = Bin(00000000);
    P10PCR = Bin(00000000);

    //设置为推挽输出
    P0OS=Bin(11111100);
    P6OS=Bin(00000011);
    
    //灌电流增强设置
    P2CON=Bin(00000000);
    P5CON=Bin(00000000);
    P10CON=Bin(00000000);
}

void main(void)
{
	EA = 0;		//关总中断		 
	PSW = 0x00; //清除程序状态字
	Switch_RC12MCLK();	//时钟初始化
	PortInit();
	EA = 1;

	EEPROM_Write(0x20,init,20);
	EEPROM_Read(recv,0x20,20);
	while(1)
	{	
	};
}