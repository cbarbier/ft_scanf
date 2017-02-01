/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:32:24 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		pf_helper2_p(t_arg *arg, int dw, int dp)
{
	char		*tmp;

	arg->buf = ft_strnew(arg->len);
	if (arg->precision == -1 && arg->zero)
	{
		dp = dw;
		dw = 0;
	}
	if (!arg->uval && !arg->precision)
		tmp = ft_strnew(0);
	else
		tmp = ft_imtoa_base(arg->uval, 16);
	while (!arg->minus && dw--)
		ft_strcat(arg->buf, " ");
	ft_strcat(arg->buf, "0x");
	while (dp-- > 0)
		ft_strcat(arg->buf, "0");
	ft_strcat(arg->buf, tmp);
	while (arg->minus && dw--)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static void		pf_helper_p(t_arg *arg)
{
	int		dwidth;
	int		dprec;

	dwidth = 0;
	dprec = 0;
	if (!arg->uval && !arg->precision)
		arg->len = 0;
	else
		arg->len = ft_nblenbase(arg->uval, 16);
	if (arg->precision > arg->len)
	{
		dprec = arg->precision - arg->len;
		arg->len = arg->precision;
	}
	arg->len += 2;
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_p(arg, dwidth, dprec);
}

char			*pf_handler_p(t_arg *arg)
{
	arg->uval = (unsigned long int)va_arg(*(arg->ap), void *);
	pf_helper_p(arg);
	return (arg->buf);
}
