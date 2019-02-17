/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/17 19:15:20 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SCALE 50

static int	pexit(int exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}

static int	map_len_x(t_list *begin)
{
	static int len = 0;
	
	if (len == 0)
		len = ((t_point *)begin->content)->x;
	return (len);
}

static int	map_len_y(t_list *begin)
{
	static int len = 0;
	
	if (len == 0)
		len = ((t_point *)begin->content)->y;
	return (len);
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

static void bresenham(t_img *img, t_point pt1, t_point pt2)
{
	int		ex;
	int		ey;
	int		dx;
	int		dy;
	int		dex;
	int		dey;
	int		xincr;
	int		yincr;
	int		i;

	ex = abs(pt2.x - pt1.x);
	ey = abs(pt2.y - pt1.y);
	dx = 2 * ex;
	dy = 2 * ey;
	dex = ex;
	dey = ey;
	xincr = 1;
	yincr = 1;
	i = 0;
	if (pt1.x > pt2.x)
		xincr = -1;
	if (pt1.y  > pt2.y)
		yincr = -1;
	if (dex > dey)
	{
		while (i <= dex)
		{
			image_pixel_put(img, pt1.x, pt1.y, (pt1.z > 0 && pt2.z > 0 ? 0x00FF00 : 0x0000DD));
			++i;
			pt1.x += xincr;
			ex -= dy;
			if (ex < 0)
			{
				pt1.y += yincr;
				ex += dx;
			}
		}
	}
	else if (dex < dey)
	{
		while (i <= dey)
		{
			image_pixel_put(img, pt1.x, pt1.y, (pt1.z > 0 && pt2.z > 0 ? 0x00FF00 : 0x0000DD));
			++i;
			pt1.y += yincr;
			ey -= dx;
			if (ey < 0)
			{
				pt1.x += xincr;
				ey += dy;
			}
		}
	}
}

static void	fill_image(t_list *begin, t_img *img)
{
	int		i;
	int		lim_x;
	t_list	*next_bottom_elem;

	i = 0;
	lim_x= 1 + map_len_x(begin) / SCALE;
	while (begin)
	{
		if (begin->next && (i % lim_x) != lim_x - 1)
			bresenham(img, (*(t_point *)begin->content), (*(t_point *)begin->next->content));
		if ((next_bottom_elem = ft_lstnelem(begin, lim_x + 1)))
			bresenham(img, (*(t_point *)begin->content), (*(t_point *)next_bottom_elem->content));
		image_pixel_put(img, ((t_point *)begin->content)->x, ((t_point *)begin->content)->y, (((t_point *)begin->content)->z > 0 ? 0xFFFFFF :  0xFF0000));
		++i;
		begin = begin->next;
	}
}

static void	centerise(t_list *begin)
{
	while (begin)
	{
		((t_point *)begin->content)->x += W_WIDTH / 2 - map_len_x(begin) / 2;
		((t_point *)begin->content)->y +=  + W_HEIGHT / 2 - map_len_y(begin) / 2;
		begin = begin->next;
	}
}

static int	task_manager(t_list *begin)
{
	t_mlx	mlx;

	init(&mlx);
	apply_scale_on_lst(begin, SCALE);
	map_len_y(begin);
	centerise(begin);
	fill_image(begin, &mlx.img);
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
