/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:44:37 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 16:58:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_mlx *env)
{
	int		bpp;
	int		endian;
	int		size_l;

	if (!(env->mlx_ptr = mlx_init()))
		exit(2);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH,
											W_HEIGHT, "WindowToMyKokoro")))
		exit(3);
	if (!(env->img.img_ptr = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT)))
		exit(4);
	if (!(env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, \
													&bpp, &size_l, &endian)))
		exit(5);
}

void	init_view(t_math *math)
{
	math->bol_rot = 0;
	math->bol_center = 1;
	math->bol_scale = 1;
}

void	init_dif(t_point ***pts, t_math *math)
{
	math->dif.x_max = pts[0][0]->x;
	math->dif.x_min = pts[0][0]->x;
	math->dif.y_max = pts[0][0]->y;
	math->dif.y_min = pts[0][0]->y;
}
