#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<200;j++);
}
void cmd(int a)
{
 IO0CLR=0xffffffff;
 IO0SET=a<<4;
 IO0SET=0x00000008;
	delay();
 IO0CLR=0x00000008;
}
void data(int b)
{
	IO0CLR=0xffffffff;
	IO0SET=b<<4;
	IO0SET=0x0000000C;
	delay();
  IO0CLR=0x00000004;
}	
void main()
{ 
	char a;
	IO0DIR=0xFFFFFFFD;
	IO0CLR=0x00000000;
	PINSEL0=0x00000004;
	U0LCR=0x83;
	U0DLL=0x63;
	U0DLM=0x00;
	U0LCR=0x03;
  cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0e);
	while(1)
	{while((U0LSR&0x01)==0);
	a=U0RBR;
	
	data(a);
		delay();			
}
	}
	
	