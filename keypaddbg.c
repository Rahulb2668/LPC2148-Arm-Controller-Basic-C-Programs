#include<lpc21xx.h>
void delay(){
	int i,j;
	for(i=0;i<500;i++)
	for(j=0;j<500;j++);
}
void main()
{
	IO0DIR=0X0003C000;
	IO1DIR=0XFFFFFFFF;
	IO0SET=0X0001FC00;
	int e;
	while(1)
	{
	IO0CLR=0XFFFFFFFF;
	e=IO0PIN&0X00003C00;
	switch(e)
	{
		case(0x00003800):IO1SET=0X00010000;
		delay();
		IO1CLR=0X00010000;
		case(0x00003400):IO1SET=0x00020000;
		case(0X00002C00):IO1SET=0X00040000;
		case(0X00001C00):IO1SET=0X00080000;
	}
}
}