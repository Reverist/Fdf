/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:25:46 by akrivosh          #+#    #+#             */
/*   Updated: 2018/12/28 15:17:16 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 34
# include "libft.h"

typedef struct		s_line
{
	char			*tmp;
	int				fd;
	struct s_line	*next;
}					t_line;
int					get_next_line(const int fd, char **line);

#endif
