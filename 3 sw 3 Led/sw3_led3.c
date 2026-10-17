// 3 Led : Led 1,2,3==RB1,2 3

#include <p18f4580.h>

#define LED1 PORTBbits.RB1
#define LED2 PORTBbits.RB2
#define LED3 PORTBbits.RB3

#define SW1 PORTCbits.RC3
#define SW2 PORTCbits.RC2
#define SW3 PORTBbits.RB5

#define DELAY_COUNT 100

void Delay(int);

void main(void)
{
	TRISBbits.RB1 = 0;
	TRISBbits.RB2 = 0;
	TRISBbits.RB3 = 0;

	TRISCbits.RC3 = 1;
	TRISCbits.RC2 = 1;
	TRISBbits.RB5 = 1;

	ADCON1 = 0x0F;

	while(1)
	{
		if(SW1 == 0)
			LED1 = 1;
		else
			LED1 = 0;
	

		if(SW2 == 0)
			LED2 = 1;
		else
			LED2 = 0;
		

		if(SW3 == 0)
			LED3 = 1;
		else
			LED3 = 0;
	}

}