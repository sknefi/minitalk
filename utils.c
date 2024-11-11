#include "minitalk.h"

void	init_signal(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sig == SIGUSR1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_error("Signal (SIGUSR1)");
	}
	if (sig == SIGUSR2)
	{
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_error("Signal (SIGUSR2)");
	}
}

// same function as used in gnl project
// s1 is current string
// s2 will always be only 1 character (8bits from signals)
char	*mt_ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (!s1)
			ft_error("Malloc failed - ft_strjoin[1]\n");
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)ft_calloc(
			(ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
	{
		free(s1);
		ft_error("Malloc failed - ft_strjoin[2]\n");
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}
