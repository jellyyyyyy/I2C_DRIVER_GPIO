/****************************************Copyright (c)**************************************************
**                                    南京立超电子有限公司                              
**                                        技  术  部 
**                                    http://www.dycmcu.com
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: G80F916.h
**创   建   人: 张峰
**最后修改日期: 2013-10-15
**描        述: G80F916芯片特殊功能寄存器定义
**
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 张峰
** 版  本: V1.0
** 日　期: 2013-10-15
** 描　述: G80F916芯片特殊功能寄存器定义
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人: 
** 日　期:
** 描　述:
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef __G80F916_H__
#define __G80F916_H__

#include <absacc.h>

/* CPU */
sfr      PSW       = 0xD0;            
sfr      ACC       = 0xE0;
sfr      B         = 0xF0;
sfr      AUXC      = 0xF1;
sfr      SP        = 0x81;
sfr      DPL       = 0x82;
sfr      DPH       = 0x83;
sfr      DPL1      = 0x84;
sfr      DPH1      = 0x85;
sfr      INSCON    = 0x86;
sfr      XPAGE     = 0xF7;

/* POWER  */
sfr      PCON      = 0x87;
sfr      SUSLO     = 0x8E;

/* LPD */
sfr      LPDCON    = 0xB3;

/* FLASH */
sfr      IB_DATA   = 0xEE;
sfr      IB_OFFSET = 0xEF;
sfr      IB_CON1   = 0xF2;
sfr      IB_CON2   = 0xF3;
sfr      IB_CON3   = 0xF4;
sfr      IB_CON4   = 0xF5;
sfr      IB_CON5   = 0xF6;
sfr      PBANK     = 0xB6;
sfr      PBANKLO   = 0xB7;
sfr      ISPLO     = 0xA5;
sfr      ISPCON    = 0xA6;
sfr      FLASHCON  = 0xA7;

/* WDT */
sfr      RSTSTAT   = 0xB1;

/* CLOCK */
sfr      CLKCON    = 0xB2;
sfr      CLKCON1   = 0xB4;
sfr      OSCLO     = 0xB5;

/* INTERRUPT */
sfr      IEN0      = 0xA8;
sfr      IEN1      = 0xA9;
sfr      IENC      = 0xAA;
sfr      EXF0      = 0xAB;
sfr      EXF1      = 0xAC;
sfr      IPL0      = 0xB8;
sfr      IPH0      = 0xB9;
sfr      IPL1      = 0xBA;
sfr      IPH1      = 0xBB;
sfr      EXCON2    = 0xCF;

/* PORT */
sfr      P0        = 0x80;
sfr      P1        = 0x90;
sfr      P2        = 0xA0;
sfr      P3        = 0xB0;
sfr      P4        = 0xC0;
sfr      P5        = 0xD8;
sfr      P6        = 0xE8;
sfr      P7        = 0xF8;
sfr      P8        = 0xE5;
sfr      P9        = 0xE6;
sfr      P10       = 0xE7;
sfr      P0CR      = 0xC1;
sfr      P1CR      = 0xC2;
sfr      P2CR      = 0xC3;
sfr      P3CR      = 0xC4;
sfr      P4CR      = 0xC5;
sfr      P5CR      = 0xC6;
sfr      P6CR      = 0xC7;
sfr      P0PCR     = 0xD1;
sfr      P1PCR     = 0xD2;
sfr      P2PCR     = 0xD3;
sfr      P3PCR     = 0xD4;
sfr      P4PCR     = 0xD5;
sfr      P5PCR     = 0xD6;
sfr      P6PCR     = 0xD7;
sfr      P6OS      = 0xBE;
sfr	     P0OS      = 0XBD;

/* TIMER */
sfr      TCON      = 0x88;
sfr      TMOD      = 0x89;
sfr      TL0       = 0x8A;
sfr      TH0       = 0x8C;
sfr      TL1       = 0x8B;
sfr      TH1       = 0x8D;
sfr      T2CON     = 0xC8;
sfr      T2MOD     = 0xC9;
sfr      RCAP2L    = 0xCA;
sfr      RCAP2H    = 0xCB;
sfr      TL2       = 0xCC;
sfr      TH2       = 0xCD;
sfr      TCON1     = 0x8F;
sfr      T3CON     = 0xE1;
sfr      TL3       = 0xE2;
sfr      TH3       = 0xE3;

/* EUART0 */
sfr      SCON      = 0x98;
sfr      SBUF      = 0x99;
sfr      SADDR     = 0x9A;
sfr      SADEN     = 0x9B;
sfr      SBRTH     = 0x9C;
sfr      SBRTL     = 0x9D;
sfr      SFINE     = 0x9E;

/* EUART1 */
sfr      SCON1     = 0xD9;
sfr      SBUF1     = 0xDA;
sfr      SADDR1    = 0xDB;
sfr      SADEN1    = 0xDC;
sfr      SBRTH1    = 0xDD;
sfr      SBRTL1    = 0xDE;

/* EUART2 */
sfr      SCON2     = 0xF9;
sfr      SBUF2     = 0xFA;
sfr      SADDR2    = 0xFB;
sfr      SADEN2    = 0xFC;
sfr      SBRTH2    = 0xFD;
sfr      SBRTL2    = 0xFE;
sfr      SFINE2    = 0x9F;	


/* EUART3  */			  //HARBOUR0713
sfr      SCON3     = 0xEB;
sfr      SBUF3     = 0xEC;
sfr      SADDR3    = 0xED;
sfr      SADEN3    = 0xE4;
sfr      SBRTH3    = 0xBC;
sfr      SBRTL3    = 0xBF;
sfr      SFINE3    = 0xAF;	
sfr	   SNEG      = 0XDF;
/* IR */           
sfr      IRCON     = 0xAD;
sfr      IRDAT     = 0xAE;

///* TWI */						//HARBOUR0713
//sfr      TWICON = 0xE9;
//sfr      TWIDAT = 0xEA;

/* ADC */
sfr      ADCON     = 0x91;
sfr      ADCON1    = 0x92;
sfr      ADT       = 0x93;
sfr      ADCH      = 0x94;
sfr      ADDL      = 0x95;
sfr      ADDH      = 0x96;

/*SPI*/
sfr      SPCON     = 0xA1;
sfr      SPSTA     = 0xA2;
sfr      SPDAT     = 0xA3;


/* 扩展寄存定义 */
#define  P7CR      XBYTE[0xFFD0]       
#define  P8CR      XBYTE[0xFFD1]
#define  P9CR      XBYTE[0xFFD2]
#define  P10CR     XBYTE[0xFFD3]
#define  P7PCR     XBYTE[0xFFD8]
#define  P8PCR     XBYTE[0xFFD9]
#define  P9PCR     XBYTE[0xFFDA]
#define  P10PCR    XBYTE[0xFFDB]
#define  P2CON     XBYTE[0xFFE0]
#define  P5CON     XBYTE[0xFFE1]
#define  P10CON    XBYTE[0xFFE2]

/*PWM*/
#define  PWM0CON   XBYTE[0xFF90]
#define  PWM0PH    XBYTE[0xFF91]
#define  PWM0PL    XBYTE[0xFF92]
#define  PWM0DH    XBYTE[0xFF93]
#define  PWM0DL    XBYTE[0xFF94]
#define  PWM1CON   XBYTE[0xFF98]
#define  PWM1PH    XBYTE[0xFF99]
#define  PWM1PL    XBYTE[0xFF9A]
#define  PWM1DH    XBYTE[0xFF9B]
#define  PWM1DL    XBYTE[0xFF9C]

/* LCD */
#define  LCDCON    XBYTE[0xFF88]
#define  LCDCON1   XBYTE[0xFF89]
#define  LCDCON2   XBYTE[0xFF8A]
#define  LEDCON    XBYTE[0xFF8B]
#define  LCLK      XBYTE[0xFF8C]
#define  P2SS      XBYTE[0xFF80]
#define  P3SS      XBYTE[0xFF81]
#define  P4SS      XBYTE[0xFF82]
#define  P5SS      XBYTE[0xFF83]
#define  P7SS      XBYTE[0xFF84]
#define  P8SS      XBYTE[0xFF85]
#define  P9SS      XBYTE[0xFF86]

/* RTC */ 
#define  SBSC      XBYTE[0xFFA0]
#define  SEC       XBYTE[0xFFA1]
#define  MIN       XBYTE[0xFFA2]
#define  HR        XBYTE[0xFFA3]
#define  DAY       XBYTE[0xFFA4]
#define  MTH       XBYTE[0xFFA5]
#define  YR        XBYTE[0xFFA6]
#define  WEEK      XBYTE[0xFFA7]
#define  RTCDATH   XBYTE[0xFFA8]
#define  RTCDATL   XBYTE[0xFFA9]
#define  RTCALM    XBYTE[0xFFAA]
#define  A0SEC     XBYTE[0xFFAB]
#define  A0MIN     XBYTE[0xFFAC]
#define  A0HR      XBYTE[0xFFAD]
#define  A0DAY     XBYTE[0xFFAE]
#define  A0MTH     XBYTE[0xFFAF]
#define  A1SEC     XBYTE[0xFFB0]
#define  A1YR      XBYTE[0xFFB1]
#define  A1HR      XBYTE[0xFFB2]
#define  RTCCON    XBYTE[0xFFB3]
#define  RTCWR     XBYTE[0xFFB4]
#define  RTCPSW    XBYTE[0xFFB5]
#define  RTCIE     XBYTE[0xFFB6]
#define  RTCIF     XBYTE[0xFFB7]
#define  RTCECL    XBYTE[0xFFB8]
#define  RTCECH    XBYTE[0xFFB9]
#define  RTCTMR    XBYTE[0xFFBA]
#define  RTCTMP    XBYTE[0xFFBB]

/*7816*/
#define  S7816EN     XBYTE[0xFFC0]
#define  S7816CON    XBYTE[0xFFC1]
#define  EGTSET      XBYTE[0xFFC2]
#define  S7816WTH    XBYTE[0xFFC3]
#define  S7816WTL    XBYTE[0xFFC4]
#define  S7816CLKDIV XBYTE[0xFFC5]
#define  S7816ETUH   XBYTE[0xFFC6]
#define  S7816ETUL   XBYTE[0xFFC7]
#define  RXBUF       XBYTE[0xFFC8]
#define  TXBUF       XBYTE[0xFFC9]
#define  S7816IE     XBYTE[0xFFCA]
#define  S7816STA    XBYTE[0xFFCB]
#define  S7816ERRSTA XBYTE[0xFFCC]

/* TEMP */
#define  TPCON       XBYTE[0xFFE8]
#define  TEMPH       XBYTE[0xFFE9]
#define  TEMPL       XBYTE[0xFFEA]
#define  TEMPKH      XBYTE[0xFFEB]
#define  TEMPKL      XBYTE[0xFFEC]
#define  TEMPBH      XBYTE[0xFFED]
#define  TEMPBL      XBYTE[0xFFEE]

/*--------------------------  位寻址区 -------------------- */
/*  PSW   */
sbit     CY        = PSW^7;
sbit     AC        = PSW^6;
sbit     F0        = PSW^5;
sbit     RS1       = PSW^4;
sbit     RS0       = PSW^3;
sbit     OV        = PSW^2;
sbit     F1        = PSW^1;
sbit     P         = PSW^0;

/*  TCON  */
sbit     TF1       = TCON^7;
sbit     TR1       = TCON^6;
sbit     TF0       = TCON^5;
sbit     TR0       = TCON^4;

/*  T2CON  */
sbit     TF2       = 0xCF;
sbit     EXF2      = 0xCE;
sbit     EXEN2     = 0xCB;
sbit     TR2       = 0xCA;
sbit     C_T2      = 0xC9;
sbit     CP_RL2    = 0xC8;

/*  IPL0   */ 
sbit     PADTPL    = 0xBE;
sbit     PT2L      = 0xBD;
sbit     PSL       = 0xBC;
sbit     PT1L      = 0xBB;
sbit     P7816L    = 0xBA;
sbit     PT0L      = 0xB9;
sbit     PX4L      = 0xB8;

/*  IEN0   */
sbit     EA        = 0xAF;
sbit     EADTP     = 0xAE;
sbit     ET2       = 0xAD;
sbit     ES        = 0xAC;
sbit     ET1       = 0xAB;
sbit     E7816     = 0xAA;
sbit     ET0       = 0xA9;
sbit     EX4       = 0xA8;

/*  SCON  */
sbit     SM0_FE    = 0x9F;
sbit     SM1_RXOV  = 0x9E;
sbit     SM2_TXCOL = 0x9D;
sbit     REN       = 0x9C;
sbit     TB8       = 0x9B;
sbit     RB8       = 0x9A;
sbit     TI        = 0x99;
sbit     RI        = 0x98;	 

/* P0 */
sbit     P0_0      = P0^0;
sbit     P0_1      = P0^1;
sbit     P0_2      = P0^2;
sbit     P0_3      = P0^3;
sbit     P0_4      = P0^4;
sbit     P0_5      = P0^5;
sbit     P0_6      = P0^6;
sbit     P0_7      = P0^7;

/* P1 */
sbit     P1_0      = P1^0;
sbit     P1_1      = P1^1;
sbit     P1_2      = P1^2;
sbit     P1_3      = P1^3;
sbit     P1_4      = P1^4;
sbit     P1_5      = P1^5;
sbit     P1_6      = P1^6;
sbit     P1_7      = P1^7;

/* P2 */
sbit     P2_0      = P2^0;
sbit     P2_1      = P2^1;
sbit     P2_2      = P2^2;
sbit     P2_3      = P2^3;
sbit     P2_4      = P2^4;
sbit     P2_5      = P2^5;
sbit     P2_6      = P2^6;
sbit     P2_7      = P2^7;

/* P3 */
sbit     P3_0      = P3^0;
sbit     P3_1      = P3^1;
sbit     P3_2      = P3^2;
sbit     P3_3      = P3^3;
sbit     P3_4      = P3^4;
sbit     P3_5      = P3^5;
sbit     P3_6      = P3^6;
sbit     P3_7      = P3^7;

/* P4 */
sbit     P4_0      = P4^0;
sbit     P4_1      = P4^1;
sbit     P4_2      = P4^2;
sbit     P4_3      = P4^3;
sbit     P4_4      = P4^4;
sbit     P4_5      = P4^5;
sbit     P4_6      = P4^6;
sbit     P4_7      = P4^7;	 

/* P5 */
sbit     P5_0      = P5^0;
sbit     P5_1      = P5^1;
sbit     P5_2      = P5^2;
sbit     P5_3      = P5^3;
sbit     P5_4      = P5^4;
sbit     P5_5      = P5^5;
sbit     P5_6      = P5^6;
sbit     P5_7      = P5^7;	

/* P5 */
sbit     P6_0      = P6^0;
sbit     P6_1      = P6^1;
sbit     P6_2      = P6^2;
sbit     P6_3      = P6^3;
sbit     P6_4      = P6^4;
sbit     P6_5      = P6^5;
sbit     P6_6      = P6^6;
sbit     P6_7      = P6^7;

/* P7 */
sbit     P7_0      = P7^0;
sbit     P7_1      = P7^1;
sbit     P7_2      = P7^2;
sbit     P7_3      = P7^3;
sbit     P7_4      = P7^4;
sbit     P7_5      = P7^5;
sbit     P7_6      = P7^6;
sbit     P7_7      = P7^7;

#endif

