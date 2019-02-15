/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/15 22:41:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pexit(int	exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}
int		main(int ac, char **av)
{
	t_mlx	mlx;
	int i;

	i = 0;
	if (!(mlx.mlx_ptr = mlx_init()))
		pexit(E_MLX_INIT);
	if (!(mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "MyWindow")))
		pexit(E_MLX_NEW_WINDOW);
	if (!(mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, W_WIDTH, W_HEIGHT)))
	{
		mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
		pexit(E_MLX_NEW_IMAGE);
	}
	mlx.img.data = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	while (i < 200)
	{
		image_pixel_put(&mlx.img, 700 + i, 450, 0xFF00FF);
		i++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	get_file(ac, av);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	return (0);
}
