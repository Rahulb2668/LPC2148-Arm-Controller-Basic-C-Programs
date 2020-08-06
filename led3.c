#include<lpc21xx.h>
void delay()
{ for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++);
}
void main()
{int a;
	IO0DIR=0xFFFFFFFF;
	IO1DIR=0x00000000;
	while(1)
	{
		if((IO1PIN&0x00010000)==0)
		{
		a=0x00000400;
		delay();
		for(int i=1;i<11;i++)
		{
		 IO0SET=a;
			a=a<<1;
			delay();
			IO0CLR=0xffffffff;
			//delay();
			//IO0CLR=IO0CLR<<1;
			delay();
			}
		}
		else if((IO1PIN&0x00020000)==0)
		{
			IO0SET=0xffffffff;
			delay();
			IO0CLR=0xffffffff;
			delay();
		}
		else if((IO1PIN&0x00040000)==0)
		{
			IO0SET=0x00007c00;
			delay();
			IO0CLR=0x00007c00;
			delay();
			IO0SET=0x000f8000;
			delay();
			IO0CLR=0x000f8000;
		}
		
	}
}