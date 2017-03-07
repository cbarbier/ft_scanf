/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 17:38:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			sf_handler_s(t_sf *sf)
{
	char		*p;
	int			len;
	char		c;

	if (!(p = va_arg(*(sf->ap), char *)))
		return (-1);
	len = 0;
	while ((c = read_buff_at_index(sf)) && !ft_strchr(SPACES, c))
	{
		p[len] = c;
		sf->index++;
		len++;
	}
	return (len);
}
