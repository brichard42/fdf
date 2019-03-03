/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 12:33:22 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "fdf_errors.h"
# include "fdf_colors.h"
# include "fdf_structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define W_HEIGHT 1080
# define W_WIDTH 1920
# define KEY_Z /*6*/122
# define KEY_E /*14*/101
# define KEY_R /*15*/114
# define KEY_I /*34*/105
# define KEY_P /*35*/112
# define KEY_UP /*126*/65362
# define KEY_DOWN /*125*/65364
# define KEY_LEFT /*123*/65361
# define KEY_RIGHT /*124*/65363
# define KEY_ESC /*53*/65307
# define KEY_PLUS /*69*/65451
# define KEY_MINUS /*78*/65453

# define CONTROLS		"            CONTROLS"
# define S_UP			"     Move Up    |     ^"
# define S_DOWN			"    Move Down   |     v"
# define S_LEFT			"    Move Left   |     <"
# define S_RIGHT		"   Move Right   |     >"
# define S_ZOOM_IN		"    Zoom In     |     z"
# define S_ZOOM_OUT		"    Zoom Out    |     e"
# define S_INC_H		"Increase Height |     +"
# define S_DEC_H		"Decrease Height |     -"
# define S_CHANGE_V		"   Change View  |     i"
# define S_CENTER_V		"   Center View  |     p"
# define S_RESET_V		"   Reset  View  |     r"
# define S_EXIT			"  Exit Program  |     esc"

/*
**	treat_img.c.C
*/

void			do_maths(t_point ***pts, t_math *math);
void			treat_img(t_mlx *env);
void			bresenham(t_img *img, t_point pt1, t_point pt2);
void			scale_view(t_point ***pts, t_math *math);
void			center_view(t_point ***pts, t_math *math);

/*
**	image_pixel_put.c
*/

int				image_pixel_put(t_img *img, t_point *pt, int colour);

/*
**	fdf_parsing.c
*/

int				fdf_parsing(char *av, t_mlx *env);

/*
**	fdf_init.c
*/

void			fdf_init(t_mlx *env);
void			init_view(t_math *math);

/*
**	fdf_utils.c
*/

int				pexit(int exit_value);
void			ft_tpointcpy(t_point ***dst, t_point ***src);
void			ft_free_tab(void **cont, int size);

/*
**	ft_*.c
*/

t_point			*ft_t_pointnew(long x, long y, long z);
int				ft_abs(int a);

/*
**	key_fun.c
*/

void			move_left(t_math *math);
void			move_right(t_math *math);
void			move_down(t_math *math);
void			move_up(t_math *math);
void			move_center(t_math *math);

/*
**	key_fun_2.c
*/

void			zoom_in(t_math *math);
void			zoom_out(t_math *math);
void			depth_inc(t_math *math);
void			depth_dec(t_math *math);
void			center_scale(t_math *math);

/*
**	key_fun_3.c
*/

void			switch_iso(t_math *math);

/*
**	fdf_colors.c
*/

int				pick_color(double z);

/*
**	EVENT DEFINITIONS
*/

/*
**	Input Event Masks. Used as event-mask window attribute and as arguments
**	to Grab requests.  Not to be confused with event names.
*/

# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)

/*
**	Event names.  Used in "type" field in XEvent structures.  Not to be
**	confused with event masks above.  They start from 2 because 0 and 1
**	are reserved in the protocol for errors and replies.
*/

# define KEYPRESS				2
# define KEYRELEASE				3
# define DESTROYNOTIFY			17

#endif
