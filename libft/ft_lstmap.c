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
	void	*content_new;
	t_list	*new;
	t_list	*new_head;

	if (!f || !del || !lst)
		return (NULL);
	content_new = f(lst->content);
	if (content_new == NULL)
		return (NULL);
	new = ft_lstnew(content_new);
	if (!new)
	{
		del(content_new);
		return (NULL);
	}
	new_head = new;
	lst = lst->next;
	while (lst)
	{
		content_new = f(lst->content);
		if (content_new == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		new->next = ft_lstnew(content_new);
		if (!new->next)
		{
			del(content_new);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (new_head);
}
