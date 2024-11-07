#include "minitalk.h"

void	confirm_message(int signum)
{
	if (signum == SIGUSR1)
		printf("SUCCESS: sent 1 to server\n");
	else if (signum == SIGUSR2)
		printf("SUCCESS: sent 0 to server\n");
	else 
		printf("ERROR: wierd");
}

void	send_bits(char c, pid_t server_pid)
{
	unsigned int	bit;

	bit = 0;
	while (bit < 8)
	{
		// printf("%c", (c << bit));
		if (c & (0x01 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit++;
		usleep(400);
	}
}

void	send_str(char *str, pid_t server_pid)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		send_bits(str[i], server_pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		return (printf("error, invalid arguments\n"),
			printf("valid format> ./minitalk <server_pid> <message>"),
			EXIT_SUCCESS);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > MAX_PID)
		printf("Invalid PID\n", EXIT_SUCCESS);
	signal(SIGUSR1, confirm_message);
	signal(SIGUSR2, confirm_message);
	send_str(argv[2], server_pid);
	return (EXIT_SUCCESS);
}