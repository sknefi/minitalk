#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	// Simple signal handler for demonstration
	(void)context;  // Avoid unused parameter warning
	printf("Received signal %d from PID: %d\n", signum, info->si_pid);
}

int		main(void)
{
	init_signal(SIGUSR1, &handle_signal);
	init_signal(SIGUSR2, &handle_signal);
	printf("Server PID: [%d]\n", (int)getpid());
	return (0);
}