/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/31 09:19:33 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ftoa(double f, unsigned int prec)
{
	char			*res;
	char			*tmp;
	long double		nb;
	long double		dec;
	unsigned int	size;

	nb = (f < 0 ? -f : f);
	if (!(tmp = ft_imtoa_base((uintmax_t)f, 10)))
		return (NULL);
	size = ft_strlen(tmp) + prec + (prec ? 1 : 0);
	if (!(res = ft_strcat(ft_strnew(size), tmp)))
		return (NULL);
	free(tmp);
	if (prec)
	{
		ft_strcat(res, ".");
		dec = ft_pow(10, prec) * (nb - (uintmax_t)nb) + 0.5;
		tmp = ft_uimtoa_base((uintmax_t)dec, 10);
		ft_strcat(res, tmp);
		free(tmp);
	}
	return (res);
}
