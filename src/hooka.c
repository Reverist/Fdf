/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:27:55 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 18:34:41 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		translation_hook(int k, t_fdf *p)
{
	if (k >= 123 && k <= 126)
	{
		if (k == 123 || k == 124)
			p->offs.x += (k == 124) ? 20 : -20;
		else if (k == 125 || k == 126)
			p->offs.y += (k == 126) ? -20 : 20;
	}
	return (1);
}

int		scaling_hook(int k, t_fdf *p)
{
	if (k == 69)
	{
		p->scaling.x *= 1.25;
		p->scaling.y *= 1.25;
		p->scaling.z *= 1.25;
		p->scaling.w *= 1.25;
	}
	else if (k == 78 && p->scaling.x > 0.05)
	{
		p->scaling.x *= 0.9;
		p->scaling.y *= 0.9;
		p->scaling.z *= 0.9;
		p->scaling.w *= 0.9;
	}
	else if (k == 12 || k == 14)
	{
		if (k == 14 && p->depth < 100)
			p->depth *= 1.10;
		else if (p->depth > 0.05)
			p->depth *= 0.9;
	}
	return (1);
}

int		rotation_hook(int k, t_fdf *p)
{
	if (k == 18 || k == 19)
		(k == 19) ? norm_rotation(p, 'z', '+') : norm_rotation(p, 'z', '-');
	else if (k == 20 || k == 21)
		(k == 21) ? norm_rotation(p, 'y', '+') : norm_rotation(p, 'y', '-');
	else if (k == 23 || k == 22)
		(k == 22) ? norm_rotation(p, 'x', '+') : norm_rotation(p, 'x', '-');
	else if (k == 26 || k == 28)
		k == 26 ? norm_rotation(p, 'a', '+') : norm_rotation(p, 'a', '-');
	return (1);
}

void	iso(t_fdf *p)
{
	double	p_x;
	double	p_y;
	double	z;

	if (p->angle.x == 0 && p->angle.y == 0)
		p->angle = (t_matrix) {.x = -0.1, .y = 6.5, .z = 12};
	z = p->angle.z;
	p_x = p->angle.x;
	p_y = p->angle.y;
	p->angle.x = (p_x - p_y) * cos(0.523599);
	p->angle.y = -z + (p_x + p_y) * sin(0.523599);
}

int		user_hook(int k, t_fdf *p)
{
	if (k == 53)
		mlx_destroy_window(p->w.mlx_ptr, p->w.win_ptr);
	if (k == 53)
		exit(0);
	if (k == KEY_I)
	{
		iso(p);
		mlx_clear_window(p->w.mlx_ptr, p->w.win_ptr);
		mlx(p);
	}
	if (k == KEY_P)
	{
		p->angle = (t_matrix) {.x = 0, .y = 0, .z = 0};
		mlx_clear_window(p->w.mlx_ptr, p->w.win_ptr);
		mlx(p);
	}
	else
	{
		rotation_hook(k, p);
		scaling_hook(k, p);
		translation_hook(k, p);
		mlx_clear_window(p->w.mlx_ptr, p->w.win_ptr);
		mlx(p);
	}
	return (1);
}
