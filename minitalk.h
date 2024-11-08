#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

# ifndef MAX_PID
#  define MAX_PID 4194304
# endif

void	init_signal(int sig, void (*handler)(int, siginfo_t *, void *));

#endif