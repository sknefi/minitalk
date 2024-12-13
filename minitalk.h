#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>

# ifndef MAX_PID
#  define MAX_PID 4194304
# endif

void	init_signal(int sig, void (*handler)(int, siginfo_t *, void *));
char	*add_byte_to_string(char *curr_str, char c);

#endif