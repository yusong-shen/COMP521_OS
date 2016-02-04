// montty.c

#include <stdio.h>
#include <threads.h>
#include <terminals.h>
#include <hardware.h>

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
int InitTerminal(int term){
	InitHardware();
	return 0;
}


int InitTerminalDriver(){
	return 0;
}
