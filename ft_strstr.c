/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/07 09:45:10 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char			*ptrb;
	unsigned int	il;

	ptrb = (char *)big;
	il = 0;
	if (!*little)
		return (ptrb);
	while (*ptrb)
	{
		if (!little[il])
			return (ptrb);
		else if (little[il] == *(ptrb + il))
			il++;
		else if (little[il] != *(ptrb + il))
		{
			il = 0;
			ptrb++;
		}
	}
	return (NULL);
}
