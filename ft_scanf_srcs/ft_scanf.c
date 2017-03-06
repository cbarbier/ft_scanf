/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:38:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 18:21:40 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_scanf(int fd, const char *format, ...)
{
	int			ret;
	t_sf		sf;
	va_list		ap;

	init_pf(&sf);
	init_buff(&sf);
	sf.ap = &ap;
	va_start(*(sf.ap), format);
	split_args(&sf, format);
	va_end(*(pf.ap));
	free(sf->buff);
	ret = sf.ret;
	return (ret);
}
