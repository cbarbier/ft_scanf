/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:59:18 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 18:38:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_scanf.h"

static int		fill_buff(t_sf *sf)
{
	int	ret;

	if ((ret = read(sf->fd, sf->buff, sf->size) < 0)
		return (-1);
	buff[ret] = 0;
	return (ret);
}

int				init_buff(t_sf *sf)
{
	if (!(sf->buff = (char *)ft_memalloc((sf->buffsize + 1) * sizeof(char))))
		return (0);
	fill_buff(sf->buff, sf->buffsize, sf->fd);
	return (1);
}

char		read_at_index(t_sf *sf, int index)
{
	if (!sf->buff[index])
		if (!fill_buff(sf->buff, sf->size, sf->fd))
			return (0);
	return (sf->buff[index]);
}
