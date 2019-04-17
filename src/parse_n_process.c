/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:49:40 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 18:59:08 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getwidth(char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

void	reading(int fd, t_fdf *p)
{
	char	*l;
	t_list	*buff;
	int		ret;

	p->max.y = 0;
	p->max.x = 0;
	l = NULL;
	while ((ret = get_next_line(fd, &l)))
	{
		if (ret == -1 || ret == 0 || !l)
			error("Read error");
		if (!p->max.x)
			p->max.x = ft_getwidth(l, ' ');
		if (p->max.x != ft_getwidth(l, ' ') || p->max.x == 0)
			error("Invalid");
		if (!(buff = ft_lstnew(l, ft_strlen(l) + 1)))
			error("Cant' create list");
		ft_lstadd(&p->lst, buff);
		ft_strdel(&l);
		++p->max.y;
	}
	if (p->max.x < 1)
		error("bad file");
	ft_lstrev(&p->lst);
}

int		process(t_fdf *p)
{
	t_point	i;
	char	**tmp;
	t_list	*list;

	list = p->lst;
	i.y = -1;
	while (++i.y < p->max.y)
	{
		i.x = -1;
		tmp = ft_strsplit(list->content, ' ');
		while (++i.x < p->max.x)
		{
			p->points[i.y][i.x].z = (double)ft_atoi(tmp[i.x]);
			p->points[i.y][i.x].x = i.x;
			p->points[i.y][i.x].y = i.y;
		}
		ft_freesplit(&tmp);
		list = list->next;
	}
	return (1);
}

void	ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

int		ft_freesplit(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*split)[i];
	}
	ft_memdel((void **)split);
	return (0);
}
