#include<lpc21xx.h>
void delay();
void main()
{
	IO0DIR=0XFFFFFFFF;
	while(1)
	{
   IO0SET=0X00000003;
		delay();
	 IO0CLR=0x00000003;
		delay();
	 IO0SET=0X00000030;
		delay();
		IO0CLR=0X00000030;
		delay();
		IO0SET=0X00000300;
		delay();
		IO0CLR=0X00000300;
		delay();
		IO0SET=0X00003000;
		delay();
		IO0CLR=0X00003000;
		delay();
		IO0SET=0X00030000;
		delay();
		IO0CLR=0X00030000;
		delay();
		IO0SET=0X00300000;
		delay();
		IO0CLR=0X00300000;
		delay();
		IO0SET=0X03000000;
		delay();
		IO0CLR=0X03000000;
		delay();
		IO0SET=0X30000000;
		delay();
		IO0CLR=0X30000000;
		delay();
	}
}
void delay()
{
	int i,j;
	for(i=0;i<300;i++)
	for(j=0;j<300;j++);
}