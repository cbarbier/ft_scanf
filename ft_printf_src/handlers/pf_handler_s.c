/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/02/01 19:25:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		pf_helper2_s(t_arg *arg, int dw, int dp)
{
	char		*tmp;

	arg->buf = ft_strnew(arg->len);
	while (!arg->minus && dw-- > 0)
		ft_strcat(arg->buf, (arg->zero ? "0" : " "));
	if (arg->precision == -1 || arg->precision > (int)ft_strlen(arg->s))
		tmp = ft_strdup(arg->s);
	else
		tmp = ft_strsub(arg->s, 0, dp);
	ft_strcat(arg->buf, tmp);
	while (arg->minus && dw-- > 0)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static void		pf_helper_s(t_arg *arg)
{
	int		dwidth;
	int		dprec;

	dwidth = 0;
	dprec = 0;
	arg->len = ft_strlen(arg->s);
	if (arg->precision != -1 && arg->precision <= arg->len)
	{
		dprec = arg->precision;
		arg->len = arg->precision;
	}
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_s(arg, dwidth, dprec);
}

char			*pf_handler_s(t_arg *arg)
{
	t_length_modifier		lm;

	lm = arg->length;
	if (lm == l)
		return (pf_handler_ls(arg));
	else
		arg->s = va_arg(*(arg->ap), char *);
	if (!arg->s && arg->precision)
	{
		arg->buf = ft_strdup("(null)");
		arg->len = 6;
		return (arg->buf);
	}
	else if (!arg->s)
		arg->s = ft_strnew(0);
	pf_helper_s(arg);
	return (arg->buf);
}
