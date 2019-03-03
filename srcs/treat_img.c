/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:37:02 by evogel            #+#    #+#             */
/*   Updated: 2019/03/03 16:35:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_window(t_point pt)
{
	if ((pt.x < 0 || pt.x > W_WIDTH) && (pt.y < 0 || pt.y > W_HEIGHT))
		return (0);
	return (1);
}

static void	fdf_strings(t_mlx *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 0, WHITE, CONTROLS);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 15, WHITE, S_UP);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 30, WHITE, S_DOWN);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 45, WHITE, S_LEFT);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 60, WHITE, S_RIGHT);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 75, WHITE, S_ZOOM_IN);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 90, WHITE, S_ZOOM_OUT);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 105, WHITE, S_INC_H);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 120, WHITE, S_DEC_H);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 135, WHITE, S_CHANGE_V);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 150, WHITE, S_CENTER_V);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 165, WHITE, S_RESET_V);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 180, WHITE, S_EXIT);
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
			if (env->pts[i][j + 1] && in_window(*env->pts[i][j]) \
					&& in_window(*env->pts[i][j + 1]))
				bresenham(&env->img, *env->pts[i][j], *env->pts[i][j + 1]);
			if (env->pts[i + 1] && in_window(*env->pts[i][j]) \
					&& in_window(*env->pts[i + 1][j]))
				bresenham(&env->img, *env->pts[i][j], *env->pts[i + 1][j]);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	fdf_strings(env);
}
