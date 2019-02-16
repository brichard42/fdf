/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:25:21 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 16:04:23 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_STRUCTS_H
# define GRAPH_STRUCTS_H

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

#endif
