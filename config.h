
#ifndef __CONFIG_H 
#define __CONFIG_H

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif


/********************************/
/*      CPU无关性定义           */
/********************************/
typedef unsigned char      uint8;
typedef unsigned char      uint8_t;

typedef signed char      int8;
typedef signed char      int8_t;

typedef unsigned short     uint16;
typedef unsigned short     uint16_t;

typedef signed short     int16;
typedef signed short     int16_t;

typedef unsigned long      uint32;
typedef unsigned long      uint32_t;

typedef signed long      int32;
typedef signed long      int32_t;

typedef float              fp32;
typedef double             fp64;

typedef	bit				   Bit;
typedef	bit				   Bool;
typedef	unsigned char	   Byte;
typedef	unsigned int	   Word;
typedef	unsigned long	   Dword;

typedef union 
{
   uint32 val;
	struct 
	{
      uint8 buf3:8;
      uint8 buf2:8;
      uint8 buf1:8;
      uint8 buf0:8;
	}TBuf;
}__U32_Def;   

typedef union 
{
   uint8 tByte;
	struct 
	{
      uint8 bit0:1;
      uint8 bit1:1;
      uint8 bit2:1;
      uint8 bit3:1;
      uint8 bit4:1;
      uint8 bit5:1;
      uint8 bit6:1;
      uint8 bit7:1;
	}Bits;
}__ByteBits;   

/********************************/
/*      引用相应CPU头文件       */
/********************************/
#include "G80F916.h"

#define	      FSYSCLK			             12000000	//定时器时钟频率12MHz
#define	      TIMERCLK			             1000000	//定时器时钟频率1MHz

#define	      MAKEDWORD(v1,v2,v3,v4)	     (((Dword)(v1)<<24) + ((Dword)(v2)<<16) + ((Dword)(v3)<<8) + (Dword)(v4))
#define	      MAKEWORD(v1,v2)	             (((Word)(v1)<<8) + (Word)(v2))
#define	      HIBYTE(v1)		             ((Byte)((v1)>>8))
#define	      LOBYTE(v1)		             ((Byte)((v1)&0xff))

#define       LongToBin(n) \
      (                    \
      ((n >> 21) & 0x80) | \
      ((n >> 18) & 0x40) | \
      ((n >> 15) & 0x20) | \
      ((n >> 12) & 0x10) | \
      ((n >>  9) & 0x08) | \
      ((n >>  6) & 0x04) | \
      ((n >>  3) & 0x02) | \
      ((n      ) & 0x01)   \
      )
#define       Bin(n)                 LongToBin(0x##n##l)	//write binary charactor set,exsample : Bin(11111111) = 0xff


#define       BIT0                   0x01
#define       BIT1                   0x02
#define       BIT2                   0x04
#define       BIT3                   0x08
#define       BIT4                   0x10
#define       BIT5                   0x20
#define       BIT6                   0x40
#define       BIT7                   0x80

#define       NOP                    _nop_()

 

/********************************/
/*      用户头文件包含区        */
/********************************/
#include <intrins.h>	
#include <string.h>	
#include <math.h>
#include <stdlib.h>

#include "io.h"
//#include "isr.h"
#include "timer.h"
//#include "rtc.h"
//#include "uart.h"
//#include "data_struct.h"
//#include "subfun.h"   
//#include "lcd.h"
//#include "display.h"
//#include "clock.h"
//#include "adc.h"
//#include "target.h"
//#include "Key_Driver.h"
//#include "UseKey.h"
#include "i2c.h"
#include "ee_driver.h"
//#include "Memory.h"
//#include "DL645.h"
//#include "Alarm.h"
//#include "Exint.h"
#endif
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
