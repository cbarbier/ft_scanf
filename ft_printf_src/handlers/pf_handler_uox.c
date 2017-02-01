/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_uox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 13:18:26 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		set_base(char c)
{
	if (c == 'o')
		return (8);
	else if (c == 'x')
		return (16);
	else
		return (10);
}

static void		pf_helper2_uox(t_arg *arg, int base, int dw, int dp)
{
	char		*tmp;
	char		*up;

	arg->buf = ft_strnew(arg->len);
	if (!arg->uval && !arg->precision && (!arg->prefix
		|| (arg->prefix && base == 16)))
		tmp = ft_strdup("");
	else
		tmp = ft_uimtoa_base(arg->uval, base);
	while (!arg->minus && !(arg->precision == -1 && arg->zero) && dw-- > 0)
		ft_strcat(arg->buf, " ");
	if (base != 10 && arg->prefix && arg->uval)
		ft_strcat(arg->buf, (base == 8 ? "0" : "0x"));
	while (dp-- > 0 || (arg->zero && arg->precision == -1 && dw-- > 0))
		ft_strcat(arg->buf, "0");
	ft_strcat(arg->buf, tmp);
	up = arg->buf;
	if (arg->conversion == 'X')
		while (*up && (*up = ft_toupper(*up)))
			up++;
	while (arg->minus && dw-- > 0)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static void		pf_helper_uox(t_arg *arg)
{
	int		dwidth;
	int		dprec;
	int		base;

	base = set_base(ft_tolower(arg->conversion));
	dwidth = 0;
	dprec = 0;
	arg->len = ft_nblenbase(arg->uval, base);
	if (!arg->uval && !arg->precision && (!arg->prefix
		|| (arg->prefix && base == 16)))
		arg->len--;
	arg->len += (base == 8 && arg->prefix && arg->uval ? 1 : 0);
	if (arg->precision > arg->len)
	{
		dprec = arg->precision - arg->len;
		arg->len = arg->precision;
	}
	arg->len += (base == 16 && arg->prefix && arg->uval ? 2 : 0);
	if (arg->min_width > arg->len)
	{
		dwidth = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_uox(arg, base, dwidth, dprec);
}

char			*pf_handler_uox(t_arg *arg)
{
	t_length_modifier		lm;

	if (ft_strchr("UO", arg->conversion))
		arg->length = l;
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
	pf_helper_uox(arg);
	return (arg->buf);
}
