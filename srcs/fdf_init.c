/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:44:37 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 14:29:46 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_mlx *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		pexit(E_MLX_INIT);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH,
											W_HEIGHT, "WindowToMyKokoro")))
		pexit(E_MLX_NEW_WINDOW);
}

int		init_img(t_mlx *env, int width, int height)
{
	int		bpp;
	int		endian;

	if (!(env->img.img_ptr = mlx_new_image(env->mlx_ptr, width, height)))
		pexit(5);
	if (!(data = (int *)mlx_get_data_addr(env->img.img_ptr, &bpp, &(env->img.size_l), &endian)))
		pexit(6);
}
