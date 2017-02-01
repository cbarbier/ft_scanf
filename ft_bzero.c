/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:58:04 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/07 08:58:42 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		indice;
	char		*str;

	indice = 0;
	str = (char*)s;
	while (indice < n)
	{
		str[indice] = 0;
		indice++;
	}
}
