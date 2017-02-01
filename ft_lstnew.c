/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/04 20:24:03 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list *elem;

	elem = (t_list*)ft_memalloc(sizeof(t_list));
	if (!elem || !content)
		return (elem);
	elem->content = ft_memalloc(content_size);
	if (!elem->content)
		return (elem);
	elem->content = ft_memcpy(elem->content, content, content_size);
	elem->content_size = content_size;
	return (elem);
}
