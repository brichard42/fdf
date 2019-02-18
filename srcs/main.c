/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:10:24 by brichard          #+#    #+#             */
/*   Updated: 2019/02/18 18:07:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	pexit(int exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}

static void	init_window(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		pexit(E_MLX_INIT);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH,
											W_HEIGHT, "MyWindow")))
		pexit(E_MLX_NEW_WINDOW);
}

static int	task_manager(char **file)
{
	t_mlx	mlx;

	(void)file;
	init_window(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

int			main(int ac, char **av)
{
	int		**file;

	file = NULL;
	if (ac != 2)
		return (0);
	if ((fdf_parsing(av[1], file)) == -1)
		pexit(E_FDF_PARSING);
	task_manager(file);
	return (0);
}
