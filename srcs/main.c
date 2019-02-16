/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 20:39:05 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SCALE 10

static int	pexit(int exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}

static void	init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		pexit(E_MLX_INIT);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH,
											W_HEIGHT, "MyWindow")))
		pexit(E_MLX_NEW_WINDOW);
	mlx->img.data_size = W_WIDTH * W_HEIGHT * 4;
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT)))
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		pexit(E_MLX_NEW_IMAGE);
	}
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
									&mlx->img.size_l, &mlx->img.endian);
}

static void link_points(t_list *begin, t_mlx *mlx)
{
	int		len_x;
	int		len_y;

	len_x = ((t_point *)begin->content)->x;
	len_y = ((t_point *)begin->content)->y;
	while (begin) // MAUVAIS CALCULS
	{
		ft_printf("NOTINLOOP | y = {%d} x = {%d} next->x = {%d}\n", ((t_point *)begin->content)->y, ((t_point *)begin->content)->x, ((t_point *)begin->next->content)->x);
		while (begin->next && ((t_point *)begin->content)->x++ < ((t_point *)begin->next->content)->x)
		{
			ft_printf("INLOOP | y = {%d}\n", ((t_point *)begin->content)->y);
			image_pixel_put(&mlx->img, ((t_point *)begin->content)->x + W_WIDTH / 2 - len_x / 2, ((t_point *)begin->content)->y + W_HEIGHT / 2 - len_y / 2, (((t_point *)begin->content)->z > 0 ? 0x00FF00 :  0xFF00FF));
		}
		begin = begin->next;
	}
}

static int	task_manager(t_list *begin)
{
	t_mlx	mlx;
	int		len_x;
	int		len_y;

	init(&mlx);
	apply_scale_on_lst(begin, SCALE);
	len_x = ((t_point *)begin->content)->x;
	len_y = ((t_point *)begin->content)->y;
	link_points(begin, &mlx);
	while (begin)
	{
		image_pixel_put(&mlx.img, ((t_point *)begin->content)->x + W_WIDTH / 2 - len_x / 2, ((t_point *)begin->content)->y + W_HEIGHT / 2 - len_y / 2, (((t_point *)begin->content)->z > 0 ? 0x00FF00 :  0xFF00FF));
		begin = begin->next;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	return (0);
}

int			main(int ac, char **av)
{
	t_list	*begin;

	begin = NULL;
	if (ac != 2)
		return (0);
	if (fdf_parsing(av[1], &begin) == -1)
		pexit(E_FDF_PARSING);
	task_manager(begin);
	return (0);
}
