/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 12:26:13 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "fdf_errors.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "fdf_structs.h"

# define W_HEIGHT 1080
# define W_WIDTH 1920

/*
**	treat_img.c.C
*/

void	fdf_get_scale(t_file *file);
void	treat_img(t_file *file, t_mlx *env);
void	bresenham(t_img *img, t_point pt1, t_point pt2);

/*
**	image_pixel_put.c
*/

int		image_pixel_put(t_img *img, int x, int y, int colour);

/*
**	fdf_parsing.c
*/

int		fdf_parsing(char *av, t_file *file);

/*
**	fdf_init.c
*/

void	init_img(t_mlx *env, int width, int height);
void	init_window(t_mlx *env);

/*
**	fdf_utils.c
*/

int		pexit(int exit_value);

#endif
