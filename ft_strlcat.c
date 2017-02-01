/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/12 10:59:54 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	id;
	unsigned int	is;

	id = 0;
	while (dst[id] && id < size)
		id++;
	if (id == size)
		return (size + ft_strlen(src));
	is = 0;
	while ((id + is) < size - 1 && src[is])
	{
		dst[id + is] = src[is];
		is++;
	}
	dst[id + is] = '\0';
	return (id + ft_strlen(src));
}
