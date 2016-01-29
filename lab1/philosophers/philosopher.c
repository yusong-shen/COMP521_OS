#include <stdio.h>

#include <threads.h>	/* COMP 421 threads package definitions */

/*
 * The state of each of the 5 philosophers: either THINKING, HUNGRY,
 * or EATING.
 * 
 * This is declared 'static' so it can't be seen outside this .c file.
 */
static int state[5];
#define	THINKING	0
#define	HUNGRY		1
#define	EATING		2

/*
 * A condition variable for each philosopher to wait on.  Declared 
 * 'static' as with all variables that should only be seen inside
 * this monitor.
 */
static cond_id_t philcond[5];

#define	LEFTPHIL	((i+1) % 5)	/* the philosopher to i's left */
#define	RIGHTPHIL	((i+4) % 5)	/* the philosopher to i's right */

static void test_forks(int);

/*
 * Pick up both of the forks for philosopher i.  Waits until
 * both forks are available.
 *
 * This is an entry procedure for the monitor, so:
 *   - it is an 'extern' function (any function not defined 'static'
 *     is automatically extern, according to the C language; and
 *   - it acquires the mutual exclusion of the monitor at the top
 *     and releases it at the bottom.
 */
extern void
pickup_forks(int i)
{
	/*
	 * You MUST use Declare_Monitor_Entry_Procedure() at the
	 * beginning of EACH and EVERY entry procedure of your monitor.
	 * You MUST NOT use Declare_Monitor_Entry_Procedure() anywhere
	 * else.  This call acquires the mutual exclusion of the monitor
	 * and arranges for the mutual exclusion to be automatically
	 * released when this entry procedure returns.
	 */
	Declare_Monitor_Entry_Procedure();

	state[i] = HUNGRY;
	test_forks(i);
	while (state[i] != EATING)
		CondWait(philcond[i]);
}

/*
 * Put down both of the forks for philosopher i.  If this allows either
 * the philosopher to our left or to our right to begin eating, let them
 * eat.
 *
 * As with pickup_forks, this is also an entry procedure of the monitor.
 */
extern void
putdown_forks(int i)
{
	/*
	 * You MUST use Declare_Monitor_Entry_Procedure() at the
	 * beginning of EACH and EVERY entry procedure of your monitor.
	 * You MUST NOT use Declare_Monitor_Entry_Procedure() anywhere
	 * else.  This call acquires the mutual exclusion of the monitor
	 * and arranges for the mutual exclusion to be automatically
	 * released when this entry procedure returns.
	 */
	Declare_Monitor_Entry_Procedure();

	state[i] = THINKING;
	test_forks(LEFTPHIL);
	test_forks(RIGHTPHIL);
}

/*
 * Test whether philosopher i can begin eating.  If so, move him
 * to EATING state and signal him (in case he is waiting).
 *
 * This is an *internal* (non-entry) procedure of the monitor.  Thus,
 * it is a 'static' function, making this function name not known
 * outside this .c file, so it can't be called from outside the
 * monitor.  An internal procedure should be called only from a
 * monitor entry procedure (or from another internal procedure of
 * the monitor).
 */
static void
test_forks(int i)
{
	if (state[LEFTPHIL] != EATING &&
	    state[i] == HUNGRY &&
	    state[RIGHTPHIL] != EATING) {
		state[i] = EATING;
		CondSignal(philcond[i]);
	}
}

/*
 * Initialize the Dining Philosophers monitor.
 * 
 * This procedure should be called *once* when the whole program starts
 * running.  It creates the condition variables and initializes the
 * shared variables used inside the monitor.
 */
void
init_philosophers()
{
	int i;

	for (i = 0; i < 5; i++) {
		state[i] = THINKING;
		philcond[i] = CondCreate();
	}
}
