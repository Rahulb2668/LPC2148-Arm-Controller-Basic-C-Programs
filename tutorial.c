#include<lpc21xx.h>
void delay(int i)
{
	int a,b;
	for(a=0;a<i;a++)
	for(b=0;b<i;b++);
}
void main()
{
	IO1DIR &= ~((1<<20));
	IO0DIR |= (1<<5)|(1<<6)|(1<<7)|(1<<8);
	
	while(1)
	{
		IO0SET|=(1<<5)|(1<<6);
		delay(2000);
			IO0CLR|=(1<<5)|(1<<6);
			delay(1000);
		if(!(IO1PIN & (1<<20)))
		{
			IO0SET|=(1<<7)|(1<<8);
			delay(2000);			
			IO0CLR|=(1<<7)|(1<<8);
			delay(1000);
			
		}
	}
}