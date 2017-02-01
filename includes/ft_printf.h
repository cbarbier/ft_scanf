/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:08 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/30 20:46:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <inttypes.h>
# include "libft.h"
# define NB_SPEC			19
# define SPECIFIERS			"%sSpdDioOuUxXcCbBfF"
# define FLAGS				" #-+0"
# define LM					"lmhjz"
# define RED				"\x1B[31m"
# define GRN				"\x1B[32m"
# define YEL				"\x1B[33m"
# define BLU				"\x1B[34m"
# define EOC				"\033[0m"
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
	uintmax_t				uval;
	intmax_t				val;
	char					*s;
	void					*p;
	double					d;
	char					*text;
	int						error;
	int						prefix;
	int						sign;
	int						zero;
	int						minus;
	int						space;
	int						plus;
	int						min_width;
	int						precision;
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

typedef struct				s_pf
{
	int						ret;
	int						len;
	char					*buf;
	t_handler				handlers[NB_SPEC];
	t_arg					*arg;
	va_list					*ap;
}							t_pf;

int							ft_printf(const char *format, ...);
void						init_pf(t_pf *pf);
void						split_args(t_pf *pf, const char *format);
int							check_arg(t_arg *arg);
int							arg_to_buffer(t_pf *pf);
char						*pf_join(t_pf *pf, t_arg *arg);
char						*pf_handler_di(t_arg *arg);
char						*pf_handler_uox(t_arg *arg);
char						*pf_handler_c(t_arg*arg);
char						*pf_handler_s(t_arg *arg);
char						*pf_handler_p(t_arg *arg);
char						*pf_handler_ls(t_arg *arg);
char						*pf_handler_lc(t_arg *arg);
char						*pf_handler_percent(t_arg *arg);
char						*pf_handler_other(t_arg *arg);
char						*pf_handler_b(t_arg *arg);
char						*pf_handler_f(t_arg *arg);

#endif
