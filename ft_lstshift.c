/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:04:13 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/23 19:04:26 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstshift(t_list **alst, void (*del)(void **))
{
	t_list *lst;

	if (!alst || !del || !*alst)
		return ;
	lst = (*alst)->next;
	del(&((*alst)->content));
	del((void **)alst);
	*alst = lst;
}
