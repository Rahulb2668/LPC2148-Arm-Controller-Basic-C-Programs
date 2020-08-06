#include<lpc21xx.h>
void cmd(char a);
void data(char b);
void delay();
void display(const char *g);
void main()
{
	IO1DIR=0XFFFFFFFF;
	IO0CLR=0xffffffff;
	IO0DIR=0XFFFFFF0F;
	cmd(0X38);
	cmd(0X80);
	cmd(0X01);
	cmd(0X06);
	cmd(0X0E);
	while(1)
	{
	IO0SET=0X000000FE;
	if((IO0PIN&0X00000010)==0)
	{
		display("one");
	}
//	if((IO0PIN&0X00000020)==0)
//	{
//		display("two");
//	}
//	if((IO0PIN&0X00000040)==0)
//	{
//		display("three");
//	}
//	if((IO0PIN&0X00000080)==0)
//	{
//		display("four");
//	}

	}
  }
void cmd(char a)
{
	IO1CLR=0XFFFFFFFF;
	IO1SET=a<<16;
	IO1SET=0X01000000;
	delay(700);
	IO1CLR=0X01000000;
}
void data(char b)
{
	IO1CLR=0XFFFFFFFF;
	IO1SET=b<<16;
	IO1SET=0X03000000;
	delay(700);
	IO1CLR=0X01000000;
}
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<1000;j++);
}
void display(const char *g)
{
	while(*g!='\0')
	{
		data(*g);
		g++;
	}
}