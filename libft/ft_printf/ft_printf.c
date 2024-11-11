/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:19 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 19:50:51 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/ft_printf.h"

void	ftp_handle_format(char c, va_list args, int *count)
{
	if (c == 's')
		(*count) += ftp_print_string(va_arg(args, char *));
	else if (c == 'c')
		(*count) += ftp_print_char((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		(*count) += ftp_print_number(va_arg(args, int), 10, DEC);
	else if (c == 'u')
		(*count) += ftp_print_number(
				(unsigned long)va_arg(args, unsigned int), 10, DEC);
	else if (c == 'x')
		(*count) += ftp_print_number(
				va_arg(args, unsigned int), 16, HEX);
	else if (c == 'X')
		(*count) += ftp_print_number(
				va_arg(args, unsigned int), 16, UP_HEX);
	else if (c == 'p')
		(*count) += ftp_print_pointer(
				(unsigned long long)va_arg(args, void *), 16, HEX);
	else
		(*count) += write(1, &c, 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i])
				ftp_handle_format(str[i], args, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
