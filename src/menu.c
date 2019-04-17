/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:48:04 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 18:49:19 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		menu_display(t_image *w, unsigned c)
{
	short	x;

	x = 0;
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 15, c,
			"Translate:[<-][->][^][v]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 45, c, "Zoom In/Out:[+]/[-]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 75, c,
			"Altitude: [Q] / [E]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 105, c,
			"Rotation: [1 - 8]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 135, c,
			"ISO : I");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 165, c,
			"Parallel : P");
	mlx_string_put(w->mlx_ptr, w->win_ptr, x, 195, c,
			"Exit : [ESCAPE]");
}

void		menu(t_fdf *p)
{
	t_point		i;
	t_point		max;
	int			border;

	max.y = 250;
	max.x = 250;
	i.y = -1;
	border = 4;
	while (++i.y < max.y)
	{
		i.x = -1;
		while (++i.x < max.x)
		{
			if (i.x > border && i.x < max.x - border && i.y > border && i.y
					< max.y - border)
				mlx_pixel_put(p->w.mlx_ptr, p->w.win_ptr, i.x, i.y, 0x2E8B57);
			else
				mlx_pixel_put(p->w.mlx_ptr, p->w.win_ptr, i.x, i.y, 0x2E8B57);
		}
	}
	menu_display(&(p->w), 0x000000);
}
