/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:25:26 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 17:09:47 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	new_lst = NULL;
	while (curr)
	{
		new_content = f(curr->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		curr = curr->next;
	}
	return (new_lst);
}
