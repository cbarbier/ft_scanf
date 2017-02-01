/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_lc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 18:46:48 by cbarbier         ###   ########.fr       */
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

static void		pf_helper2_lc(t_arg *arg, int nbytes, int dw)
{
	char	*tmp;

	if (arg->min_width > nbytes)
	{
		dw = arg->min_width - nbytes;
		arg->len = arg->min_width;
	}
	else
		arg->len = nbytes;
	arg->buf = ft_strnew(arg->len);
	while (!arg->minus && dw-- > 0)
		ft_strcat(arg->buf, (arg->zero ? "0" : " "));
	tmp = itowc((wchar_t)arg->val, nbytes);
	ft_strncat(arg->buf, tmp, nbytes);
	free(tmp);
	tmp = arg->buf + (!arg->minus ? dw : 0) + nbytes;
	while (arg->minus && dw-- > 0)
		ft_strcat(tmp, " ");
}

static void		pf_helper_lc(t_arg *arg)
{
	int		dw;
	int		nbytes;

	dw = 0;
	if (arg->val <= 0x07FF)
		arg->len = 2;
	else if (arg->val <= 0xFFFF)
		arg->len = 3;
	else if (arg->val <= 0x10FFFF)
		arg->len = 4;
	nbytes = arg->len;
	if (arg->min_width > arg->len)
	{
		dw = arg->min_width - arg->len;
		arg->len = arg->min_width;
	}
	pf_helper2_lc(arg, nbytes, dw);
}

char			*pf_handler_lc(t_arg *arg)
{
	arg->val = va_arg(*(arg->ap), int);
	if (arg->val < 0 || arg->val > 0x10FFFF)
	{
		arg->error = 1;
		arg->buf = ft_strnew(0);
	}
	else if (arg->val <= 0x7F)
		return (pf_handler_c(arg));
	pf_helper_lc(arg);
	return (arg->buf);
}
