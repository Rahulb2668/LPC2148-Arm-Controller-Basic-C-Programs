#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void cmd(int a)
{
	IO0CLR=0xffffffff;
	IO0SET=a<<2;
	IO0SET=0x00000002;
	delay();
	IO0CLR=0x00000002;
}
void data(int b)
{
	IO0CLR=0xFFFFFFFF;
	IO0SET=b<<2;
	IO0SET=0x00000003;
	delay();
	IO0CLR=0x00000002;
}
void main()
{ int e;
	IO0DIR=0xffffffff;
	IO1DIR=0x000F0000;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	while(1)
	{ IO1CLR=0xffffffff;
		IO1SET=0x00FE0000;
		e=IO1PIN&0x00F00000;
		switch(e)
		{
			case(0x00E00000):data('1');break;
			case(0x00D00000):data('2');break;
			case(0x00B00000):data('3');break;
			case(0x00700000):data('4');break;
		}
		IO1CLR=0xffffffff;
		IO1SET=0x00FD0000;
		e=IO1PIN&0x00F00000;
		switch(e)
		{
			case(0x00E00000):data('5');break;
			case(0x00D00000):data('6');break;
			case(0x00B00000):data('7');break;
			case(0x00700000):data('8');break;
		}
		IO1CLR=0xffffffff;
		IO1SET=0x00FB0000;
		e=IO1PIN&0x00F00000;
		switch(e)
		{
			case(0x00E00000):data('9');break;
			case(0x00D00000):data('A');break;
			case(0x00B00000):data('B');break;
			case(0x00700000):data('C');break;
		}
		IO1CLR=0xffffffff;
		IO1SET=0x00F70000;
		e=IO1PIN&0x00F00000;
		switch(e)
		{
			case(0x00E00000):data('D');break;
			case(0x00D00000):data('E');break;
			case(0x00B00000):data('F');break;
			case(0x00700000):data('G');break;
		}
	}
}
		