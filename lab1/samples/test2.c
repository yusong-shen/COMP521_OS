#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>

void writer(void *);

char string[] = "abcdefghijklmnopqrstuvwxyz";
int length = sizeof(string) - 1;

int main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);

    //   if (argc > 1) HardwareOutputSpeed(1, atoi(argv[1]));
    //  if (argc > 2) HardwareInputSpeed(1, atoi(argv[2]));
    // HardwareOutputSpeed(1, 100);
    HardwareInputSpeed(1, 2000);

    ThreadCreate(writer, NULL);

    ThreadWaitAll();

    exit(0);
}

void
writer(void *arg)
{
    int status;

    printf("Doing WriteTerminal... '");
    fflush(stdout);
    status = WriteTerminal(1, string, length);
    printf("'. Done: status = %d.\n", length);
    fflush(stdout);
}
