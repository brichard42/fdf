/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/11 17:42:45 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define RGB_SIZE 4
#define W_HIGH 900
#define W_WIDTH 1600

int		color(unsigned char *rgb)
{
	return (rgb[1] * 65536 + rgb[2] * 256 + rgb[3]);
}

int		main(void)
{
	unsigned char	rgb[RGB_SIZE];
	void			*mlx_ptr;
	void			*win_ptr;
	int				i;

	ft_bzero((void*)rgb, RGB_SIZE);
	rgb[1] = 255;
	if (!(mlx_ptr = mlx_init()))
	{
		perror(strerror(errno));
		exit(2);
	}
	if (!(win_ptr = mlx_new_window(mlx_ptr, W_WIDTH, W_HIGH, "MyWindow")))
	{
		perror(strerror(errno));
		exit(3);
	}
	i = 0;
	while (i < 200 && rgb[1]-- != 0 && rgb[2]++ != 255)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 800, 350 + i, color(rgb));
		mlx_pixel_put(mlx_ptr, win_ptr, 700 + i, 450, color(rgb));
		i++;
	}
	mlx_loop(mlx_ptr);
	i = 0;
	while (i < 200 && rgb[1]++ && rgb[2]--)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, W_WIDTH / 2, (W_HIGH / 2 - 100) + i, color(rgb));
		mlx_pixel_put(mlx_ptr, win_ptr, (W_WIDTH / 2 - 100) + i, W_HIGH, color(rgb));
		i++;
	}
	return (0);
}
