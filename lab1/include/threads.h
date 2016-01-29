/*
 * threads.h
 *
 * Defines the interface to the COMP 421 threads package.
 */

#ifndef _threads_h
#define _threads_h

/*
 * Define the types used for thread identifiers and condition variable
 * identifiers.
 */
typedef int thread_id_t;
typedef int cond_id_t;

/*
 * Declares the calling procedure to be an entry procedure of the
 * monitor.  Must be called only at the *beginning* of each C/C++
 * procedure that implements an entry procedure of the monitor.
 * Acquires the mutual exclusion of the monitor, and when this entry
 * procedure returns, the mutual exclusion for the monitor is then
 * autmatically released.
 */
void Declare_Monitor_Entry_Procedure(void);

/*
 * Create a new thread, beginning execution at function func, passing
 * it the single argument arg.  The thread id of the new thread is
 * returned.
 */
thread_id_t ThreadCreate(void (*func)(void *), void *arg);

/*
 * Wait for the specified thread th to have completed.  The thread
 * must have been created by ThreadCreate().
 */
void ThreadWait(thread_id_t th);

/*
 * Wait for all threads created by ThreadCreate() to have completed.
 */
void ThreadWaitAll(void);

/*
 * Create a new condition variable for the monitor.  The condition
 * variable of the new condition variable is returned.
 */
cond_id_t CondCreate(void);

/*
 * Destroy the existing condition variable cv that was previously
 * created by CondCreate().
 */
void CondDestroy(cond_id_t cv);

/*
 * Do a signal operation on condition variable cv belonging to the
 * monitor.  Must be called only from within the monitor.
 */
void CondSignal(cond_id_t cv);

/*
 * Do a wait operation on condition variable cv belonging to the
 * monitor.  Must be called only from within the monitor.
 */
void CondWait(cond_id_t cv);

#endif /* _threads_h */
