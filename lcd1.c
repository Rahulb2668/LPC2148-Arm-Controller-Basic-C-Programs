#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<200;j++);
}
void cmd(int a)
{
	IO0CLR=0xffffffff;
 IO0SET=a<<2;
 IO0SET=0x00000002;
	delay();
 IO0CLR=0x00000002;
}
void data(int b)
{IO0CLR=0xffffffff;
	IO0SET=b<<2;
	IO0SET=0x00000003;
	delay();
 IO0CLR=0x00000002;
}
void display(char *p)
{
	while(*p!='\0')
	{
		data(*p);
		p++;
	}
}
void main()
{ 
	
	IO0DIR=0xFFFFFFFF;
	IO1DIR=0x00000000;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0e);
	while(1)
	{
		data('a');
	}			
}
	
	
	