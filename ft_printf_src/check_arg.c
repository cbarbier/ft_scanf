/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:25:48 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 19:01:09 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		set_flags(t_arg *arg, char *s)
{
	while (*s)
	{
		if (*s == '#')
			arg->prefix = 1;
		else if (*s == '0' && !ft_isdigit(*(s - 1)))
			arg->zero = 1;
		else if (*s == '-')
			arg->minus = 1;
		else if (*s == '+')
			arg->plus = 1;
		else if (*s == ' ')
			arg->space = 1;
		if (arg->minus)
			arg->zero = 0;
		if (arg->plus)
			arg->space = 0;
		s++;
	}
}

static int		set_min_width(t_arg *arg, char *spec)
{
	int index;
	int val;

	index = 0;
	val = 0;
	while (spec[index] && ft_isdigit(spec[index]))
		val = 10 * val + spec[index++] - '0';
	if (spec[index] == '*' && ++index)
		val = va_arg(*(arg->ap), int);
	if (spec[index] && ft_isdigit(spec[index]) && !(val = 0))
		while (spec[index] && ft_isdigit(spec[index]))
			val = 10 * val + spec[index++] - '0';
	arg->min_width = val < 0 ? -val : val;
	arg->minus = val < 0 ? 1 : arg->minus;
	return (index);
}

static int		set_precision(t_arg *arg, char *spec)
{
	int		index;
	int		val;

	index = 0;
	if (spec[index++] != '.' && (arg->precision = -1))
		return (0);
	if (spec[index] == '*')
	{
		val = va_arg(*(arg->ap), int);
		arg->precision = val < 0 ? -1 : val;
		return (2);
	}
	if (!ft_isdigit(spec[index]))
	{
		arg->precision = 0;
		return (index);
	}
	val = 0;
	while (spec[index] && ft_isdigit(spec[index]))
		val = 10 * val + spec[index++] - '0';
	arg->precision = (index ? val : -1);
	return (index);
}

static void		set_length_modifier(t_arg *arg, char *format)
{
	char		*tmp;

	if ((tmp = ft_strstr(format, "z")))
		arg->length = z;
	else if ((tmp = ft_strstr(format, "j")))
		arg->length = j;
	else if ((tmp = ft_strstr(format, "ll")))
		arg->length = ll;
	else if ((tmp = ft_strstr(format, "l")))
		arg->length = l;
	else if ((tmp = ft_strstr(format, "hh")))
		arg->length = hh;
	else if ((tmp = ft_strstr(format, "h")))
		arg->length = h;
	else
		arg->length = none;
}

int				check_arg(t_arg *arg)
{
	char	*spec;
	int		index;

	if (!arg->conversion)
		return (0);
	index = 1;
	spec = arg->text;
	while (spec[index] && ft_strchr(FLAGS, spec[index]))
		index++;
	set_flags(arg, spec);
	spec += index;
	spec += set_min_width(arg, spec);
	spec += set_precision(arg, spec);
	set_length_modifier(arg, spec);
	if (ft_strchr(SPECIFIERS, arg->conversion))
		return (1);
	return (0);
}
