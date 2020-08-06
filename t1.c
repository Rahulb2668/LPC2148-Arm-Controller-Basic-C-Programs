#include<lpc21xx.h>
void delay()
{int i,j;
for(i=0;i<1000;i++)
for(j=0;j<1000;j++);
}
void main()
{
 IO0DIR=0XFFFFFFFF;
	while(1)
	{
		IO0SET=0X000000FF;
		delay();
		IO0CLR=0X000000FF;
		delay();
	}
}