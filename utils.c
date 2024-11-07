#include "minitalk.h"

static void		handle_error(char *str)
{
	printf("Error type: %s\n", str);
	exit(1);
}

void	init_signal(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = handler;
	sigemptyset(&s_sigaction.sa_mask);
	if (sig == SIGUSR1)
	{
		if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
			handle_error("Signal (SIGUSR1)");
	}
	if (sig == SIGUSR2)
	{
		if (sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
			handle_error("Signal (SIGUSR2)");
	}
}
