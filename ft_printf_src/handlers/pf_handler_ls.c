/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:50:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*itowc(wchar_t wc, int nb)
{
	unsigned char	*res;
	unsigned char	h;
	int				i;

	if (!(res = (unsigned char *)ft_memalloc(nb * sizeof(unsigned char))))
		return (0);
	i = 0;
	h = 0;
	if (nb == 4 && (h = !h ? 0xf0 : h))
		res[3] = 0x80 + (wc >> 6 * i++ & 0x3F);
	if (nb >= 3 && (h = !h ? 0xE0 : h))
		res[2] = 0x80 + (wc >> 6 * i++ & 0x3F);
	if (nb >= 2 && (h = !h ? 0xC0 : h))
		res[1] = 0x80 + (wc >> 6 * i++ & 0x3F);
	res[0] = h + (wc >> (i * 6));
	return ((char *)res);
}

static void		set_dw_ls(t_arg *arg)
{
	int		dw;
	char	*tmp;
	int		ln;

	dw = 0;
	ln = arg->len;
	if (arg->precision > -1)
		ln = arg->precision > arg->len ? arg->len : arg->precision;
	if (arg->min_width > ln)
		dw = arg->min_width - ln;
	arg->len = (dw ? arg->min_width : ln);
	tmp = arg->buf;
	arg->buf = ft_strnew(arg->len);
	while (!arg->minus && dw-- > 0)
		ft_strcat(arg->buf, (arg->zero ? "0" : " "));
	ft_strncat(arg->buf, tmp, ln);
	while (arg->minus && dw-- > 0)
		ft_strcat(arg->buf, " ");
	free(tmp);
}

static char		*pf_tool_ls(t_arg *arg, wchar_t wc, int *len)
{
	char		c;
	int			dw;

	if ((wc < 0 || wc > 0x10FFFF) && (arg->error = 1))
		return (ft_strnew(0));
	if (wc < 0x7F)
	{
		*len = 1;
		c = (char)wc;
		return (ft_strncpy(ft_strdup(" "), &c, 1));
	}
	dw = 0;
	if (wc <= 0x07FF)
		*len = 2;
	else if (wc <= 0xFFFF)
		*len = 3;
	else if (wc <= 0x10FFFF)
		*len = 4;
	if (arg->precision > -1 && arg->len + (*len) > arg->precision)
		return (ft_strnew(0));
	return (itowc(wc, *len));
}

char			*pf_handler_ls(t_arg *arg)
{
	int		len;
	wchar_t *p;

	p = va_arg(*(arg->ap), wchar_t *);
	if (!p && (arg->len = 6))
	{
		arg->precision = -1;
		arg->buf = ft_strdup("(null)");
		set_dw_ls(arg);
		return (arg->buf);
	}
	arg->buf = ft_strnew(0);
	len = 1;
	while (*p && len)
	{
		len = 0;
		arg->buf = ft_strjoinfree(arg->buf, pf_tool_ls(arg, *p, &len));
		if (arg->precision > -1 && arg->len + len > arg->precision)
			len = 0;
		else
			arg->len += len;
		p++;
	}
	set_dw_ls(arg);
	return (arg->buf);
}
