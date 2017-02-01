/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:47:52 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 18:50:11 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*call_handler(t_pf *pf, char conversion)
{
	int		index;
	t_arg	*arg;

	arg = (t_arg *)pf->arg;
	index = 0;
	while (index < NB_SPEC && pf->handlers[index].c != conversion)
		index++;
	if (index < NB_SPEC)
		return (pf->handlers[index].f(arg));
	return (pf_handler_other(arg));
}

int			arg_to_buffer(t_pf *pf)
{
	t_arg	*arg;

	arg = (t_arg *)pf->arg;
	arg->ap = pf->ap;
	check_arg(arg);
	arg->buf = call_handler(pf, arg->conversion);
	pf->buf = pf_join(pf, arg);
	if (pf->arg->error)
		return (-1);
	pf->ret += arg->len;
	return (pf->ret);
}
