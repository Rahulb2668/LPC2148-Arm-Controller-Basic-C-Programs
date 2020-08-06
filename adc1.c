#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void cmd(int a)
{
	IO0CLR=0XFFFFFFFF;
	IO0SET=a<<4;
	IO0SET=0X00000008;
	delay();
	IO0CLR=0X00000008;
}
void data(char b)
{
	IO0CLR=0XFFFFFFFF;
	IO0SET=b<<4;
	IO0SET=0X0000000C;
	delay();
	IO0CLR=0X00000008;
}
void main()
	{ 
	int a;
	char p,q,r,s;
	IO0DIR=0XF7FFFFFF;
	PINSEL1=0X00040000;
	ADCR=0X01200001;
		cmd(0x38);
		cmd(0x01);
		cmd(0x80);
		cmd(0x06);
		cmd(0x0E);
		data('q');
	while(1)
	{
		while(!(ADDR&0X80000000));
		a=(ADDR&0X0000FFC0);
		a=a>>6;
		p=(a/1000)+48;
		q=((a%1000)/100)+48;
		r=((a%100)/10)+48;
		s=(a%10)+48;
		data(p);
		data(q);
		data(r);
		data(s);
		delay();
		cmd(0x01);
	}
}
		
	