/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/28 17:58:01 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define KEY_A 0//97
# define KEY_Z 6//122
# define KEY_E 14//101
# define KEY_R 15//114
# define KEY_I 34//105
# define KEY_P 35//112
# define KEY_UP 126//65364
# define KEY_DOWN 125//65362
# define KEY_LEFT 123//65361
# define KEY_RIGHT 124//65363
# define KEY_ESC 53//65307
# define KEY_PLUS 69//65451
# define KEY_MINUS 78//65453

/*
fix center_scale PLEASE
recheck leaks
color swap
*/

int			do_key_release(int keycode, void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	if (keycode == KEY_ESC)
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

	env = (t_mlx *)param;
	ft_tpointcpy(env->pts, env->ori);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	ft_bzero(env->img.data, W_HEIGHT * env->img.size_l);
	if (keycode >= 0 && keycode <= 130 && env->key_tab[keycode])
		env->key_tab[keycode](&env->math);
	do_maths(env->pts, &env->math);
	treat_img(env);//+++++SHOULD BE CALLED AFTER ANY KIND OF CHANGES, I.E SCALE..VUE..ETC.+++++//
	env->math.bol_center = 0;
	env->math.bol_scale = 0;
	return (0);
}

int			fdf_close(void *param)
{
	//free param!!
	(void)param;
	exit(0);
	return (0);
}

void		ft_bzero_tab(t_keyfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
}

void		init_tab(t_keyfunc *tab, int size)
{
	ft_bzero_tab(tab, size);
	tab[KEY_LEFT] = move_left;
	tab[KEY_RIGHT] = move_right;
	tab[KEY_DOWN] = move_down;
	tab[KEY_UP] = move_up;
	tab[KEY_Z] = zoom_in;
	tab[KEY_E] = zoom_out;
	tab[KEY_P] = move_center;
	tab[KEY_PLUS] = depth_inc;
	tab[KEY_MINUS] = depth_dec;
	tab[KEY_I] = switch_iso;
	tab[KEY_R] = center_scale;
}

int			main(int ac, char **av)
{
	t_mlx		env;

	if (ac != 2)
		return (0);
	env.pts = NULL;
	if ((fdf_parsing(av[1], &env)) == -1)
		exit(E_FDF_PARSING);
	fdf_init(&env);
	init_tab(env.key_tab, 130);
	init_view(env.pts, &env.math);
	mlx_hook(env.win_ptr, KeyPress, KeyPressMask, do_key, (void *)&env);
	mlx_hook(env.win_ptr, KeyRelease, KeyReleaseMask, do_key_release, (void *)&env);
	mlx_hook(env.win_ptr, DestroyNotify, KeyPressMask, fdf_close, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
