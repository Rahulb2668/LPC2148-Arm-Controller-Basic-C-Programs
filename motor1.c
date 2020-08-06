#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void main()
{
	IO0DIR=0x00000007;
	while(1)
{
//	//IO0SET=0x00000005;
//	delay();
//	IO0CLR=0x00000007;
//	delay();
	IO0SET=0x00000006;
	delay();
	IO0CLR=0x00000007;
	delay();
	}
}
	
	