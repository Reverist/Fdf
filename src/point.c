/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:59:33 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 19:03:53 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *p)
{
	t_matrix	zoom;

	p->center.y = (p->points[p->max.y - 1][p->max.x - 1].y +
			p->points[0][0].y) / 2;
	p->center.x = (p->points[p->max.y - 1][p->max.x - 1].x +
			p->points[0][0].x) / 2;
	p->offs.x = WIN_WIDTH / 2 - p->center.x;
	p->offs.y = WIN_HEIGHT / 2 - p->center.y;
	p->offs.z = 1;
	p->angle = (t_matrix) {.x = 0, .y = 0, .z = 0};
	p->depth = 1;
	zoom.x = (WIN_WIDTH / p->max.y - 1) * 1.1;
	zoom.y = (WIN_HEIGHT / p->max.x - 1) * 1.1;
	p->scaling.x = (zoom.x <= zoom.y) ? zoom.x : zoom.y;
	p->scaling.y = p->scaling.x;
	p->scaling.z = -p->scaling.x;
}

void	matrix(t_fdf *p)
{
	t_point i;

	p->matrix = identity(0, p->scaling.x);
	p->matrix = ft_matrix_global_rotation(p->matrix, p->angle);
	p->matrix = matrix_z(p->matrix, p->depth);
	i.y = 0;
	while (i.y < p->max.y)
	{
		i.x = -1;
		while (++i.x < p->max.x)
		{
			p->mpoints[i.y][i.x] =
				matrix_to_vector(p->matrix, p->points[i.y][i.x], p->center);
		}
		++i.y;
	}
	ft_free_matrix(p->matrix);
}

int		mallocd(t_fdf *p)
{
	t_point	i;

	if (!(p->points = (t_matrix **)malloc(sizeof(t_matrix *) * p->max.y)) ||
			!(p->mpoints = (t_matrix **)malloc(sizeof(t_matrix *) * p->max.y)))
		return (0);
	i.y = 0;
	while (i.y < p->max.y)
	{
		if (!(p->points[i.y] =
					(t_matrix *)malloc(sizeof(t_matrix ) * p->max.x)) ||
				!(p->mpoints[i.y] =
					(t_matrix *)malloc(sizeof(t_matrix ) * p->max.x)))
			return (0);
		++i.y;
	}
	return (1);
}

void	norm_rotation(t_fdf *p, char axis, char i)
{
	double	a;

	a = 7.5 * (PI / 180);
	if (axis == 'z' || axis == 'a')
		p->angle.z += (i == '+') ? a : -a;
	if (axis == 'y' || axis == 'a')
		p->angle.y += (i == '+') ? a : -a;
	if (axis == 'x' || axis == 'a')
		p->angle.x += (i == '+') ? a : -a;
	while (p->angle.x >= 2 * PI)
		p->angle.x -= 2 * PI;
	while (p->angle.y >= 2 * PI)
		p->angle.y -= 2 * PI;
	while (p->angle.z >= 2 * PI)
		p->angle.z -= 2 * PI;
	while (p->angle.x < 0)
		p->angle.x += 2 * PI;
	while (p->angle.y < 0)
		p->angle.y += 2 * PI;
	while (p->angle.z < 0)
		p->angle.z += 2 * PI;
}

void	ft_free_matrix(double **m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(m[i]);
		++i;
	}
	free(m);
}
