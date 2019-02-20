/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 17:17:13 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int		treat_img - act on the char* data

mlx_hook - localised in .h
optimise bresenham - pas de calculs pour pts en dehors de l'img
*/

static int	task_manager(int **file)
{
	t_mlx	env;

	(void)file;
	init_window(&env);
	init_img(&env, W_WIDTH, W_HEIGHT);
	mlx_loop(env.mlx_ptr);
	return (0);
}

int			main(int ac, char **av)
{
	int		**file;

	if (ac != 2)
		return (0);
	if (!(file = fdf_parsing(av[1])))
		pexit(E_FDF_PARSING);
	task_manager(file);
	return (0);
}
