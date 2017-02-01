/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:19:34 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 13:15:11 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	set_handler(t_handler *handler, char *v, char *(*f)(t_arg *arg))
{
	handler->c = *v;
	handler->f = f;
}

static void	init_pf_specifiers(t_pf *pf)
{
	t_handler *handlers;

	handlers = pf->handlers;
	set_handler(handlers, "%", &pf_handler_percent);
	set_handler(handlers + 1, "s", &pf_handler_s);
	set_handler(handlers + 2, "S", &pf_handler_ls);
	set_handler(handlers + 3, "p", &pf_handler_p);
	set_handler(handlers + 4, "d", &pf_handler_di);
	set_handler(handlers + 5, "D", &pf_handler_di);
	set_handler(handlers + 6, "i", &pf_handler_di);
	set_handler(handlers + 7, "o", &pf_handler_uox);
	set_handler(handlers + 8, "O", &pf_handler_uox);
	set_handler(handlers + 9, "u", &pf_handler_uox);
	set_handler(handlers + 10, "U", &pf_handler_uox);
	set_handler(handlers + 11, "x", &pf_handler_uox);
	set_handler(handlers + 12, "X", &pf_handler_uox);
	set_handler(handlers + 13, "c", &pf_handler_c);
	set_handler(handlers + 14, "C", &pf_handler_lc);
	set_handler(handlers + 15, "b", &pf_handler_b);
	set_handler(handlers + 16, "B", &pf_handler_b);
	set_handler(handlers + 17, "f", &pf_handler_f);
	set_handler(handlers + 18, "F", &pf_handler_f);
}

void		init_pf(t_pf *pf)
{
	ft_memset(pf, 0, sizeof(t_pf));
	pf->buf = ft_strnew(0);
	init_pf_specifiers(pf);
}
