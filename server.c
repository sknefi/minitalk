#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit;
	static char		curr_char;
	static char		*curr_str;

	(void)context;
	if (signum == SIGUSR1)
		curr_char |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		curr_str = mt_ft_strjoin(curr_str, &curr_char);
		if (curr_char == '\0')
		{
			ft_printf("%s", curr_str);
			curr_str = NULL;
		}
		bit = 0;
		curr_char = 0;
	}
	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	init_signal(SIGUSR1, &handle_signal);
	init_signal(SIGUSR2, &handle_signal);
	ft_printf("Server PID: [%d]\n\n", (int)getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
