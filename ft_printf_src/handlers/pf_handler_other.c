/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 22:12:49 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 21:02:57 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	set_color(char *txt)
{
	if (!ft_strncmp(txt, "{red}", 5))
		ft_memcpy(txt, RED, 5);
	else if (!ft_strncmp(txt, "{grn}", 5))
		ft_memcpy(txt, GRN, 5);
	else if (!ft_strncmp(txt, "{yel}", 5))
		ft_memcpy(txt, YEL, 5);
	else if (!ft_strncmp(txt, "{blu}", 5))
		ft_memcpy(txt, BLU, 5);
	else if (!ft_strncmp(txt, "{no}", 4))
		ft_memcpy(txt, EOC, 4);
}

static void	pf_apply_color(char *txt, int ln)
{
	while (ln--)
	{
		if (*txt == '{')
			set_color(txt);
		txt++;
	}
}

char		*pf_handler_other(t_arg *arg)
{
	if (!ft_strcmp(arg->text, "%"))
		return (arg->buf = ft_strdup(""));
	else if (*(arg->text) != '%')
	{
		arg->len = ft_strlen(arg->text);
		arg->buf = ft_strdup(arg->text);
		pf_apply_color(arg->buf, arg->len);
		return (arg->buf);
	}
	arg->val = arg->conversion;
	return (pf_handler_c(arg));
}
