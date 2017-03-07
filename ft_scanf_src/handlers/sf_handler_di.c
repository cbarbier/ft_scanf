/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_handler_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 17:44:59 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				sf_handler_di(t_sf *sf)
{
	unsigned int	val;
	int				*p;
	char			c;
	int				sign;
	int				len;

	sign = -1;
	if (read_buff_at_index(sf) == '-')
		sf->index++;
	else
		sign = 1;
	len = sign == -1 ? 1 : 0;
	val = 0;
	ft_printf("di handleer\n");
	while ((c = read_buff_at_index(sf)) && ft_isdigit(c))
	{
		ft_printf("%c\n", c);
		val = 10 * val + (c - '0');
		sf->index++;
		len++;
	}
	if (!(p = va_arg(*(sf->ap), int*)))
		return (-1);
	*p = (int)(sign * val);
	return (len);
}
