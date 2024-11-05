#include "minitalk.h"
#include <stdio.h>

int     main(void)
{
    pid_t   pid;

    pid = getpid();
    printf("Server PID: [%d]", pid);
    return (0);
}