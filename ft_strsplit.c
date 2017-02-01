/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/07 10:49:03 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				nb_words(char **aptr, char c)
{
	unsigned int	nbwords;
	char			*ptr;

	ptr = *aptr;
	nbwords = 0;
	while (*ptr)
	{
		if (*ptr != c)
		{
			if (!nbwords)
				*aptr = ptr;
			while (*ptr && *ptr != c)
				ptr++;
			nbwords++;
		}
		else
			ptr++;
	}
	return (nbwords);
}

static	unsigned int	add_word(char *ptr, char **res, char c)
{
	unsigned int	index;

	index = 0;
	while (ptr[index] != c && ptr[index])
		index++;
	*res = ft_strsub(ptr, 0, index);
	while (ptr[index] && ptr[index] == c)
		index++;
	return (index);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**res;
	char			*ptr;
	unsigned int	i_res;
	unsigned int	nb;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	nb = nb_words(&ptr, c);
	res = (char **)malloc((nb + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i_res = 0;
	while (i_res < nb)
	{
		ptr += add_word(ptr, &res[i_res], c);
		i_res++;
	}
	res[nb] = 0;
	return (res);
}
