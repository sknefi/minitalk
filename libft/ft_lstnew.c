/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:25:46 by fkarika           #+#    #+#             */
/*   Updated: 2024/09/24 19:16:36 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_linked_list;

	new_linked_list = (t_list *)malloc(sizeof(t_list));
	if (!new_linked_list)
		return (NULL);
	new_linked_list->content = content;
	new_linked_list->next = NULL;
	return (new_linked_list);
}
