#include<p18f4580.h>

#define LED PORTBbits.RB1

void main()
{
	 char read;
	 TRISCbits.RC6 = 0; //Tx
	 TRISCbits.RC7 = 1; //Rx
	 TRISBbits.RB1 = 0; //LED

	ADCON1 = 0x0F;

//	UART RC INIT

	TXSTA = 0X24;//TX ENA. ASY. HIGH SPEED
	RCSTA = 0X90;//RX ENA. 8 BIT CONFIG TX/RX
	SPBRG = 0X81;// or 129 D B.R. = 9600
	
LED = 0;
	while(1)
	{ 	
		while(PIR1bits.RCIF==0);//wait for data receive
		read = RCREG; //COPY RECEIVE DATA INTO VARIABLE
	
		switch(read)
		{
			case '1':
			LED = 1;
			break;
			case '0':
			LED = 0;
			break;
			
		}
	}
}