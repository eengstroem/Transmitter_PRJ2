/*
 * Transmitter.cpp
 *
 * Created: 22-04-2020 14:38:49
 * Author : Gustav
 */ 

#include <avr/io.h>
#define F_CPU 16000000		//Frequency
#define BAUD 9600		//Baud rate
#define BRC	((F_CPU/16/BAUD) - 1)	//Baud rate calculation and register

int main(void)
{
   UBRR0H = (BRC >> 8);   //Set most and least important bits, according to green book
   UBRR0L = BRC;
   
   UCSR0B = (1 << TXEN0);
   UCSR0B = (1 << UCSZ01) | (1 << UCSZ00);

    while (1) 
    {
      UDR0 = '0001';
    }
}


