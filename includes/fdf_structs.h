/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:12:31 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 11:41:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# define KEY_TAB /*130*/65453

typedef struct	s_vect
{
	double		x;
	double		y;
}				t_vect;

typedef struct	s_dif
{
	double		dx;
	double		dy;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
}				t_dif;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_math
{
	t_dif		dif;
	double		zoom;
	double		depth;
	double		x_move;
	double		y_move;
	double		x_rot;
	double		y_rot;
	int			bol_center;
	int			bol_scale;
	int			bol_rot;
}				t_math;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
}				t_img;

typedef	void	(*t_keyfunc)(t_math *);

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_point		***pts;
	t_point		***ori;
	t_math		math;
	t_keyfunc	key_tab[KEY_TAB];
}				t_mlx;

#endif
