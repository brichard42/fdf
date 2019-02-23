/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:12:31 by brichard          #+#    #+#             */
/*   Updated: 2019/02/23 18:36:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct	s_dif
{
	long			dx;
	long			dy;
	long			x_max;
	long			y_max;
	long			x_min;
	long			y_min;
}				t_dif;

typedef struct	s_point
{
	long		x;
	long		y;
	long		z;
}				t_point;

typedef struct	s_math
{
	t_dif		dif;
	int			zoom;
	int			depth;
	int			x_move;
	int			y_move;
	double		x_rot;
	double		y_rot;
	int			bol_center;
	int			bol_scale;
}				t_math;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			data_size;
	int			size_l;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_point		***pts;
	t_point		***ori;
	t_math		math;
}				t_mlx;

#endif
