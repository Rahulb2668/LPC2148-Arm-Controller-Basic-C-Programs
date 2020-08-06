#include<lpc21xx.h>
void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<a;j++);
}
void cmd(int a)
{
IO1CLR=0XFFFFFFFF;
int x;
x=a&0XF0;//READING MSB
IO1SET=x<<16;//DATA PINS ON THE 20 PIN
IO1SET=0X00080000;//ENABLE ON 19TH PIN RSON 17TH PIN
delay(1000);
IO1CLR=0X00080000;//TOGLED ENABLE
delay();
IO1CLR=0XFFFFFFFF;
x=a&0X0F;//READING LSB
IO1SET=x<<20;//SHIFTING TO 20TH PIN
IO1SET=0X00080000;
delay(1000);
IO1CLR=0X00080000;
delay();
}
void data(int b)
{
	IO1CLR=0XFFFFFFFF;
	int x;
	x=b&0XF0;
	IO1SET=x<<16;
	IO1SET=0X000A0000;
	delay();
	IO1CLR=0X00080000;
	delay();
	IO1CLR=0XFFFFFFFF;
	x=b&0X0F;
	IO1SET=x<<20;
	IO1SET=0X000A0000;
	delay();
	IO1CLR=0X00080000;
	delay();
}
void main()
{
	IO1DIR=0XFFFFFFFF;
	cmd(0x02);
	cmd(0x28);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	while(1);
	{
		data('A');
		cmd(0X01);
	}
}

	
 
