/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:44:37 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 18:04:00 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_get_scale(t_file *file)
{
	int i;
	int j;

	while (file->pts[i])
		i++;
	while (file->(*pts)[j])
		j++;
	if (W_WIDTH - j > W_HEIGHT - i)
		file->scale = (int)(W_WIDTH / j);
	else
		file->scale = (int)(W_HEIGHT / i);
}

void	init_window(t_mlx *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		pexit(E_MLX_INIT);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH,
											W_HEIGHT, "WindowToMyKokoro")))
		pexit(E_MLX_NEW_WINDOW);
}

void	init_img(t_mlx *env, int width, int height)
{
	int		bpp;
	int		endian;

	if (!(env->img.img_ptr = mlx_new_image(env->mlx_ptr, width, height)))
		pexit(5);
	if (!(env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, &bpp, &(env->img.size_l), &endian)))
		pexit(6);
}
