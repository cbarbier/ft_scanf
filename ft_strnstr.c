/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/12 10:52:26 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big);
	while ((i + j) < len && big[i])
	{
		while ((i + j) < len && big[i + j] == little[j])
		{
			j++;
			if (!little[j])
				return ((char *)(big + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
