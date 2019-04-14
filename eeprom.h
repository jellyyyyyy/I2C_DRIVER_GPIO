#ifndef _EE_DRIVER_H
#define _EE_DRIVER_H

#define EE_Address 		0xA0	//Æ÷¼þµØÖ·

#define EE_Write_Add(address)		(EE_Address | ((address)>0xFF?0x02:0x00))

#define EEPROM_PageSize		16

signed char EEPROM_WritePage(unsigned char Dst, unsigned char *Src, unsigned int Len);
signed char EEPROM_Write(unsigned char Dst, unsigned char *Src, unsigned int Len);
signed char EEPROM_ReadOnce(unsigned char *Dst, unsigned char Src, unsigned int Len);
signed char EEPROM_Read(unsigned char *Dst, unsigned char Src, unsigned int Len);

#endif //_EE_DRIVER_H