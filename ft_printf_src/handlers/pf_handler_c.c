/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handler_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 11:28:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		pf_helper_c(t_arg *arg)
{
	int		dw;
	char	c;
	char	*tmp;

	dw = 0;
	c = (char)(arg->val);
	if (arg->min_width > 1)
	{
		dw = arg->min_width - 1;
		arg->len = arg->min_width;
	}
	else
		arg->len = 1;
	arg->buf = ft_strnew(arg->len);
	tmp = arg->buf;
	while (!arg->minus && dw-- > 0 && tmp++)
		ft_strcat(arg->buf, (arg->zero ? "0" : " "));
	ft_strncat(arg->buf, &c, 1);
	tmp++;
	while (arg->minus && dw-- > 0)
		ft_strcat(tmp, " ");
}

char		*pf_handler_c(t_arg *arg)
{
	t_length_modifier	lm;

	lm = arg->length;
	if (arg->conversion == 'C')
		arg->len = 1;
	else if ((ft_strchr(LM, arg->conversion)
			|| ft_strchr(FLAGS, arg->conversion)) && !(arg->len = 0))
		return ((arg->buf = ft_strdup("")));
	else if (arg->conversion != 'c')
		arg->val = arg->conversion;
	else if (lm == l)
		return (pf_handler_lc(arg));
	else
		arg->val = (char)va_arg(*(arg->ap), int);
	pf_helper_c(arg);
	return (arg->buf);
}
