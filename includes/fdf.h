/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 17:17:08 by brichard         ###   ########.fr       */
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

# define W_HEIGHT 900
# define W_WIDTH 1600

/*
**	IMAGE_PIXEL_PUT.C
*/

int		image_pixel_put(t_img *img, int x, int y, int colour);

/*
**	fdf_parsing.c
*/

int		**fdf_parsing(char *av);

/*
**	fdf_JESAISPAS.c
*/

void	apply_scale_on_lst(t_list *lst, int scale);

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
