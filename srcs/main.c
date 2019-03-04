/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/03/04 11:02:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_close(void *param)
{
	t_mlx	*env;
	int		i;

	env = (t_mlx *)param;
	i = 0;
	while (env->pts[i])
		++i;
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
	return (0);
}

static int	do_key_rel(int keycode, void *param)
{
	t_mlx	*env;
	int		i;

	env = (t_mlx *)param;
	if (keycode == KEY_ESC)
	{
		i = 0;
		while (env->pts[i])
			++i;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0);
	}
	return (0);
}

static int	do_key_press(int keycode, void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	ft_tpointcpy(env->pts, env->ori);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	ft_bzero(env->img.data, W_HEIGHT * W_WIDTH * 4);
	if (keycode >= 0 && keycode <= KEY_TAB && env->key_tab[keycode])
		env->key_tab[keycode](&env->math);
	do_maths(env->pts, &env->math);
	treat_img(env);
	env->math.bol_center = 0;
	env->math.bol_scale = 0;
	return (0);
}

static void	init_tab(t_keyfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
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
		exit(1);
	fdf_init(&env);
	init_tab(env.key_tab, KEY_TAB);
	init_view(&env.math);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, do_key_press, (void *)&env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, do_key_rel, (void *)&env);
	mlx_hook(env.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, \
							fdf_close, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
