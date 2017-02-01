/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:28:16 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 09:48:31 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*pf_join(t_pf *pf, t_arg *arg)
{
	char	*buf;

	if (!pf->buf || !arg->buf)
		return (NULL);
	if (!(buf = ft_strnew(pf->ret + arg->len)))
		return (NULL);
	ft_memcpy(buf, pf->buf, pf->ret);
	ft_memcpy(buf + pf->ret, arg->buf, arg->len);
	ft_strdel(&(arg->buf));
	ft_strdel(&(pf->buf));
	return (buf);
}
