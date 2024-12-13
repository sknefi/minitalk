#include "minitalk.h"

void	confirm_message(int signum)
{
	if (signum == SIGUSR1)
		// ft_printf("");
		ft_printf("1");
	else if (signum == SIGUSR2)
		// ft_printf("");
		ft_printf("0");
	else
		// ft_printf("");
		ft_printf("ERROR: someother signal was sent");
}

void	send_bit(char c, pid_t server_pid)
{
	int		bit;
	char	curr_char;

	bit = 0;
	curr_char = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
		{
			kill(server_pid, SIGUSR1);
			curr_char |= (1 << bit);
		}
		else
			kill(server_pid, SIGUSR2);
		bit++;
		usleep(800);
	}
	ft_printf("\nSent: %c\n", curr_char);
}

void	send_str(char *str, pid_t server_pid)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		send_bit(str[i], server_pid);
		i++;
		usleep(800);
	}
	send_bit('\0', server_pid);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		return (ft_printf("valid format> ./minitalk <server_pid> <message>\n"),
			EXIT_SUCCESS);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > MAX_PID)
		ft_printf("Invalid PID\n", EXIT_SUCCESS);
	signal(SIGUSR1, confirm_message);
	signal(SIGUSR2, confirm_message);
	send_str(argv[2], server_pid);
	return (EXIT_SUCCESS);
}
