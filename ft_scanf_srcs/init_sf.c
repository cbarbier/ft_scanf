/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:19:34 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 16:00:51 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	set_handler(t_handler *handler, char *v, char *(*f)(t_arg *arg))
{
	handler->c = *v;
	handler->f = f;
}

static void	init_sf_specifiers(t_pf *pf)
{
	t_handler *handlers;

	handlers = pf->handlers;
	set_handler(handlers, "%", &pf_handler_percent);
	set_handler(handlers + 1, "s", &sf_handler_s);
	set_handler(handlers + 2, "S", &sf_handler_ls);
	set_handler(handlers + 3, "p", &sf_handler_p);
	set_handler(handlers + 4, "d", &sf_handler_di);
	set_handler(handlers + 5, "D", &sf_handler_di);
	set_handler(handlers + 6, "i", &sf_handler_di);
	set_handler(handlers + 7, "o", &sf_handler_uox);
	set_handler(handlers + 8, "O", &sf_handler_uox);
	set_handler(handlers + 9, "u", &sf_handler_uox);
	set_handler(handlers + 10, "U", &sf_handler_uox);
	set_handler(handlers + 11, "x", &sf_handler_uox);
	set_handler(handlers + 12, "X", &sf_handler_uox);
	set_handler(handlers + 13, "c", &sf_handler_c);
	set_handler(handlers + 14, "C", &sf_handler_lc);
	set_handler(handlers + 15, "b", &sf_handler_b);
	set_handler(handlers + 16, "B", &sf_handler_b);
	set_handler(handlers + 17, "f", &sf_handler_f);
	set_handler(handlers + 18, "F", &sf_handler_f);
}

void		init_sf(t_pf *pf)
{
	ft_memset(pf, 0, sizeof(t_sf));
	init_sf_specifiers(pf);
}
