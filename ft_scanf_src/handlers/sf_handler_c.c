/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_handler_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 16:03:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		sf_handler_c(t_sf *sf)
{
	char	*p;

	if (!(p = va_arg(*(sf->ap), char *)))
		return (-1);
	*p = read_buff_at_index(sf);
	sf->index++;
	return (1);
}
