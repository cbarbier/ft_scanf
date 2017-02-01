# ************************************************************************** */
#                                                                            */
#                                                        :::      ::::::::   */
#   Makefile                                           :+:      :+:    :+:   */
#                                                    +:+ +:+         +:+     */
#   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
#                                                +#+#+#+#+#+   +#+           */
#   Created: 2016/07/12 12:31:51 by cbarbier          #+#    #+#             */
#   Updated: 2016/07/12 14:18:23 by cbarbier         ###   ########.fr       */
#                                                                            */
# ************************************************************************** */

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC  = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strjoinfree.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_pow.c \
	   ft_itoa.c \
	   ft_ftoa.c \
	   ft_itoa_base.c \
	   ft_imtoa_base.c \
	   ft_uimtoa_base.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstpushback.c \
	   ft_lstshift.c \
	   ft_nblen.c \
	   ft_nblenbase.c \
	   ft_sqrt.c \
	   ft_swapbits.c \
	   ft_printbits.c \
	   get_next_line.c \
	   ft_printf_src/ft_printf.c \
	   ft_printf_src/split_args.c \
	   ft_printf_src/init_pf.c \
	   ft_printf_src/arg_to_buffer.c \
	   ft_printf_src/check_arg.c \
	   ft_printf_src/pf_tools.c \
	   ft_printf_src/handlers/pf_handler_di.c \
	   ft_printf_src/handlers/pf_handler_uox.c \
	   ft_printf_src/handlers/pf_handler_s.c \
	   ft_printf_src/handlers/pf_handler_p.c \
	   ft_printf_src/handlers/pf_handler_c.c \
	   ft_printf_src/handlers/pf_handler_lc.c \
	   ft_printf_src/handlers/pf_handler_ls.c \
	   ft_printf_src/handlers/pf_handler_percent.c \
	   ft_printf_src/handlers/pf_handler_b.c \
	   ft_printf_src/handlers/pf_handler_f.c \
	   ft_printf_src/handlers/pf_handler_other.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -I includes -o $@ 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean
