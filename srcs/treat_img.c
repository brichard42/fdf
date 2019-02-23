/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:37:02 by evogel            #+#    #+#             */
/*   Updated: 2019/02/22 21:40:15 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	treat_img(t_file *file, t_mlx *env)
{
	int i;
	int j;

	i = 0;
	while (file->pts[i])
	{
		j = 0;
		while (file->pts[i][j])
		{
			if (file->pts[i][j + 1])
				bresenham(&env->img, *file->pts[i][j], *file->pts[i][j + 1]);
			if (file->pts[i + 1])
				bresenham(&env->img, *file->pts[i][j], *file->pts[i + 1][j]);
			image_pixel_put(&env->img, file->pts[i][j]->x, file->pts[i][j]->y, 0xFFFFFF);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}

void	bresenham(t_img *img, t_point pt1, t_point pt2)
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

	ex = ft_abs(pt2.x - pt1.x);
	ey = ft_abs(pt2.y - pt1.y);
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
			image_pixel_put(img, pt1.x, pt1.y, 0x00FF00/* + (pt1.z * 0xFF0000)*/);
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
			image_pixel_put(img, pt1.x, pt1.y, 0x00FF00/* + (pt1.z * 0xFF0000)*/);
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
