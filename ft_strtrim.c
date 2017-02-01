/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/04 11:06:57 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int st;
	int en;

	if (!s)
		return (NULL);
	st = 0;
	while (s[st] && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
		st++;
	en = ft_strlen(s) - 1;
	if (en < 0)
		en = 0;
	while (en > st && (s[en] == ' ' || s[en] == '\n' || s[en] == '\t'))
		en--;
	return (ft_strsub(s, st, en - st + 1));
}
