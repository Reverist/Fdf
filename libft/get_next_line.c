/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:00:47 by akrivosh          #+#    #+#             */
/*   Updated: 2018/12/28 15:15:53 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*malloc_t_line(t_line **save, int fd)
{
	t_line	*temp;
	t_line	*follow;

	if (!(*save))
	{
		(*save) = (t_line *)ft_memalloc(sizeof(t_line));
		(*save)->fd = fd;
	}
	temp = (*save);
	while ((*save))
	{
		if ((*save)->fd == fd)
			break ;
		if ((*save)->next == NULL)
		{
			(*save)->next = (t_line *)ft_memalloc(sizeof(t_line));
			(*save)->next->fd = fd;
		}
		(*save) = (*save)->next;
	}
	follow = (*save);
	(*save) = temp;
	return ((follow));
}

int		reading_loop(t_line *cur)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		red;

	red = 0;
	if (!ft_strchr(cur->tmp, '\n'))
		while ((red = read(cur->fd, buff, BUFF_SIZE)) > 0)
		{
			if (!cur->tmp)
				cur->tmp = ft_strnew(1);
			buff[red] = '\0';
			tmp = cur->tmp;
			cur->tmp = ft_strjoin(cur->tmp, buff);
			free(tmp);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	if (red < 0)
		return (-1);
	if (red == 0 && (cur->tmp == NULL || cur->tmp[0] == '\0'))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*save;
	int				ret;
	char			*y;
	char			*tmp;
	t_line			*cur;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	cur = malloc_t_line(&save, fd);
	if ((ret = reading_loop(cur)) == -1 || ret == 0)
		return (ret);
	if ((y = ft_strchr(cur->tmp, '\n')))
	{
		*line = ft_strsub(cur->tmp, 0, y - cur->tmp);
		tmp = cur->tmp;
		cur->tmp = ft_strdup(y + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(cur->tmp);
		ft_strdel(&cur->tmp);
	}
	return (1);
}
