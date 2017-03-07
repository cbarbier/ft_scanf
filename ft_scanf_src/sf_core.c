/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:48:16 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 18:42:27 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_arg(t_sf *sf, const char *format)
{
	int		len;

	if (*format == '%' && format[1])
	{
		sf->conv = format[1];
		return (2);
	}
	len = 0;
	while (format[len] && format[len] != '%')
	{
		if (read_buff_at_index(sf) != format[len++])
			return (-1);
		sf->index++;
	}
	return (len);
}

int			sf_core(t_sf *sf, const char *format)
{
	int		tmp;

	while (*format)
	{
		sf->conv = 0;
		if ((tmp = find_arg(sf, format)) < 0)
			return (0);
		if (sf->conv && scan_arg(sf) < 0)
			return (0);
		format += tmp;
	}
	return (1);
}
