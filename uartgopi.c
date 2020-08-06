#include<lpc21xx.h>
void delay()
{
	int i,j;
	for(i=0;i<300;i++)
	for(j=0;j<300;j++);
}
void main()
{
	char a;
	IO0DIR=0XFFFFFFFF;
	PINSEL0=0X00000005;
	U0LCR=0X83;
	U0DLL=0X63;
	U0DLM=0X00;
	U0LCR=0X03;
	while(1)
	{
		while((U0LSR&0X01)==0);
		a=U0RBR;
		delay();
		U0THR=a;
		while((U0LSR&0X20)==0);
		delay();
	}
}
