#include<lpc21xx.h>
void delay()
{
 for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void main()
{ char a;
	IO0DIR=0xFFFFFFFF;
	PINSEL0=0x0000000C;
	U0LCR=0x83;
	U0DLL=0x63;
	U0DLM=0x00;
	U0LCR=0x03;
  while((U0LSR&0x01)==0);
	a=U0RBR;
	delay();
}	