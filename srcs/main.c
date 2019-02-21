/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 13:01:20 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int		treat_img - act on the char* data

mlx_hook - localised in .h
optimise bresenham - pas s en dehors de l'img
*/

static int	task_manager(t_file file)
{
	t_mlx	env;

	(void)file;
	init_window(&env);
	init_img(&env, W_WIDTH, W_HEIGHT);
	fdf_get_scale(&file);
	int i = 0;
	while (i < file.y_len)
	{
		int j = 0;
		while (j < file.x_len)
		{
			ft_printf("[%03d ", file.pts[i][j].x);
			ft_printf("%03d ", file.pts[i][j].y);
			ft_printf("%03d]\n", file.pts[i][j].z);
			++j;
		}
		++i;
	}
	treat_img(file, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

int			main(int ac, char **av)
{
	t_file	file;

	if (ac != 2)
		return (0);
	if ((fdf_parsing(av[1], &file)) == -1)
		pexit(E_FDF_PARSING);
	task_manager(file);
	return (0);
}
