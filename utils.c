/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:54 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 17:00:09 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * @brief Concatenates two strings into a new string.
 * @param s1 The first string.
 * @param s2 I will pass only one character at a time
*/
char	*add_byte_to_string(char *curr_str, char c)
{
	char	*str;
	size_t	len_curr_str;

	if (!curr_str)
	{
		str = (char *)ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = (unsigned char) c;
		str[1] = '\0';
		return (str);
	}
	len_curr_str = ft_strlen(curr_str);
	str = (char *)ft_calloc(len_curr_str + 2, sizeof(char));
	if (!str)
	{
		free(curr_str);
		return (NULL);
	}
	ft_strlcpy(str, curr_str, len_curr_str + 2);
	str[len_curr_str] = c;
	str[len_curr_str + 1] = '\0';
	free(curr_str);
	return (str);
}

void	send_ack(int signum, siginfo_t *info)
{
	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}
