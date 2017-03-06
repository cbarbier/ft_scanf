/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:25:48 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 15:53:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		set_flags(t_arg *arg, char *s)
{
	while (*s)
	{
		if (*s == ' ')
			arg->space = 1;
		if (*s == 'a')
			arg->alloc = 1;
		s++;
	}
}

static int		set_max_width(t_arg *arg, char *spec)
{
	int index;
	int val;

	index = 0;
	val = 0;
	while (spec[index] && ft_isdigit(spec[index]))
		val = 10 * val + spec[index++] - '0';
	arg->max_width = val;
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
	spec += set_max_width(arg, spec);
	set_length_modifier(arg, spec);
	if (ft_strchr(SPECIFIERS, arg->conversion))
		return (1);
	return (0);
}
