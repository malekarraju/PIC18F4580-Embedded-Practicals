#include <p18f4580.h>

void Delay(int);
void main(void)
{
	char arr[] = "Raju Malekar ";
	char *str;

	TRISCbits.RC6 = 0;  // Transmitter
	TRISCbits.RC7 = 1; // Reciever

	// UART Init
	TXSTA = 0x24; // 0010 0100 	TX ENA. ASY. HIGH SPEED
	RCSTA = 0x90; // 1001 0000  RX ENA. 8 BIT CONFIG TX/RX, ERROR 0 init

	SPBRG = 0x81; // or 129, Set the baud rate generator value for EUSART communication

	while(1)
	{
		str = arr;
		while(*str != '\0')
		{
			while(PIR1bits.TXIF == 0); // Wait until TXREG is ready for new data

			TXREG = *str;   // Load the current character into TXREG
			Delay(100);
			
			Delay(100);
			
			str++;       // Move pointer to the next character
		}

				while(PIR1bits.TXIF == 0); // Wait until TXREG is ready for new data
			TXREG = '\r';
				while(PIR1bits.TXIF == 0); // Wait until TXREG is ready for new data
			TXREG = '\n';
		
	}

}

void Delay(int x)
{
	int i, j;
	 for(i=0; i<x; i++)
		for(j=0; j<x; j++);
}
