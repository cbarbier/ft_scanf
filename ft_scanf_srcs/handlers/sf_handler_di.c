/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_handler_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:13:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 18:56:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		pf_helper2_di(t_arg *arg, int dw, int dp)
{
	char		*tmp;

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

static void		sf_helper_di(t_arg *arg)
{
	while ()
}

char			*sf_handler_di(t_arg *arg)
{
	t_length_modifier		lm;

	if (arg->conversion == 'D')
		arg->length = l;
	lm = arg->length;
	if (lm == hh)
		arg->p = (char*)va_arg(*(arg->ap), int *);
	else if (lm == h)
		arg->p = (short int*)va_arg(*(arg->ap), int*);
	else if (lm == ll)
		arg->p = va_arg(*(arg->ap), long long int*);
	else if (lm == l)
		arg->p = va_arg(*(arg->ap), long int*);
	else if (lm == j)
		arg->p = va_arg(*(arg->ap), intmax_t*);
	else if (lm == z)
		arg->p = va_arg(*(arg->ap), ssize_t*);
	else
		arg->val = va_arg(*(arg->ap), int*);
	sf_helper_di(arg);
	return (0);
}
