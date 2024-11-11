/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:55 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 16:30:22 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdio.h"
# include <unistd.h>

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"

int		ft_printf(const char *str, ...);

int		ftp_print_char(char c);
int		ftp_print_string(char *str);
int		ftp_print_number(long n, int base, char *symbols);
int		ftp_print_pointer(
			unsigned long long ptr, unsigned long long base, char *symbols);

#endif
