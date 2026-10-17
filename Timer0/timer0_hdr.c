#include <p18f4580.h>

#define LED PORTCbits.RC0

void T0_Delay(void);

void main(void)
{
    TRISCbits.RC0 = 0;    // RC0 as output
    T0CON = 0x07;            // 16-bit, Fosc/4, prescaler 1:256, timer off

    while(1)
    {
        LED = 1;
        T0_Delay();          // 1 s ON
        LED = 0;
        T0_Delay();          // 1 s OFF
    }
}

void T0_Delay(void)
{
    TMR0H = 0xB3;            // Write high byte first
    TMR0L = 0xB5;            // Preload = 0xB3B5 = 46005 -> 19531 counts
    T0CONbits.TMR0ON = 1;

    while(INTCONbits.TMR0IF == 0);

    T0CONbits.TMR0ON = 0;
    INTCONbits.TMR0IF = 0;
}