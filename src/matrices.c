/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:40:59 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 18:47:38 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		**identity(int zero, int fill)
{
	double	**m;
	t_point	i;

	m = (double**)malloc(sizeof(double*) * 4);
	i.y = 0;
	while (i.y < 4)
	{
		m[i.y] = (double*)malloc(sizeof(double) * 4);
		i.x = 0;
		while (i.x < 4)
		{
			m[i.y][i.x] = (i.x != i.y) ? zero : fill;
			++i.x;
		}
		++i.y;
	}
	return (m);
}

double		**factor_matrix(double **a, double **b)
{
	double		**m;
	t_point		i;

	m = identity(0, 0);
	i.y = 0;
	while (i.y < 4)
	{
		i.x = 0;
		while (i.x < 4)
		{
			i.z = 0;
			while (i.z < 4)
			{
				m[i.y][i.x] += a[i.y][i.z] * b[i.z][i.x];
				++i.z;
			}
			++i.x;
		}
		++i.y;
	}
	ft_free_matrix(a);
	ft_free_matrix(b);
	return (m);
}

double		**matrix_z(double **matrix, double coef)
{
	matrix[0][2] *= coef;
	matrix[1][2] *= coef;
	return (matrix);
}

double		**ft_matrix_global_rotation(double **m, t_matrix a)
{
	double		**tmp;
	double		t;

	t = 100000;
	tmp = identity(0, 1);
	tmp[0][0] = (((D)(int)(cos(a.y) * t)) / t) * (((D)(int)(cos(a.z) * t)) / t);
	tmp[0][1] = (((D)(int)(cos(a.z) * t)) / t) * (((D)(int)(sin(a.x) * t)) / t)
		* (((D)(int)(sin(a.y) * t)) / t) - (((D)(int)(cos(a.x) * t)) / t)
		* (((D)(int)(sin(a.z) * t)) / t);
	tmp[0][2] = (((D)(int)(cos(a.x) * t)) / t) * (((D)(int)(cos(a.z) * t)) / t)
		* (((D)(int)(sin(a.y) * t)) / t) + (((D)(int)(sin(a.x) * t)) / t)
		* (((D)(int)(sin(a.z) * t)) / t);
	tmp[1][0] = (((D)(int)(cos(a.y) * t)) / t) * (((D)(int)(sin(a.z) * t)) / t);
	tmp[1][1] = (((D)(int)(cos(a.x) * t)) / t) * (((D)(int)(cos(a.z) * t)) / t)
		+ (((D)(int)(sin(a.x) * t)) / t) * (((D)(int)(sin(a.y) * t)) / t)
		* (((D)(int)(sin(a.z) * t)) / t);
	tmp[1][2] = (((D)(int)(-cos(a.z) * t)) / t) * (((D)(int)(sin(a.x) * t)) / t)
		+ (((D)(int)(cos(a.x) * t)) / t) * (((D)(int)(sin(a.y) * t)) / t)
		* (((D)(int)(sin(a.z) * t)) / t);
	tmp[2][0] = (((D)(int)(-sin(a.y) * t)) / t);
	tmp[2][1] = (((D)(int)(cos(a.y) * t)) / t) * (((D)(int)(sin(a.x) * t)) / t);
	tmp[2][2] = (((D)(int)(cos(a.x) * t)) / t) * (((D)(int)(cos(a.y) * t)) / t);
	m = factor_matrix(m, tmp);
	return (m);
}

t_matrix	matrix_to_vector(double **m, t_matrix v, t_matrix c)
{
	t_matrix	n;

	v.x -= c.x;
	v.y -= c.y;
	v.z -= c.z;
	n.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3] * v.w + c.x;
	n.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3] * v.w + c.y;
	n.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3] * v.w + c.z;
	n.w = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + m[3][3] * v.w;
	return (n);
}
