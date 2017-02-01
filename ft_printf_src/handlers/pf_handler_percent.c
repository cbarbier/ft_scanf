/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:42:33 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		pf_helper2_percent(t_arg *arg, int dw)
{
	arg->buf = ft_strnew(arg->len);
	while (!arg->minus && dw--)
		ft_strcat(arg->buf, " ");
	ft_strcat(arg->buf, "%");
	while (arg->minus && dw--)
		ft_strcat(arg->buf, " ");
}

static void		pf_helper_percent(t_arg *arg)
{
	int		dwidth;

	dwidth = 0;
	arg->len = 1;
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_percent(arg, dwidth);
}

char			*pf_handler_percent(t_arg *arg)
{
	arg->val = '%';
	if (!arg->conversion)
		pf_helper_percent(arg);
	return (pf_handler_c(arg));
}
