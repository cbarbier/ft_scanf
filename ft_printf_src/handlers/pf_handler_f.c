/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:29:59 by cbarbier         ###   ########.fr       */
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

static void		pf_helper2_f(t_arg *arg, char *tmp, int dw)
{
	arg->buf = ft_strnew(arg->len);
	if (arg->zero)
		ft_strcat(arg->buf, set_sign(arg));
	while (!arg->minus && dw-- > 0)
		ft_strcat(arg->buf, (arg->zero ? "0" : " "));
	if (!arg->zero)
		ft_strcat(arg->buf, set_sign(arg));
	ft_strcat(arg->buf, tmp);
	while (arg->minus && dw-- > 0)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static void		pf_helper_f(t_arg *arg)
{
	int		dwidth;
	char	*tmp;

	dwidth = 0;
	tmp = ft_ftoa(arg->d, arg->precision);
	arg->len = ft_strlen(tmp);
	if (arg->sign || arg->space || arg->plus)
		arg->len++;
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_f(arg, tmp, dwidth);
}

char			*pf_handler_f(t_arg *arg)
{
	arg->d = va_arg(*(arg->ap), double);
	arg->sign = (arg->d < 0 ? 1 : 0);
	arg->d = (arg->d < 0 ? -arg->d : arg->d);
	arg->precision = arg->precision == -1 ? 6 : arg->precision;
	pf_helper_f(arg);
	return (arg->buf);
}
