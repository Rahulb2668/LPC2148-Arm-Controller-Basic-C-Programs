#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
char rece()
{
	while(!(U0LSR&0x01));
		return(U0RBR);
}
void trans(char b)
{
	U0THR=b;
	while(!(U0LSR&0x20));
}
void main()
{ char c;
	IO0SET=0xfffffffD;
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0x63;
	U0DLM=0x00;
	U0LCR=0x03;
	while(1)
	{
		c=rece();
		delay();
		trans(c);
		delay();
	}
}