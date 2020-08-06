#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void main()
{
	IO0DIR=0XFFFFFFFF;
	PINSEL0=0X00000002;
	PWMTCR=0X01;
	PWMTC=0X00000000;
	PWMPR=0X00000FFF;
	PWMPC=0X0000000F;
	PWMMCR=0X00000002;
  PWMPCR=0X00000200;
		PWMMR0=500;
	for(int i=0;i<500;i++)
	{
	PWMMR1=i;
		delay();
	}
	PWMLER=0X00000001;
}
  	
	

	