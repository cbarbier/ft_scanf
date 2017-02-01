/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:57:31 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/21 15:17:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **alst, t_list *elem)
{
	t_list *lst;

	if (!alst || !elem)
		return ;
	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	lst = *alst;
	while (lst->next)
		lst = lst->next;
	lst->next = elem;
}
