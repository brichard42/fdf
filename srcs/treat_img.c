/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:37:02 by evogel            #+#    #+#             */
/*   Updated: 2019/02/20 22:18:00 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_get_scale(t_file *file)
{
	file->scale = (W_WIDTH > W_HEIGHT ? W_HEIGHT : W_WIDTH) 
					/ (file->x_len > file->y_len ? file->x_len : file->y_len);
	int i = 0;
	while (file->tab[i])
	{
		int j = 0;
		while (j < file->x_len)
		{
			file->pts[i][j].x = j * file->scale;
			file->pts[i][j].y = i * file->scale;
			file->pts[i][j].z = file->tab[i][j] * file->scale;
			++j;
		}
		++i;
	}
}

void	treat_img(t_file file, t_mlx *env)
{
	int i;
	int j;

	i = 0;
	while (i < file.y_len)
	{
		j = 0;
		while (j < file.x_len)
		{
			if (!(j + 1 > file.x_len))
				bresenham(&env->img, file.pts[i][j], file.pts[i][j + 1]);
			if (!(i + 1 > file.y_len))
				bresenham(&env->img, file.pts[i][j], file.pts[i + 1][j]);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window((char *)env->img.data, env->win_ptr, env->img.img_ptr, 0, 0);
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
