/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:10:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uimtoa_base(uintmax_t nb, int base)
{
	char		*res;
	int			size;
	const char	vals[] = "0123456789abcdef";

	size = ft_nblenbase(nb, base);
	if (!(res = ft_strnew(size)))
		return (NULL);
	while (size)
	{
		res[--size] = vals[nb % base];
		nb /= base;
	}
	return (res);
}
