/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:43:49 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 19:03:16 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H
# include <stdarg.h>
# include "libft.h"
# define NB_SF_SPEC			4
# define SF_SPEC			"disc"
# define SPACES				" \t"

typedef struct s_sf			t_sf;
typedef struct				s_sfhandler
{
	char					c;
	int						(*f)(t_sf *sf);
}							t_sfhandler;
struct						s_sf
{
	int						ret;
	char					buff;
	char					conv;
	int						len;
	int						fd;
	int						index;
	t_sfhandler				handlers[NB_SF_SPEC];
	va_list					*ap;
};
int							ft_scanf(int fd, const char *format, ...);
int							init_sf(t_sf *sf, int fd);
int							sf_core(t_sf *sf, const char *format);
int							scan_arg(t_sf *sf);
char						read_buff_at_index(t_sf *sf);
int							sf_handler_di(t_sf *sf);
int							sf_handler_c(t_sf *sf);
int							sf_handler_s(t_sf *sf);

#endif
