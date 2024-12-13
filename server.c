#include "minitalk.h"

// volatile sig_atomic_t server_running = 1;

// void handle_exit_signal(int signum)
// {
//     (void)signum;
//     server_running = 0;
// }

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit;
	static char		curr_char;
	static char		*curr_str;

	(void)context;
	if (signum == SIGUSR1)
		curr_char |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		curr_str = add_byte_to_string(curr_str, curr_char);
		if (!curr_str)
			ft_error("Memory allocation failed\n");
		if (curr_char == '\0')
		{
			ft_printf("RECIEVED MESSAGE: %s\n", curr_str);
			free(curr_str);
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
    // signal(SIGHUP, handle_exit_signal);
	ft_printf("Server PID: [%d]\n\n", (int)getpid());
	// while (server_running)
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
