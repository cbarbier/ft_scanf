/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/13 17:12:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
	{
		if (s1)
			ft_strdel((char **)&s1);
		if (s2)
			ft_strdel((char **)&s2);
		return (NULL);
	}
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	ft_strdel((char **)&s1);
	ft_strdel((char **)&s2);
	return (res);
}
