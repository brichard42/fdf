/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 12:26:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
parsing - FICHIER = CARRER OU RECTANGLE SINON INVALIDE

int		treat_img - act on the char* data


mlx_hook - localised in .h
optimise bresenham - pas s en dehors de l'img
*/

static int	task_manager(t_file file)
{
	t_mlx	env;

	init_window(&env);
	init_img(&env, W_WIDTH, W_HEIGHT);
	fdf_get_scale(&file);//++++++END OF INIT++++++//
	treat_img(&file, &env);//+++++SHOULD BE CALLED AFTER ANY KIND OF CHANGES, I.E SCALE..VUE..ETC.+++++//
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
