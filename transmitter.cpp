/*
 * transmitter.cpp
 *
 * Created: 13/05/2020 10:16:12
 *  Author: Emil Engstroem
 * Updated transmitter
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "transmitter.hpp"
#include "uart.hpp"

volatile int globalProtocol[16];
volatile int globalN;

char HouseData[8];
char FunctionData[8];
char UnitData[8];

void InitInterrupt4()
{
	EIMSK = 0b00000000; //Just to clear
	EICRA = 0b00000001; //enable interrupt, any edge
	EICRB = 0b00000001; //enable interrupt, any edge
	EIMSK = 0b00010000; //enable external interrupts, pin 4
	TIFR4 |= 0b00000001;
};

void disableInterrupt4()
{
	EIMSK = 0b00000000;
	EICRA = 0b00000000; 
	EICRB = 0b00000000; //Disable all
	EIMSK = 0b00000000; 
	TIFR4 |= 0b00000000;
};

//void X10ManchesterEncoding(char * data)
//{
	//
	//sendX10Data()
//}

void sendX10Data(int p0, int p1, int p2, //
 int p3, int p4, int p5, int p6, int p7, int p8,
int p9, int p10, int p11, int p12, int p13, int p14, int p15)
{
	//while(globalN < 8)_delay_us(1);

	if ( p0 != 0) globalProtocol[0] = 1;
	else          globalProtocol[0] = 0;
	if ( p1 != 0) globalProtocol[1] = 1;
	else          globalProtocol[1] = 0;
	if ( p2 != 0) globalProtocol[2] = 1;
	else          globalProtocol[2] = 0;
	if ( p3 != 0) globalProtocol[3] = 1;
	else          globalProtocol[3] = 0;
	if ( p4 != 0) globalProtocol[4] = 1;
	else          globalProtocol[4] = 0;
	if ( p5 != 0) globalProtocol[5] = 1;
	else          globalProtocol[5] = 0;
	if ( p6 != 0) globalProtocol[6] = 1;
	else          globalProtocol[6] = 0;
	if ( p7 != 0) globalProtocol[7] = 1;
	else          globalProtocol[7] = 0;
	if ( p8 != 0) globalProtocol[8] = 1;
	else          globalProtocol[8] = 0;
	if ( p9 != 0) globalProtocol[9] = 1;
	else          globalProtocol[9] = 0;
	if ( p10 != 0) globalProtocol[10] = 1;
	else          globalProtocol[10] = 0;
	if ( p11 != 0) globalProtocol[11] = 1;
	else          globalProtocol[11] = 0;
	if ( p12 != 0) globalProtocol[12] = 1;
	else          globalProtocol[12] = 0;
	if ( p13 != 0) globalProtocol[13] = 1;
	else          globalProtocol[13] = 0;
	if ( p14 != 0) globalProtocol[14] = 1;
	else          globalProtocol[14] = 0;
	if ( p15 != 0) globalProtocol[15] = 1;
	else          globalProtocol[15] = 0;
	
	globalN = -1;
	InitInterrupt4();
	
	
};

void enableTimer1()
{
	// Set PB2 as output
	DDRB = 0b00000100;
	
	
	TCCR1A = 0b01000000; //Toggle OC1A on compare match 
	TCCR1B = 0b00001001; // Bit = 3 CTC mode, Bit 0 = Prescale 1
	
	
	OCR1A = 133; //Top is OCR1A, 16Mhz/120kHz
}