/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:17:58 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 18:27:09 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx(t_fdf *p)
{
	new_image(p);
	matrix(p);
	mlx_draw(p);
	mlx_put_image_to_window(p->w.mlx_ptr, p->w.win_ptr, p->w.img, 0, 0);
	menu(p);
	mlx_hook(p->w.win_ptr, KEYPRESS, KEYPRESSMASK, user_hook, p);
	mlx_loop(p->w.mlx_ptr);
}

void	new_image(t_fdf *p)
{
	p->w.img = mlx_new_image(p->w.mlx_ptr, 1280, 720);
	p->w.ptr = mlx_get_data_addr(p->w.img,
			&p->w.bits_per_pixel, &p->w.size_line, &p->w.endian);
	p->w.bits_per_pixel /= 8;
}

void	mlx_draw(t_fdf *p)
{
	t_point	i;

	i.y = 0;
	while (i.y < p->max.y)
	{
		i.x = -1;
		while (++i.x < p->max.x)
		{
			if (i.x < p->max.x - 1)
				drawline(p, p->mpoints[i.y][i.x], p->mpoints[i.y][i.x + 1]);
			if (i.y < p->max.y - 1)
				drawline(p, p->mpoints[i.y][i.x], p->mpoints[i.y + 1][i.x]);
		}
		++i.y;
	}
	drawline(p, p->mpoints[i.y - 1][i.x - 1], p->mpoints[i.y - 1][i.x - 1]);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_fdf	p;
	int		fd;

	list = NULL;
	if (ac != 2)
		error("Please insert the file name");
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || fd == 0 || !fd)
		error("Can't open file");
	reading(fd, &p);
	if (!mallocd(&p))
		error("Error allocating the memory");
	if (!process(&p))
		error("Can't process the map points");
	init(&p);
	p.w.mlx_ptr = mlx_init();
	p.w.win_ptr = mlx_new_window(p.w.mlx_ptr, 1280, 720, "lol");
	mlx(&p);
}
