/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 16:06:25 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pexit(int exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}

/*
int		init_window - creates win
int		init_img - creates img (put in t_img)
int		treat_img - act on the char* data

mlx_hook - localised in .h
optimise bresenham - pas de calculs pour pts en dehors de l'img
*/

static int	task_manager(int **file)
{
	t_mlx	env;

	init_window(&env);
	init_img(&env, W_WIDTH, W_HEIGHT);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
#include <stdio.h>
int			main(int ac, char **av)
{
	int		**file;

	if (ac != 2)
		return (0);
	if (!(file = fdf_parsing(av[1])))
		pexit(E_FDF_PARSING);
	int i = 0;
	while (file[i])
	{
		int j = 0;
		while (j < 6)
		{
			printf("jean[%d][%d] = {%d}\n", i, j, file[i][j]);
			++j;
		}
		++i;
	}
	task_manager(file);
	return (0);
}
