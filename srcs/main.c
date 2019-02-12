/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/12 16:40:17 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(unsigned char *rgb)
{
	return (rgb[1] * 65536 + rgb[2] * 256 + rgb[3]);
}

int		pexit(int	exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}

int		main(void)
{
	t_mlx	mlx;

	if (!(mlx.mlx_ptr = mlx_init()))
		pexit(E_MLX_INIT);
	if (!(mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "MyWindow")))
		pexit(E_MLX_NEW_WINDOW);
	if (!(mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, W_WIDTH, W_HEIGHT)))
		pexit(E_MLX_NEW_IMAGE);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
