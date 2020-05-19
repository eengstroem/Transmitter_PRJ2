/*
 * transmitter.cpp
 *
 * Created: 13/05/2020 10:51:43
 *  Author: Emil Engstroem
 */ 
#ifndef TRANSMITTER_H_ //Header guard
#define TRANSMITTER_H_

	
	
void sendX10Data(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8,
int p9, int p10, int p11, int p12, int p13, int p14, int p15);
void InitInterrupt4();
void disableInterrupt4();
void enableTimer1();

extern volatile int globalProtocol[16];
extern volatile int globalN;
extern char HouseData[8];
extern char FunctionData[8];
extern char UnitData[8];


#endif /* TRANSMITTER_H_ */