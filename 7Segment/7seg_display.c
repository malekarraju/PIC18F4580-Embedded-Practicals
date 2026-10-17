#include<p18f4580.h>

void T0_Delay(void);
void Delay_Count(int);

void main()
{
	char arr[]={0x03f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	int i;

	TRISC = 0x00;

	   //Timer Init
	T0CON = 0X07;//16 BIT,TIMER OFF,1:25

	while(1)
	{
		for(i=0; i<=9; i++)
		{	
			PORTC = arr[i];
			Delay_Count(20);  // 1 count for 100ms
		}
	}
}

void T0_Delay()
{
	// use main formula
		TMR0H = 0xFE;
		TMR0L = 0X78;


	T0CONbits.TMR0ON = 1;  // start timer0
	
	while(INTCONbits.TMR0IF==0); // wait for interrupt overflow
	INTCONbits.TMR0IF = 0;  // clear the flag bit
	
	T0CONbits.TMR0ON = 1;  // stop timer
}

void Delay_Count(int a)
{
	int i;
		for(i=0; i<a; i++) T0_Delay();
}
