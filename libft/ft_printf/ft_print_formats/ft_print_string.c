/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:24 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 20:22:04 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/ft_printf.h"

int	ftp_print_string(char *str)
{
	int	count;

	if (str == NULL)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
		count += write(1, str++, 1);
	return (count);
}
