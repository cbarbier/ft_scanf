/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:34:24 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	char	*set_sign(t_arg *arg)
{
	if (arg->sign)
		return ("-");
	else if (arg->plus)
		return ("+");
	else if (arg->space)
		return (" ");
	else
		return ("");
}

static void		pf_helper2_di(t_arg *arg, int dw, int dp)
{
	char		*tmp;

	arg->buf = ft_strnew(arg->len);
	if (!arg->uval && !arg->precision)
		tmp = ft_strnew(0);
	else
		tmp = ft_uimtoa_base(arg->uval, 10);
	while (!arg->minus && !(arg->zero && arg->precision < 0) && dw-- > 0)
		ft_strcat(arg->buf, " ");
	ft_strcat(arg->buf, set_sign(arg));
	while (dp-- > 0 || (arg->zero && dw-- > 0))
		ft_strcat(arg->buf, "0");
	ft_strcat(arg->buf, tmp);
	while (arg->minus && dw-- > 0)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static void		pf_helper_di(t_arg *arg)
{
	int		dwidth;
	int		dprec;

	dwidth = 0;
	dprec = 0;
	if (!arg->uval && !arg->precision)
		arg->len = 0;
	else
		arg->len = ft_nblenbase(arg->uval, 10);
	if (arg->precision > arg->len)
	{
		dprec = arg->precision - arg->len;
		arg->len = arg->precision;
	}
	if (arg->sign || arg->space || arg->plus)
		arg->len++;
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_di(arg, dwidth, dprec);
}

char			*pf_handler_di(t_arg *arg)
{
	t_length_modifier		lm;

	if (arg->conversion == 'D')
		arg->length = l;
	lm = arg->length;
	if (lm == hh)
		arg->val = (char)va_arg(*(arg->ap), int);
	else if (lm == h)
		arg->val = (short int)va_arg(*(arg->ap), int);
	else if (lm == ll)
		arg->val = va_arg(*(arg->ap), long long int);
	else if (lm == l)
		arg->val = va_arg(*(arg->ap), long int);
	else if (lm == j)
		arg->val = va_arg(*(arg->ap), intmax_t);
	else if (lm == z)
		arg->val = va_arg(*(arg->ap), ssize_t);
	else
		arg->val = va_arg(*(arg->ap), int);
	arg->sign = (arg->val < 0 ? 1 : 0);
	arg->uval = (arg->val < 0 ? -arg->val : arg->val);
	pf_helper_di(arg);
	return (arg->buf);
}
