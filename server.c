#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit;
	static int		curr_char;

	(void)context;
	if (signum == SIGUSR1)
		curr_char |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (curr_char == 0)
			printf("\n");
		printf("%c", curr_char);
		bit = 0;
		curr_char = 0;
	}
	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int		main(void)
{
	init_signal(SIGUSR1, &handle_signal);
	init_signal(SIGUSR2, &handle_signal);
	printf("Server PID: [%d]\n", (int)getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}