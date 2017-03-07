/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_handler_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 18:56:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*sf_handler_di(sf *sf)
{
	unsigned int	val;
	int			*p;
	char		c;
	int		sign;
	int		len;

	sign = read_buff_at_index(sf) == '-' ? -1 : 1;
	len = sign == -1 ? 1 : 0;
	val = 0;
	while ((c = read_buff_at_index(sf)) && ft_isdigit(c))
	{
		val *= 10 + (c - '0');
		sf->index++;
		len++;
	}
	if (!(p = va_arg(*(sf->ap), int*)))
		return (-1);
	*p = (int)(sign * val);
	return (len);
}
