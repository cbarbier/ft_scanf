/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:38:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 18:42:16 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_scanf(int fd, const char *format, ...)
{
	int			ret;
	t_sf		sf;
	va_list		ap;

	init_sf(&sf, fd);
	sf.ap = &ap;
	va_start(*(sf.ap), format);
	sf_core(&sf, format);
	va_end(*(sf.ap));
	ret = sf.ret;
	return (ret);
}
