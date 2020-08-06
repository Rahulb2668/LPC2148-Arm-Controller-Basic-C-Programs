#include<lpc21xx.h>
void delay()
{
	for(int i=0;i<300;i++)
	for(int j=0;j<300;j++);
}
void cmd(char a)
{
	  IO0CLR=0xffffffff;
    IO0SET=a<<2;
    IO0SET=0x00000002;
	  delay();
    IO0CLR=0x00000002;
}
void data(char b)
{
  IO0CLR=0xffffffff;
	IO0SET=b<<2;
	IO0SET=0x00000003;
	delay();
  IO0CLR=0x00000002;
}
void main()
{
  IO0DIR=0xFFFFFFFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	while(1)
	{
	IO0CLR=0xffffffff;
	data('a');
	}
	}