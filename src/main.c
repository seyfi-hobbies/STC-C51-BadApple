#include<reg51.h>
#include"st7565.h"
#include <stdio.h>
#include "Serial.h"


unsigned char xdata pic[1024];


//-----display--one-picture--------
void Picture_12864(unsigned char *ptr)
{	
	unsigned char i,j;
	//data
	for(i=0;i<8;i++) 
	{
		LcdSt7565_WriteCmd(0x40);
	
		LcdSt7565_WriteCmd(0xB0+i);
	
		LcdSt7565_WriteCmd(0x10); 
		LcdSt7565_WriteCmd(0x04); 
	
		//skip 3x8 =24 pix on the right
		for(j=0;j<24;j++)  
		{
			LcdSt7565_WriteData(0);
		}
		for(j=0;j<80;j++)  //each image line is 80 pixel
		{
			LcdSt7565_WriteData(*ptr);
	
			ptr++;
		}
	}
	
}

void main(void)
{
	uint idx;
	Lcd12864_Init();        
	Lcd12864_ClearScreen();	
	
	InitUart(); 
		
	while (1) {
			//1024 frame is dropped to 640 bytes
			//get 640 bytes from serial
			//send ready signal
			SendUart(123);
  		idx=0;
			while(idx <= 639) {
					pic[idx++] = RecvUart();
			}
			Picture_12864(pic);
				
	}
}