#include <p18f4580.h>

#define RS PORTCbits.RC0
#define E PORTCbits.RC1

#define DELAY_COUNT 100

void Lcd_Cmd(char);
void Lcd_Init(void);
void Lcd_Data(char);
void Lcd_String(char*);
void Delay(int);

void main(void)
{
	char arr[] = "Raju Malekar";
// PORTS and BIts Directions
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;

	TRISD = 0x00;

// LCD init
	Lcd_Init();

	while(1)
	{
		Lcd_String(arr);
		Lcd_Cmd(0x01);
	}
}

void Lcd_Init(void)
{
	Lcd_Cmd(0x38);  // 8-bit mode, 2 lines
	Lcd_Cmd(0x0E);  // Display ON, cursor ON
	Lcd_Cmd(0x06);  // Entry mode: move cursor right
	Lcd_Cmd(0x01);  // Clear display
	Lcd_Cmd(0x80);  // Cursor at first line, first position
}

void Lcd_Cmd(char ch)
{
	PORTD = ch;
	RS = 0; // command mode
//	RW = 0; connected to ground 
	E = 1;
	Delay(DELAY_COUNT);
	E = 0;
}

void Lcd_Data(char ch)
{
	PORTD = ch;
	RS = 1; // data mode
//	RW = 0; connected to ground 
	E = 1;
	Delay(DELAY_COUNT);
	E = 0;
}

void Lcd_String(char *str)
{
		while(*str != '\0')
		{
			Lcd_Data(*str);
			str++;
		}	
}

void Delay(int x)
{
	int i,j;
		for(i=0; i<x; i++)
			for(j=0; j<x; j++);
}
