#include <stdio.h>
#include <stdlib.h>

#include <threads.h>	/* COMP 421 threads package definitions */

void pickup_forks(int);
void putdown_forks(int);
void init_philosophers(void);

void
do_phil(void *arg)
{
	int i = (int)(long)arg;

	printf("do_phil %d\n", i);

	while (1) {
		pickup_forks(i);
		printf("eating %d\n", i);
		putdown_forks(i);
		printf("thinking %d\n", i);
	}
}

int
main(int argc, char **argv)
{
	int i;

	init_philosophers();

	for (i = 0; i < 5; i++) {
		ThreadCreate(do_phil, (void *)(long)i);
	}

	ThreadWaitAll();

    exit(0);
}
