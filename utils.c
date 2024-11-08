#include "minitalk.h"

static void		handle_error(char *str)
{
	ft_printf("Error type: %s\n", str);
	exit(EXIT_FAILURE);
}

void	init_signal(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sig == SIGUSR1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			handle_error("Signal (SIGUSR1)");
	}
	if (sig == SIGUSR2)
	{
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			handle_error("Signal (SIGUSR2)");
	}
}
