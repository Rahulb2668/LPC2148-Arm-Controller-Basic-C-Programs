#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++);
}
__irq void test()
{
	IO1SET=0Xffff0000;
 delay();
	IO1CLR=0Xffff0000;
	delay();
	EXTINT=0X01;
	VICVectAddr=0;
} 
void main()
{ 
	PINSEL0=0X0000000C;
	IO0DIR=0X00000000;
	 EXTMODE |=1;      // Edge sensitive mode on EINT1
 EXTPOLAR =0;  
	IO1DIR=0xFFFFFFFF;
	VICVectCntl0=0x0000002E;
	EXTINT=0x01;
	VICVectAddr0=(unsigned) test;
	VICIntEnable=0x00004000;
	while(1)
	{
		IO1SET=0Xff000000;
		delay();
		IO1CLR=0Xff000000;
		delay();
	}

}

		
	