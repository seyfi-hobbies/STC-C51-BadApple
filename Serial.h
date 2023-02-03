#ifndef __SERIAL_H__
#define __SERIAL_H__
#include "reg51.h"
typedef unsigned char BYTE;
typedef unsigned int WORD;
#define URMD 0 //0: Timer 2 as Baud Rate Generator
							//1:Timer1 in mode 0 (16-bit auto-reload mode) as Baud Rate Generator
						//2:Timer1 in mode 2 (8-bit auto-reload mode) as Baud Rate Generator

sfr T2H = 0xd6; //High 8 bit of Timer 2
sfr T2L = 0xd7; //Low 8 bit of Timer 2
sfr AUXR = 0x8e; //Auxiliary Register


typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

void InitUart();
void SendUart(BYTE dat);
BYTE RecvUart();


#endif