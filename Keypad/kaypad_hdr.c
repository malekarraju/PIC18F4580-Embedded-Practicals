#include<p18f4580.h>
#define rs PORTCbits.RC0
#define en PORTCbits.RC1

void cmd(char);
void dat(char);
void delay(int);
void lcd_init();

void delay(int a){
 int i,j;
 for(i=0;i<a;i++)
 for(j=0;j<233;j++);
}

void main(){
   ADCON1=0X0F; //CONFIG ALL PINS TO DIGITAL I/P & O/P TO ANALOG
   TRISC=0X00;
   TRISD=0X00;
   TRISB=0X00;  //COL I/P AND ROW O/P
   
   lcd_init();

while(1){
//SCAN R1
PORTB=0XFE; //r1=0 & r2=r3=r4=1
if(PORTB==0XEE)
{
 dat('7');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XDE)
{
 dat('8');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XBE)
{
 dat('9');
 delay(100);
 cmd(0X01);
}
if(PORTB==0X7E)
{
 dat('/');
 delay(100);
 cmd(0X01);
}

//r2=0 & r1=r3=r4=1
PORTB=0XFD;
if(PORTB==0XED)
{
 dat('4');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XDD)
{
 dat('5');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XBD)
{
 dat('6');
 delay(100);
 cmd(0X01);
}
if(PORTB==0X7D)
{
 dat('*');
 delay(100);
 cmd(0X01);
}

//r3=0 & r1=r2=r4=1
PORTB=0XFB;
if(PORTB==0XEB)
{
 dat('1');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XDB)
{
 dat('2');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XBB)
{
 dat('3');
 delay(100);
 cmd(0X01);
}
if(PORTB==0X7B)
{
 dat('-');
 delay(100);
 cmd(0X01);
}

//r4=0 & r1=r2=r3=1
PORTB=0XF7;
if(PORTB==0XE7)
{
 dat('C');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XD7)
{
 dat('0');
 delay(100);
 cmd(0X01);
}
if(PORTB==0XB7)
{
 dat('=');
 delay(100);
 cmd(0X01);
}
if(PORTB==0X77)
{
 dat('+');
 delay(100);
 cmd(0X01);
}
}
}

void cmd(char a)
{
 PORTD=a;
 rs=0;
 en=1;
 delay(10);
 en=0;
}

void dat(char b)
{
 PORTD=b;
 rs=1;
 en=1;
 delay(10);
 en=0;
}

void lcd_init()
{
 cmd(0X38);
 delay(100);
 cmd(0X0E);
 delay(100);
 cmd(0X01);
 delay(100);
 cmd(0X80);
 delay(100);
 cmd(0X06);
 delay(100);
}