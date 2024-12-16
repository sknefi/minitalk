/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <fkarika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:52 by fkarika           #+#    #+#             */
/*   Updated: 2024/12/16 16:59:42 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <aio.h>

# ifndef MAX_PID
#  define MAX_PID 4194304
# endif

void	init_signal(int sig, void (*handler)(int, siginfo_t *, void *));
char	*add_byte_to_string(char *curr_str, char c);
void	send_ack(int signum, siginfo_t *info);

#endif