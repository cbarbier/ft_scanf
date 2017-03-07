/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:48:16 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 19:52:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"



static int	find_arg(t_pf *pf, t_arg *arg, const char *format)
{
	int		len;

	if (*format == '%' && format[1])
	{
		arg.conversion = format[1];
		return (2);
	}
	len = 0;
	while (format[len] && format[len] != '%')
	{
		if (read_buff_at_index(sf) != format[len++])
			return (-1);
		sf->index++;
	}
	return (len);
}

int		sf_core(t_pf *pf, const char *format)
{
	int		tmp;
	t_arg	arg;

	while (*format)
	{
		ft_memset(&arg, 0, sizeof(t_arg));
		if ((tmp = find_arg(pf, &arg, format)) < 0)
			return (0);
		pf->arg = &arg;
		pf->ret = scan_arg(pf);
		format += tmp;
	}
	return (1);
}
