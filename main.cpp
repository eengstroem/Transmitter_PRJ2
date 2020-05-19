/*
 * main.cpp
 *
 * Created: 13/05/2020 10:07:47
 *  Author: Emil Engstroem
 *Updated main.cpp
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "transmitter.hpp"
#include "uart.hpp"


int main()
{
	InitUART(9600, 8, 'N'); //Init UART, with all the info
	sei(); //global interrupt enabled
	DDRA = 0;
	DDRB = 0xFF;
	DDRD = 0x00;
	int BreakLoop = 0;
	
	while(1)
	{
		SendChar('A');
		
		
		if(CharReady()){
		char checkbuffer[1] = {0};
		checkbuffer[0] = ReadChar();
		if(checkbuffer[0] == 'A'){
		BreakLoop = 1;
		
		}
		}
			char buffer[1]= {0};
			while(!CharReady())
			{
				_delay_us(1);
			}
			buffer[0]=ReadChar();
			
			if(buffer[0] == 'A')
			{
				sendX10Data(1,1,1,0, 0,1,0,1, 1,0,0,1, 1,0,1,1 ); // test
			}
			if(buffer[0] == 'B')
			{
				sendX10Data(1,1,1,0, 0,1,0,1, 1,0,1,1, 1,0,1,1); // test
			};
		}
		
	
	
	
}

ISR(INT4_vect)
{
	if( globalN < 16)
	{
		++globalN;
		int p = globalProtocol[globalN];
		if (p == 1)
		{
			
			//Start Timer 1, to get the 120kHZ. 120k signals/s
			enableTimer1();
			TCCR1A = 0b01000000;
			
			_delay_ms(1);
			
			//
			TCCR1A = 0b00000000;
			
		}
		
	}
	
	EIFR = 0x00;
};
