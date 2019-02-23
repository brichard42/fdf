/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/23 02:15:20 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
parsing - FICHIER = CARRER OU RECTANGLE SINON INVALIDE
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
	ft_bzero(env->img.data, W_HEIGHT * env->img.size_l);
	if (keycode == 123)
	{
		env->file.x_move = -5;
		do_maths(&env->file, "mx");
	}
	if (keycode == 124)
	{
		env->file.x_move = 5;
		do_maths(&env->file, "mx");
	}
	if (keycode == 126)
	{
		env->file.y_move = -5;
		do_maths(&env->file, "my");
	}
	if (keycode == 125)
	{
		env->file.y_move = 5;
		do_maths(&env->file, "my");
	}
	if (keycode == 23/*34*/)
		do_maths(&env->file, "r");
	if (keycode == 116)
	{
		env->file.zoom = 1.01;
		do_maths(&env->file, "z");
	}
	if (keycode == 24/*121*/)
	{
		env->file.zoom = 0.9;
		do_maths(&env->file, "z");
	}
	if (keycode == 49)
	{
		scale_view(&env->file);
		center_view(&env->file);
	}
	treat_img(&env->file, env);//+++++SHOULD BE CALLED AFTER ANY KIND OF CHANGES, I.E SCALE..VUE..ETC.+++++//
	return (0);
}

int			fdf_close(void *param)
{
	//free param!!
	(void)param;
	exit(0);
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
	init_view(&env.file);
	mlx_hook(env.win_ptr, KeyPress, KeyPressMask, do_key, (void *)&env);
	mlx_hook(env.win_ptr, KeyRelease, KeyReleaseMask, do_key_release, (void *)&env);
	mlx_hook(env.win_ptr, DestroyNotify, KeyPressMask, fdf_close, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
