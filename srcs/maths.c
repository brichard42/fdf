/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:42:17 by evogel            #+#    #+#             */
/*   Updated: 2019/02/22 22:16:33 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_dx_dy(t_file *file)
{
	int i;
	int j;

	file->dif.x_max = file->pts[0][0]->x;
	file->dif.x_min = file->pts[0][0]->x;
	file->dif.y_max = file->pts[0][0]->y;
	file->dif.y_min = file->pts[0][0]->y;
	i = 0;
	while (file->pts[i])
	{
		j = 0;
		while (file->pts[i][j])
		{
			if (file->pts[i][j]->x > file->dif.x_max)
				file->dif.x_max = file->pts[i][j]->x;
			if (file->pts[i][j]->x < file->dif.x_min)
				file->dif.x_min = file->pts[i][j]->x;
			if (file->pts[i][j]->y > file->dif.y_max)
				file->dif.y_max = file->pts[i][j]->y;
			if (file->pts[i][j]->y < file->dif.y_min)
				file->dif.y_min = file->pts[i][j]->y;
			j++;
		}
		i++;
	}
	file->dif.dx = ((file->dif.x_max - file->dif.x_min) == 0 ? 1 : (file->dif.x_max - file->dif.x_min));
	file->dif.dy = ((file->dif.y_max - file->dif.y_min) == 0 ? 1 : (file->dif.y_max - file->dif.y_min));
}

void		scale_view(t_file *file)
{
	get_dx_dy(file);
	if ((W_WIDTH / file->dif.dx) < (W_HEIGHT / file->dif.dy))
		file->zoom = (W_WIDTH / file->dif.dx);
	else
		file->zoom = (W_HEIGHT / file->dif.dy);
	do_maths(file, "z");
}

void		center_view(t_file *file)
{
	get_dx_dy(file);
	file->x_move = (W_WIDTH - file->dif.dx) / 2 - file->dif.x_min;
	file->y_move = (W_HEIGHT - file->dif.dy) / 2 - file->dif.y_min;
	do_maths(file, "mxy");
}

void		init_view(t_file *file)
{
	scale_view(file);
	center_view(file);
	file->depth = 8;
	file->x_rot = 0.523599;
	file->y_rot = 0.523599;
}

void		rotation(t_point *pt, double x_rot, double y_rot)
{
	int previous_x;
	int previous_y;

	previous_x = pt->x;
	previous_y = pt->y;
	pt->x = (previous_x - previous_y) * cos(x_rot);
	pt->y = -(pt->z) + (previous_x + previous_y) * sin(y_rot);
}

void		do_maths(t_file *file, char *str)
{
	int i;
	int j;

	i = 0;
	while (file->pts[i])
	{
		j = 0;
		while (file->pts[i][j])
		{
			//rotate
			if (ft_strchr(str, 'r'))
				rotation(file->pts[i][j], file->x_rot, file->y_rot);
			//zoom
			if (ft_strchr(str, 'z'))
			{
				file->pts[i][j]->x *= file->zoom;
				file->pts[i][j]->y *= file->zoom;
			}
			//depth
			if (ft_strchr(str, 'd'))
				file->pts[i][j]->z *= file->depth;
			//move
			if (ft_strchr(str, 'm') && ft_strchr(str, 'x'))
				file->pts[i][j]->x += file->x_move;
			if (ft_strchr(str, 'm') && ft_strchr(str, 'y'))
				file->pts[i][j]->y += file->y_move;
			j++;
		}
		i++;
	}
}
