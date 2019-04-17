/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:13:04 by akrivosh          #+#    #+#             */
/*   Updated: 2019/04/17 19:20:53 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <limits.h>
# include <math.h>
# include <float.h>
# include "keyh.h"
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720
# define PI						3.14159265359
# define D double
# define I int
# define KEYPRESS				2
# define KEYRELEASE				3
# define KEYPRESSMASK			(1L << 0)
# define KEYRELEASEMASK			(1L << 1)

typedef struct	s_image
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_image;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct	s_matrix
{
	double x;
	double y;
	double z;
	double w;
}				t_matrix;

typedef struct	s_fdf
{
	t_image		w;
	char		*r;
	t_list		*lst;
	t_point		max;
	double		**matrix;
	double		depth;
	t_matrix	**mpoints;
	t_matrix	**points;
	t_matrix	angle;
	t_matrix	offs;
	t_matrix	scaling;
	t_matrix	center;
}				t_fdf;

void			reading(int fd, t_fdf *p);
int				ft_getwidth(char *s, char c);
int				process(t_fdf *p);
void			ft_lstrev(t_list **alst);
t_matrix		prep_point(t_matrix raw, t_fdf *p);
t_matrix		get_p(int x, int y, t_fdf *p);
void			mlx_draw(t_fdf *p);
int				ft_freesplit(char ***split);
void			new_image(t_fdf *p);
void			set_pixel(t_fdf *p, t_matrix a, int color);
void			mlx(t_fdf *p);
int				mallocd(t_fdf *p);
t_matrix		matrix_to_vector(double **m, t_matrix v, t_matrix c);
double			**ft_matrix_global_rotation(double **m, t_matrix a);
double			**matrix_z(double **matrix, double coef);
double			**factor_matrix(double **a, double **b);
void			ft_free_matrix(double **m);
double			**identity(int zero, int fill);
void			init(t_fdf *p);
void			matrix(t_fdf *p);
void			drawline(t_fdf *p, t_matrix p0, t_matrix p1);
void			error(char *str);
int				translation_hook(int k, t_fdf *p);
int				rotation_hook(int k, t_fdf *p);
void			norm_rotation(t_fdf *p, char axis, char i);
int				user_hook(int k, t_fdf *p);
void			menu_display(t_image *w, unsigned c);
void			menu(t_fdf *p);
int				scaling_hook(int k, t_fdf *p);
void			iso(t_fdf *p);
#endif
