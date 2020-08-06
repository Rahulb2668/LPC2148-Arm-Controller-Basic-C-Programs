#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<200;j++);
}
void cmd(char a)
{
	IO0CLR=0xffffffff;
    IO0SET=a;
    IO0SET=0x00000100;
	delay();
    IO0CLR=0x00000100;
}
void data(char b)
{
    IO0CLR=0xffffffff;
	IO0SET=b;
	IO0SET=0x00000300;
	delay();
    IO0CLR=0x00000200;
}
void main()
{
    IO0DIR=0xFFFFFFFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0e);
	while(1)
	{
	IO0CLR=0xffffffff;
	data('a');
	}
	}