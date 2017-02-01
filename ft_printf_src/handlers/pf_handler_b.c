/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:29:23 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		pf_helper2_b(t_arg *arg, int dw, int dp)
{
	char		*tmp;
	char		*up;

	arg->buf = ft_strnew(arg->len);
	if (!arg->uval && !arg->precision && !arg->prefix)
		tmp = ft_strdup("");
	else
		tmp = ft_uimtoa_base(arg->uval, 2);
	while (!arg->minus && !(arg->precision == -1 && arg->zero) && dw-- > 0)
		ft_strcat(arg->buf, " ");
	if (arg->prefix && arg->uval)
		ft_strcat(arg->buf, "0b");
	while (dp-- > 0 || (arg->zero && arg->precision == -1 && dw-- > 0))
		ft_strcat(arg->buf, "0");
	ft_strcat(arg->buf, tmp);
	up = arg->buf;
	if (arg->conversion == 'B')
		while (*up && (*up = ft_toupper(*up)))
			up++;
	while (arg->minus && dw-- > 0)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static void		pf_helper_b(t_arg *arg)
{
	int		dwidth;
	int		dprec;

	dwidth = 0;
	dprec = 0;
	arg->len = ft_nblenbase(arg->uval, 2);
	if (!arg->uval && !arg->precision && !arg->prefix)
		arg->len--;
	arg->len += (arg->prefix && arg->uval ? 2 : 0);
	if (arg->precision > arg->len)
	{
		dprec = arg->precision - arg->len;
		arg->len = arg->precision;
	}
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_b(arg, dwidth, dprec);
}

char			*pf_handler_b(t_arg *arg)
{
	t_length_modifier		lm;

	lm = arg->length;
	if (lm == hh)
		arg->uval = (unsigned char)va_arg(*(arg->ap), unsigned int);
	else if (lm == h)
		arg->uval = (unsigned short int)va_arg(*(arg->ap), unsigned int);
	else if (lm == ll)
		arg->uval = va_arg(*(arg->ap), unsigned long long int);
	else if (lm == l)
		arg->uval = va_arg(*(arg->ap), unsigned long int);
	else if (lm == j)
		arg->uval = va_arg(*(arg->ap), uintmax_t);
	else if (lm == z)
		arg->uval = va_arg(*(arg->ap), size_t);
	else
		arg->uval = va_arg(*(arg->ap), unsigned int);
	pf_helper_b(arg);
	return (arg->buf);
}
