/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:08 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 18:39:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H
# include <stdarg.h>
# include <inttypes.h>
# include "libft.h"
# define NB_SPEC			19
# define SPECIFIERS			"%sSpdDioOuUxXcCbBfF"
# define FLAGS				" a"
# define LM					"lmhjz"
typedef enum	e_length_modifier
{
	none,
	hh,
	h,
	ll,
	l,
	j,
	z
}				t_length_modifier;

typedef struct				s_arg
{
	intmax_t				val;
	uintmax_t				uval;
	char					*text;
	int						error;
	int						alloc;
	int						space;
	int						max_width;
	t_length_modifier		length;
	char					conversion;
	char					*buf;
	int						len;
	va_list					*ap;
}							t_arg;

typedef struct				s_handler
{
	char					c;
	char					*(*f)(t_arg *arg);
}							t_handler;

typedef struct				s_sf
{
	int						ret;
	char					*buff;
	int						len;
	char					*buf;
	t_handler				handlers[NB_SPEC];
	t_arg					*arg;
	va_list					*ap;
}							t_sf;

int							ft_scanf(int fd, const char *format, ...);
void						init_sf(t_sf *sf);
void						split_args(t_sf *sf, const char *format);
int							check_arg(t_arg *arg);
int							scan_buffer(t_sf *sf);
char						read_at_index(t_sf *sf, int index);
int							init_buff(t_sf *sf);
char						*sf_handler_di(t_arg *arg);
char						*sf_handler_uox(t_arg *arg);
char						*sf_handler_c(t_arg*arg);
char						*sf_handler_s(t_arg *arg);
char						*sf_handler_p(t_arg *arg);
char						*sf_handler_ls(t_arg *arg);
char						*sf_handler_lc(t_arg *arg);
char						*sf_handler_percent(t_arg *arg);
char						*sf_handler_other(t_arg *arg);
char						*sf_handler_b(t_arg *arg);
char						*sf_handler_f(t_arg *arg);

#endif
