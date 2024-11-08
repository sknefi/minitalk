#include "minitalk.h"

void print_binary(int n)
{
    for (int i = 7; i >= 0; i--)
    {
        if (n & (1 << i))
            printf("1");
        else
            printf("0");
    }
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit;
	static int		curr_char;

	(void)context;
	if (signum == SIGUSR1)
		curr_char |= (0x01 << bit);
    // printf("----------\n");
	// print_binary(curr_char);
    // printf("\n");
	bit++;
	if (bit == 8)
	{
    	// printf("Received signal: %d, bit: %d, num %d\n", signum, bit, curr_char);
		ft_printf("%c\n", curr_char);
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
	printf("Server PID: [%d]\n\n", (int)getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}