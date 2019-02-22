/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:12:31 by brichard          #+#    #+#             */
/*   Updated: 2019/02/22 14:46:14 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_file
{
	t_point		***pts;
	int			x_len;
	int			y_len;
	int			scale;
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
