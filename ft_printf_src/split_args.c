/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:48:16 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 18:50:53 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_arg(t_pf *pf, const char *format)
{
	int		len;
	t_arg	arg;

	if ((len = 1) && *format == '%')
	{
		while (format[len] && (ft_isdigit(format[len]) ||
			ft_strchr("*.", format[len]) || ft_strchr(LM, format[len])
					|| ft_strchr(FLAGS, format[len])))
			len++;
		len = format[len] ? len + 1 : len;
	}
	else
		while (format[len] && format[len] != '%')
			len++;
	ft_memset(&arg, 0, sizeof(t_arg));
	arg.text = ft_strsub(format, 0, len);
	if (*format == '%')
		arg.conversion = format[(len > 1 ? len - 1 : len)];
	else
		arg.val = format[len - 1];
	pf->arg = &arg;
	pf->ret = arg_to_buffer(pf);
	ft_strdel(&(arg.text));
	return (len);
}

void		split_args(t_pf *pf, const char *format)
{
	while (*format && pf->ret >= 0)
	{
		format += find_arg(pf, format);
	}
}
