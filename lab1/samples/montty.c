// montty.c

#include <stdio.h>
#include <threads.h>
#include <terminals.h>
#include <hardware.h>

// Declaration
// Interrupt Handlers
void ReceiveInterrupt(int term);

void TransmitInterrupt(int term);

// Device Driver API for User Threads
int WriteTerminal(int term, char *buf, int buflen);

int ReadTerminal(int term, char *buf, int buflen);


int InitTerminal(int term);


int TerminalDriverStatistics(struct termstat *stats);


int InitTerminalDriver();



// Implementation
// Interrupt Handlers
void ReceiveInterrupt(int term){

}

void TransmitInterrupt(int term){

}

// Device Driver API for User Threads
int WriteTerminal(int term, char *buf, int buflen){
	return 0;

}

int ReadTerminal(int term, char *buf, int buflen){
	return 0;

}


int InitTerminal(int term){
	InitHardware(term);
	return 0;

}


int TerminalDriverStatistics(struct termstat *stats){
	return 0;

}


int InitTerminalDriver(){
	return 0;

}
