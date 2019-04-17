/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:36:29 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 18:39:45 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_fdf *p, t_matrix a, int color)
{
	int	x;
	int	y;

	x = round(a.x) + p->offs.x;
	y = round(a.y) + p->offs.y;
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		*(int *)&p->w.ptr[(x * p->w.bits_per_pixel) +
			(y * p->w.size_line)] = color;
}

void	drawline(t_fdf *p, t_matrix p0, t_matrix p1)
{
	t_matrix	dif;
	t_matrix	i;
	int			pixel;
	double		tmp;

	dif.x = fabs(p1.x - p0.x);
	dif.y = fabs(p1.y - p0.y);
	tmp = (dif.x > dif.y) ? dif.x : dif.y;
	pixel = (!round(tmp)) ? 1 : round(tmp);
	i.x = dif.x / tmp * (p0.x < p1.x ? 1 : -1);
	i.y = dif.y / tmp * (p0.y < p1.y ? 1 : -1);
	while (pixel)
	{
		if ((p0.x > WIN_WIDTH && p0.x < 0) && (p0.y > WIN_HEIGHT && p0.y < 0))
			pixel = 0;
		set_pixel(p, p0, 0x808000);
		p0.x += i.x;
		p0.y += i.y;
		pixel--;
	}
}
