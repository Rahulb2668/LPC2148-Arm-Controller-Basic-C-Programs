#include<lpc21xx.h>
void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<a;j++);
}
void cmd(int a)
{
IO1CLR=0XFFFFFFFF;
int x;
x=a&0XF0;//READING MSB
IO1SET=x<<16;//DATA PINS ON THE 20 PIN
IO1SET=0X00080000;//ENABLE ON 19TH PIN RSON 17TH PIN
delay(200);
IO1CLR=0X00080000;//TOGLED ENABLE
delay(200);
IO1CLR=0XFFFFFFFF;
x=a&0X0F;//READING LSB
IO1SET=x<<20;//SHIFTING TO 20TH PIN
IO1SET=0X00080000;
delay(200);
IO1CLR=0X00080000;
}
void data(int b)
{
	IO1CLR=0XFFFFFFFF;
	int x;
	x=b&0XF0;
	IO1SET=x<<16;
	IO1SET=0X000A0000;
	delay(200);
	IO1CLR=0X00080000;
	delay(200);
	IO1CLR=0XFFFFFFFF;
	x=b&0X0F;
	IO1SET=x<<20;
	IO1SET=0X000A0000;
	delay(200);
	IO1CLR=0X00080000;
}
void display(char *p)
{
	while(*p!='\0')
	{data(*p);
		p++;
	}
}

void hour(int hr)
{   char a,b;
 		a=(hr/10)+48;
		b=(hr%10)+48;
	  cmd(0xc5);
		data(a);data(b);
		data(':');
}
void minute(int min)
{   char a,b;
 		a=(min/10)+48;
		b=(min%10)+48;
	cmd(0xc8);
		data(a);data(b);
		data(':');	   
}
void second(int sec)
{   char a,b;
 		a=(sec/10)+48;
		b=(sec%10)+48;
	cmd(0xcb);
		data(a);data(b);
}
int timeset(int hr,int min,int sec)
{
	int e;
	  IO0SET=0X0001FC00;
    e=IO0PIN&0X00003C00;
    switch(e)
		{
			case(0X00003400):hr++;
			return(hr);
			case(0x00002c00):min++;
			return(min);
			case(0x00001c00):sec++;
			return(sec);
		}
	}
			
void main()
{ 
	int hr,min,sec;
  int count=1;
	IO1DIR=0XFFFFFFFF;
	IO0DIR=0X00000000;
	IO0CLR=0X0003C000;
	int e;
	cmd(0x02);
	cmd(0x28);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	hr=11;min=59;sec=49;
/***************************1st printing**************/	 
	cmd(0x84);
		display("WELCOME");
		delay(200);
		cmd(0XC0);
		display("TIME:");
    hour(hr);
    minute(min);
    second(sec);
	/************************************/
	while(1)
	{
	  sec++;
	  second(sec);
		minute(min);
		hour(hr);
		  delay(100);
			if(sec==60)
				{  
					sec=0;
					
          min++;
				}					
			if(min==60)
			{
				min=0;
				hr++;
			}
			if(hr>12)
			{
				hr=1;
			}
		IO0SET=0X0001FC00;
    e=IO0PIN&0X00003C00;
    switch(e)
		{
			case(0X00003800):timeset(hr,min,sec);			
		}
		
	}
}			
