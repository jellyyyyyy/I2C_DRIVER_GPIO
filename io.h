#ifndef _IO_H
#define	_IO_H

#define BELL_OUT	P10CR |= 0x01	
#define	BELL_ON		P10	|= 0x01
#define	BELL_OFF	P10 &= ~0x01

//Óà¶î±¨¾¯
#define CREDIT_RED_OUT  P0CR |= BIT2
#define CREDIT_RED_ON()  P0 |= BIT2
#define CREDIT_RED_OFF()   P0 &= ~BIT2

#define CREDIT_GREEN_OUT P0CR |= BIT3
#define CREDIT_GREEN_ON() P0 |= BIT3
#define CREDIT_GREEN_OFF()  P0 &= ~BIT3

#endif //_IO_H