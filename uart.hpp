/*
 * uart.cpp
 *
 * Created: 13/05/2020 10:13:16
 *  Author: Henning Hargaard
 *  Author: Emil Engstroem
 */ 

void InitUART(unsigned long BaudRate, unsigned char DataBit, char Parity);
unsigned char CharReady();
char ReadChar();
void SendChar(char charToSend);
void SendString(char* stringToSend);
void SendInteger(int integerToSend);
/****************************************/
