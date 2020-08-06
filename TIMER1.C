#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void main()
{
	IO1DIR=0XFFFFFFFF;
	T0TCR=0X01;//ENABLE
	T0TC=0X00000000;//TIMER COUNTER
	T0PR=0X000000FF;//PRESCALER
	T0PC=0X00000000;//PRECALER VALUE
	T0MCR=0X00000003;//MATCH  CONTROL// interrupt setted alenki flag setaavoola
	T0MR0=0X00000FFF;//MATCH REG
	while(1)
	{
		IO1SET=0XFFFFFFFF;
		while(!(T0IR&0X01));//FLAG
		T0IR=0X01;
		IO1CLR=0XFFFFFFFF;
		while(!(T0IR&0X01));//FLAG
		T0IR=0X01;
	}
}
		

	
	