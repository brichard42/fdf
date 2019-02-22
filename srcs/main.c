/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/22 15:02:03 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
parsing - FICHIER = CARRER OU RECTANGLE SINON INVALIDE

int		treat_img - act on the char* data


mlx_hook - localised in .h
optimise bresenham - pas s en dehors de l'img
*/

int			do_key_release(int keycode, void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		//++++++ FREE LES TRUCS PLEASE ++++++//
		exit (0);
	}
	return (0);
}

int			do_key(int keycode, void *param)
{
	t_mlx	*env;

	(void)keycode;
	env = (t_mlx *)param;
	ft_bzero(env->img.data, W_WIDTH * W_HEIGHT * 4);
	fdf_get_scale(&env->file);//++++++END OF INIT++++++//
	treat_img(&env->file, env);//+++++SHOULD BE CALLED AFTER ANY KIND OF CHANGES, I.E SCALE..VUE..ETC.+++++//
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	env;

	if (ac != 2)
		return (0);
	if ((fdf_parsing(av[1], &env.file)) == -1)
		pexit(E_FDF_PARSING);
	fdf_init(&env, W_WIDTH, W_HEIGHT);
	mlx_hook(env.win_ptr, KeyPress, KeyPressMask, do_key, (void *)&env);
	mlx_hook(env.win_ptr, KeyRelease, KeyReleaseMask, do_key_release, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
