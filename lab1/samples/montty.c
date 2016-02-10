// montty.c
// Mesa Style Monitor for terminal device driver
// author : Yusong Shen

#include <stdio.h>
#include <threads.h>
#include <terminals.h>
#include <hardware.h>

// buffer for echo with size 512
static char echo_buffer[512];

// Implementation
// Interrupt Handlers -- Bottom Half

// This procedure is called by the hardware once for each character typed 
// on the keyboard of the terminal identified by terminal number term, 
// after that character has been placed in the input data register for 
// that terminal. 
// The character that caused the interrupt should be read 
// by your device driver from the input data register using the 
// ReadDataRegister() operation.
extern
void ReceiveInterrupt(int term){
	Declare_Monitor_Entry_Procedure();
  char ch = ReadDataRegister(term);
  echo_buffer[0] = ch;
  WriteDataRegister(term, ch);
}

// This procedure is called by the hardware once for each character 
// written to the output data register for the terminal identified 
// by terminal number term, after the character has been completely 
// transmitted to this terminal. 
// After executing a WriteDataRegister() operation, you must assume 
// that the output data register for that terminal is “busy” with 
// the transmission of that character until you receive the 
// corresponding transmit interrupt and your TransmitInterrupt() 
// procedure is called with this same terminal number.
extern
void TransmitInterrupt(int term){
	Declare_Monitor_Entry_Procedure();

  char ch = echo_buffer[0];
  WriteDataRegister(term, ch);
}


// Device Driver API for User Threads -- Top Half

/*
 * Output buflen chars from buf to screen, blocking until all characters
 * are displayed.  Returns the number of characters written or -1 for 
 * error. Writes to terminal term.
 */
extern
int WriteTerminal(int term, char *buf, int buflen){
	Declare_Monitor_Entry_Procedure();
  int i;
  for (i=0; i<buflen; i++){
    WriteDataRegister(term, *(buf+i));
  }

  return 0;

}

/*
 * Read characters from terminal and place into buf until buflen chars
 * have been read or a '\n' is read.  Returns the number of characters
 * read or -1 for error.  Like the Unix read() call but unlike normal
 * C programming language strings, no null character is automatically
 * added onto the end of the buffer by this call.  Reads from
 * terminal term.
 */
extern
int ReadTerminal(int term, char *buf, int buflen){
	Declare_Monitor_Entry_Procedure();	
	return 0;

}

// This procedure should be called once and only once, before any other 
// call to the terminal device driver procedures defined above are 
// called for terminal term.
extern
int InitTerminal(int term){
	Declare_Monitor_Entry_Procedure();
	return	InitHardware(term);

}


// This procedure returns a consistent snapshot of the I/O statistics for 
// all terminals all at once.
extern
int TerminalDriverStatistics(struct termstat *stats){
	Declare_Monitor_Entry_Procedure();

	return 0;

}


/*
 * Must be called exactly once before any other terminal API calls.
 * Initializes the terminal driver itself, not any particular
 * terminal.  Returns 0 if OK, or -1 for any error.
 */
extern
int InitTerminalDriver(){
	Declare_Monitor_Entry_Procedure();
	return 0;

}
