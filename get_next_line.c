/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:55:34 by cbarbier          #+#    #+#             */
/*   Updated: 2016/11/28 11:37:09 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fbuffer	*find_create_fbuffer(const int fd, t_list **alst)
{
	t_list		*elm;
	t_fbuffer	fbuffer;

	elm = *alst;
	while (elm)
	{
		if (((t_fbuffer *)(elm->content))->fd == fd)
			return (elm->content);
		elm = elm->next;
	}
	fbuffer.fd = fd;
	if (!(fbuffer.data = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(elm = ft_lstnew(&fbuffer, sizeof(t_fbuffer))))
		return (NULL);
	ft_lstadd(alst, elm);
	return ((*alst)->content);
}

static int			read_line(t_fbuffer *fbuffer)
{
	int			count;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	count = 1;
	while (count > 0 && !ft_strchr(fbuffer->data, '\n'))
	{
		if ((count = read(fbuffer->fd, &buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[count] = 0;
		tmp = fbuffer->data;
		fbuffer->data = ft_strjoin(fbuffer->data, buff);
		free(tmp);
		ft_memset(buff, 0, count);
	}
	return (count);
}

static char			*update_line(char *str)
{
	char	*pos;

	if (!(pos = ft_strchr(str, '\n')))
		return (ft_strdup(str));
	return (ft_strsub(str, 0, pos - str));
}

static void			shift_data(char **data)
{
	char *tmp;
	char *pos;

	tmp = *data;
	if (!(pos = ft_strchr(tmp, '\n')))
		*data = ft_strnew(0);
	else
		*data = ft_strdup(pos + 1);
	free(tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_fbuffer		*fbuffer;
	char			*tmp;
	int				count;

	if (!line || fd < 0)
		return (-1);
	fbuffer = find_create_fbuffer(fd, &lst);
	if ((count = read_line(fbuffer)) == -1)
		return (-1);
	*line = update_line(fbuffer->data);
	tmp = fbuffer->data;
	shift_data(&(fbuffer->data));
	if (!**line && !count)
		return (0);
	else
		return (1);
}
