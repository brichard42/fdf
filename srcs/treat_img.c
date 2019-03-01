/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:37:02 by evogel            #+#    #+#             */
/*   Updated: 2019/03/01 17:54:22 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_window(t_point pt)
{
	if ((pt.x < 0 || pt.x > W_WIDTH) && (pt.y < 0 || pt.y > W_HEIGHT))
		return (0);
	return (1);
}

void		treat_img(t_mlx *env)
{
	int i;
	int j;

	i = 0;
	while (env->pts[i])
	{
		j = 0;
		while (env->pts[i][j])
		{
			if (env->pts[i][j + 1] && in_window(*env->pts[i][j]) && in_window(*env->pts[i][j + 1]))
				bresenham(&env->img, *env->pts[i][j], *env->pts[i][j + 1]);
			if (env->pts[i + 1] && in_window(*env->pts[i][j]) && in_window(*env->pts[i + 1][j]))
				bresenham(&env->img, *env->pts[i][j], *env->pts[i + 1][j]);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}

void		bresenham(t_img *img, t_point pt1, t_point pt2)
{
	double	ex;
	double	ey;
	double	dx;
	double	dy;
	double	dex;
	double	dey;
	double	xincr;
	double	yincr;
	double	i;
	t_point	tmp;

	tmp = pt1;
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
	if (dex >= dey)
	{
		while (i <= dex)
		{
			image_pixel_put(img, pt1.x, pt1.y, pick_color(pt1.z));
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
			image_pixel_put(img, pt1.x, pt1.y, pick_color(pt1.z));
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
