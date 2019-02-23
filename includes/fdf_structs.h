/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:12:31 by brichard          #+#    #+#             */
/*   Updated: 2019/02/22 22:27:58 by evogel           ###   ########.fr       */
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

typedef struct	s_file
{
	t_point		***pts;
	int			x_len;
	int			y_len;
	t_dif		dif;
	double		zoom;
	int			depth;
	int			x_move;
	int			y_move;
	double		x_rot;
	double		y_rot;
}				t_file;

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
	t_file		file;
}				t_mlx;

#endif
