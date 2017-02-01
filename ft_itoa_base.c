/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:10:01 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int n, unsigned int base)
{
	char			*res;
	unsigned int	nb;
	int				index;
	int				size;
	const char		vals[] = "0123456789abcdef";

	nb = (n < 0 && base == 10 ? -n : n);
	size = ft_nblenbase(nb, base) + (n < 0 && base == 10 ? 1 : 0);
	if (!(res = ft_strnew(size)))
		return (NULL);
	index = 0;
	if (n < 0 && base == 10)
		res[index++] = '-';
	while (index < size)
	{
		res[--size] = vals[nb % base];
		nb /= base;
	}
	return (res);
}
