/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:33 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 15:28:34 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/ft_printf.h"

int	ftp_print_number(long n, int base, char *symbols)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ftp_print_number(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ftp_print_char(symbols[n]));
	else
	{
		count = ftp_print_number(n / base, base, symbols);
		return (count + ftp_print_number(n % base, base, symbols));
	}
}
