// 3 Led : Led 1,2,3==RB1,2 3

#include <p18f4580.h>

#define LED1 PORTBbits.RB1
#define LED2 PORTBbits.RB2
#define LED3 PORTBbits.RB3

#define DELAY_COUNT 100

void Delay(int);

void main(void)
{
	TRISBbits.RB1 = 0;
	TRISBbits.RB2 = 0;
	TRISBbits.RB3 = 0;

	ADCON1 = 0x0F;

	while(1)
	{
		LED1 = 1;
		Delay(DELAY_COUNT);
		LED1 = 0;
		Delay(DELAY_COUNT);

		LED2 = 1;
		Delay(DELAY_COUNT);
		LED2 = 0;
		Delay(DELAY_COUNT);

		LED3 = 1;
		Delay(DELAY_COUNT);
		LED3 = 0;
		Delay(DELAY_COUNT);
	}

}

void Delay(int x)
{
	int i,j;
	for(i=0; i<x; i++)
		for(j=0; j<x; j++);
}