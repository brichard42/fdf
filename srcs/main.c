/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 12:01:21 by brichard         ###   ########.fr       */
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

	(void)file;
	init_window(&env);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

int			main(int ac, char **av)
{
	int		**file;

	file = NULL;
	if (ac != 2)
		return (0);
	if ((fdf_parsing(av[1], &file)) == -1)
		pexit(E_FDF_PARSING);
	task_manager(file);
	return (0);
}
