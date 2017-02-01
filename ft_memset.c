/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:54:22 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/07 08:55:28 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			indice;
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	indice = 0;
	while (indice < len)
	{
		ptr[indice] = (unsigned char)c;
		indice++;
	}
	return (b);
}
