#include<lpc21xx.h>
int count=0,change=0;
int seconds=56;
int hour=11;
int mins=59;
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
delay(200);
IO1CLR=0X00080000;//TOGLED ENABLE
delay(200);
IO1CLR=0XFFFFFFFF;
x=a&0X0F;//READING LSB
IO1SET=x<<20;//SHIFTING TO 20TH PIN
IO1SET=0X00080000;
delay(200);
IO1CLR=0X00080000;
}
void data(int b)
{
	IO1CLR=0XFFFFFFFF;
	int x;
	x=b&0XF0;
	IO1SET=x<<16;
	IO1SET=0X000A0000;
	delay(200);
	IO1CLR=0X00080000;
	delay(200);
	IO1CLR=0XFFFFFFFF;
	x=b&0X0F;
	IO1SET=x<<20;
	IO1SET=0X000A0000;
	delay(200);
	IO1CLR=0X00080000;
}
void display(char *p)
{
	while(*p!='\0')
	{data(*p);
		p++;
	}
}
void timer_init()
{
	T0TCR=0X01;
	T0MR0=4999999;
	T0TC=0X00000000;
	T0PR=0X00000000;
	T0PC=0X00000000;
	T0MCR=0X00000003;//MATCH  CONTROL// interrupt setted alenki flag setaavoola	
}
__irq void interrupt()
{ 
	if((T0IR&0x01)==1)
	{		
    count++;
		T0IR=0x01;
	  VICVectAddr=0;
	}
}
void hours(int hr)
{   char a,b;
 		a=(hr/10)+48;
		b=(hr%10)+48;
	  cmd(0xc5);
		data(a);data(b);
		data(':');
}
void minute(int min)
{   char a,b;
 		a=(min/10)+48;
		b=(min%10)+48;
	cmd(0xc8);
		data(a);data(b);
		data(':');	   
}
void second(int sec)
{   char a,b;
 		a=(sec/10)+48;
		b=(sec%10)+48;
	cmd(0xcb);
		data(a);data(b);
}


void main()
{ int e;
	IO1DIR=0XFFFFFFFF;
	IO0DIR=0X00020000;
	IO0CLR=0X00023c00;
	PINSEL0=0x00000080;//timer mr0;
	VICIntEnable=0x00000010;//4th channel selected
	VICVectCntl0=0x00000024;//4th channel by 2nd bit
	VICVectAddr0=(unsigned)interrupt;
	cmd(0x02);
	cmd(0x28);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	cmd(0x84);
	timer_init();
	display("WELCOME");
	delay(200);
	cmd(0XC0);
	display("TIME:");
	change=0;
	while(1)
	{
	if(count==1)
	{
		seconds++;
		count=0;
		change=1;
	}
	if(seconds==60)
	{
		mins++;
		seconds=0;
		change=1;
	}
	if(mins==60)
	{
		hour++;
		mins=0;
		change=1;
	}
	if(change==1)
	{
		hours(hour);
		minute(mins);
		second(seconds);
	}
	IO0SET=0X0003C00;
	e=IO0PIN&0X00003C00;
		if(e==0x00003800)
		{
			cmd(0x01);
	display("change time");
	hours(hour);
	minute(mins);
	second(seconds);
	IO0SET=0X00003c00;
	int e;
	IO0CLR=0XFFFFFFFF;
	e=IO0PIN&0X00003C00;
	while(e!=0x00003800)
	{
		hours(hour);
	minute(mins);
	second(seconds);
		if(e==0x00003400)
			{hour++;
		hours(hour);
			}
		else if(e==0X00002C00){
			mins++;
		minute(mins);
		}
		else if(e==0X00001C00)
			{
			seconds++;
		second(seconds);
	}
		
		}

	}
	}
}