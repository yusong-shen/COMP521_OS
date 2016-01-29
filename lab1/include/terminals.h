/*
 * tty.h
 *
 * Definitions of the the user level routines you must implement.
 */

#ifndef _tty_h
#define _tty_h

/*
 * Output buflen chars from buf to screen, blocking until all characters
 * are displayed.  Returns the number of characters written or -1 for 
 * error. Writes to terminal term.
 */
int WriteTerminal(int term, char *buf, int buflen);

/*
 * Read characters from terminal and place into buf until buflen chars
 * have been read or a '\n' is read.  Returns the number of characters
 * read or -1 for error.  Like the Unix read() call but unlike normal
 * C programming language strings, no null character is automatically
 * added onto the end of the buffer by this call.  Reads from
 * terminal term.
 */
int ReadTerminal(int term, char *buf, int buflen);

/*
 * Must be called once by application before any invocation of 
 * WriteTerminal or ReadTerminal on terminal number term.  Must call
 * the hardware's InitHardware for term.  Returns 0 if OK, or -1
 * for any error.
 */
int InitTerminal(int term);

/*
 * Returns a consistent snapshot of the I/O statistics for all
 * terminals.  The results are returned in the structure pointed
 * to by stats, with the statistics for each terminal number i in
 * stats[i].  If some terminal number i is not yet initialized,
 * all statistics for it should be -1.  Returns 0 if OK, or -1 for
 * any error.
 */
struct termstat {
	int tty_in;	/* # of chars received from terminal for this term */
	int tty_out;	/* # of chars sent to terminal for this term */
	int user_in;	/* # of chars received from users for this term */
	int user_out;	/* # of chars returned to users for this term */
};
int TerminalDriverStatistics(struct termstat *stats);

/*
 * Must be called exactly once before any other terminal API calls.
 * Initializes the terminal driver itself, not any particular
 * terminal.  Returns 0 if OK, or -1 for any error.
 */
int InitTerminalDriver(void);

/*
 * Additional definitions for user programs:
 */

/*
 * The following two functions are really hardware interfaces,
 * but for this project, they are available to for user programs
 * to use so that you can test different timing settings
 * more easily.  You can call these functions from an application
 * thread.
 */
int HardwareOutputSpeed(int term, int msecs);
int HardwareInputSpeed(int term, int msecs);

#endif /* _tty_h */
