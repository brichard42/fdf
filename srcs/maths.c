/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:42:17 by evogel            #+#    #+#             */
/*   Updated: 2019/02/26 17:19:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_dx_dy(t_point ***pts, t_math *math)
{
	int i;
	int j;

	math->dif.x_max = pts[0][0]->x;
	math->dif.x_min = pts[0][0]->x;
	math->dif.y_max = pts[0][0]->y;
	math->dif.y_min = pts[0][0]->y;
	i = 0;
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
			if (pts[i][j]->x > math->dif.x_max)
				math->dif.x_max = pts[i][j]->x;
			if (pts[i][j]->x < math->dif.x_min)
				math->dif.x_min = pts[i][j]->x;
			if (pts[i][j]->y > math->dif.y_max)
				math->dif.y_max = pts[i][j]->y;
			if (pts[i][j]->y < math->dif.y_min)
				math->dif.y_min = pts[i][j]->y;
			j++;
		}
		i++;
	}
	math->dif.dx = ((math->dif.x_max - math->dif.x_min) == 0 ? 1 : (math->dif.x_max - math->dif.x_min));
	math->dif.dy = ((math->dif.y_max - math->dif.y_min) == 0 ? 1 : (math->dif.y_max - math->dif.y_min));
}

void		scale_view(t_point ***pts, t_math *math)
{
	static int prev = 0;
	int	i;
	int	j;

	get_dx_dy(pts, math);
	if ((W_WIDTH / math->dif.dx) < (W_HEIGHT / math->dif.dy))
		math->zoom = ((W_WIDTH - 40) / math->dif.dx);
	else
		math->zoom = ((W_HEIGHT - 40) / math->dif.dy);
	if (math->zoom == prev)
		return ;
	i = 0;
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
			pts[i][j]->x *= math->zoom;
			pts[i][j]->y *= math->zoom;
			j++;
		}
		i++;
	}
	prev = math->zoom;
}

void		center_view(t_point ***pts, t_math *math)
{
	int	i;
	int	j;

	get_dx_dy(pts, math);
	math->x_move = (W_WIDTH - math->dif.dx) / 2 - math->dif.x_min;
	math->y_move = (W_HEIGHT - math->dif.dy) / 2 - math->dif.y_min;
	i = 0;
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
			//move x
			pts[i][j]->x += math->x_move;
			//move y
			pts[i][j]->y += math->y_move;
			j++;
		}
		i++;
	}
}

void		init_view(t_point ***pts, t_math *math)
{
	(void)pts;//a degager
	math->depth = 2;
	math->zoom = 1;
	math->bol_rot = 0;
	math->bol_center = 1;
	math->bol_scale = 5;
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

void		do_maths(t_point ***pts, t_math *math)
{
	int i;
	int j;

	i = 0;
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
//			if (math->bol_scale == 0)//zoom
//			{
				pts[i][j]->x *= math->zoom;
				pts[i][j]->y *= math->zoom;
//			}
			//depth
			pts[i][j]->z *= math->depth;
			//rotate
			if (math->bol_rot == 1)
				rotation(pts[i][j], math->x_rot, math->y_rot);
			//move x
			if (math->bol_center == 0)
				pts[i][j]->x += math->x_move;
			//move y
			if (math->bol_center == 0)
				pts[i][j]->y += math->y_move;
			j++;
		}
		i++;
	}
	if (math->bol_scale == 1)
		scale_view(pts, math);
	if (math->bol_center == 1)
		center_view(pts, math);
}
