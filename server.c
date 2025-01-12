/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filip <filip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:59 by fkarika           #+#    #+#             */
/*   Updated: 2025/01/12 17:46:51 by filip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	send_ack(signum, info);
}

int	main(void)
{
	init_signal(SIGUSR1, &handle_signal);
	init_signal(SIGUSR2, &handle_signal);
	ft_printf("Server PID: [%d]\n\n", (int)getpid());
	while (usleep(600))
		;
	return (EXIT_SUCCESS);
}
