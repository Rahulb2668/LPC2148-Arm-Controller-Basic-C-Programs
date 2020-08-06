#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++);
}
void main()
{
	IO0DIR=0XFFFFFFFF;
	while(1)
	{
   IO0SET=0X0007FE00;
		delay();
	 IO0CLR=0x0007FE00;
		delay();
	}
}