/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:59:18 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 18:39:26 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scanf.h"

char		read_buff_at_index(t_sf *sf)
{
	static int	index = 0;
	int			ret;

	if (sf->index < index)
		return (sf->buff);
	index++;
	if ((ret = read(sf->fd, &(sf->buff), 1) < 0))
		return (-1);
	return (sf->buff);
}
