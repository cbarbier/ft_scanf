/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:47:52 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 15:58:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	call_handler(t_sf *sf, char conversion)
{
	int		index;

	index = 0;
	while (index < NB_SPEC && sf->handlers[index].c != conversion)
		index++;
	if (index < NB_SPEC)
		return (sf->handlers[index].f(sf));
	return (0);
}

int			scan_arg(t_sf *sf)
{
	t_arg	*arg;
	int		tmp;

	arg = (t_arg *)(sf->arg);
	check_arg(arg);
	if ((tmp = call_handler(pf, arg->conversion)) < 0)
		return (-1);
	sf->ret += tmp;
	return (sf->ret);
}
