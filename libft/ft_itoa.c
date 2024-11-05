/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:59:25 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/02 16:43:20 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	int_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_abs(int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len_n;
	unsigned int	num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = int_len(n);
	str = malloc((len_n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len_n] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	num = ft_abs(n);
	while (num)
	{
		str[--len_n] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}
