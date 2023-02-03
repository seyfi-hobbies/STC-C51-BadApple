///suppose the frequency of test chip is 18.432MHz
#include "Serial.h"

/*----------------------------
Initialize serial port
----------------------------*/
void InitUart()
{
 SCON = 0x5a; //UART1 in 8-bit variable baud rate mode
#if URMD == 0
 T2L = 0xd8; //Set the auto-reload parameter
 T2H = 0xff; //115200 bps(65536-18432000/4/115200)
 AUXR = 0x14; //T2 in 1T mode, strat up Timer 2
 AUXR |= 0x01; //Timer 2 as baud-rate Generator of UART1
#elif URMD == 1
 AUXR = 0x40; //T1 in 1T mode
 TMOD = 0x00; //Timer1 in mode 0(16-bit auto-reload mode
 TL1 = 0xd8; //Set the auto-reload parameter
 TH1 = 0xff; //115200 bps(65536-18432000/4/115200)
 TR1 = 1; //strat up Timer 1
#else
 TMOD = 0x20; //Timer1 in mode 2 (8-bit auto-reload mode)
 AUXR = 0x40; //T1 in 1T mode
 TH1 = TL1 = 0xfb; //115200 bps(256 - 18432000/32/115200)
 TR1 = 1;
#endif
}



/*******************************************************************************
Seyfi: Serial test works with XTAL (clock freq) :18.432MHz
*******************************************************************************/
/*
void main()
{	
	unsigned char *msg = "hello seyfi";
	//BYTE idata *iptr;
  BYTE i;
  InitUart(); //initialize serial port
	
	for (i=0; i<11; i++) //read 7 bytes
	{
		SendUart(msg[i]); //send ID number to serial port
	}
	
	while(1) {
			i = RecvUart();
		  SendUart(i);
			//Delay10ms(2000);
	}
			
}

*/
/*----------------------------
Send serial port data
----------------------------*/
void SendUart(BYTE dat)
{
 while (!TI); //wait to finish transmitting
 TI = 0; 
 SBUF = dat; //Send serial port data
}

BYTE RecvUart()
{
 while (!RI); //wait receive complete
 RI = 0; //clear RI flag
 return SBUF; //return receive data
}
