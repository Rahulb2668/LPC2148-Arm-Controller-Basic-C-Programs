#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++);
}
void cmd(int a)
{
	IO1CLR=0XFFFFFFFF;
	IO1SET=a<<18;
	IO1SET=0X00020000;
	delay();
	IO1CLR=0X00020000;
}
void data(char b)
{
	IO1CLR=0XFFFFFFFF;
	IO1SET=b<<18;
	IO1SET=0X00030000;
	delay();
	IO1CLR=0X00020000;
}
void main()
	{ 
	int a;
	char p,q,r,s;
	IO0DIR=0XF7FFFFFF;
	IO1DIR=0XFFFFFFFF;
	PINSEL1=0X00040000;
		cmd(0x38);
		cmd(0x01);
		cmd(0x80);
		cmd(0x06);
		cmd(0x0E);
		//data('q');
	while(1)
	{
		ADCR=0X01200001;
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
		if(a>=500)
		{
			IO1SET=0XA0000000;
			delay();
		}			
		delay();
		cmd(0x01);
	}
	
}
		
	