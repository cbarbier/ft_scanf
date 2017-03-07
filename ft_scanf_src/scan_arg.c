/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:47:52 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 16:23:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	call_handler(t_sf *sf, char conversion)
{
	int		index;

	index = 0;
	while (index < NB_SF_SPEC && sf->handlers[index].c != conversion)
		index++;
	if (index < NB_SF_SPEC)
		return (sf->handlers[index].f(sf));
	return (-1);
}

int			scan_arg(t_sf *sf)
{
	int		tmp;

	if ((tmp = call_handler(sf, sf->conv)) < 0)
		return (-1);
	sf->ret += tmp;
	return (1);
}
