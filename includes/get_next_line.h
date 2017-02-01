/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:08 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/28 11:35:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# define BUFF_SIZE 32

typedef struct				s_fbuffer
{
	int						fd;
	char					*data;
}							t_fbuffer;

int							get_next_line(const int fd, char **line);

#endif
