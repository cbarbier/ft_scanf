/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/07 10:55:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	ft_memset(content, 0, content_size);
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *new;
	t_list *temp;

	if (!lst || !f || !(temp = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	temp = f(temp);
	begin = temp;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (!new)
		{
			ft_lstdel(&begin, del);
			return (NULL);
		}
		new = f(new);
		temp->next = new;
		temp = temp->next;
		lst = lst->next;
	}
	return (begin);
}
