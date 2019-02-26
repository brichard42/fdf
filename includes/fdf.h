/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/02/26 14:23:47 by brichard         ###   ########.fr       */
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

# define W_HEIGHT 720
# define W_WIDTH 1080

/*
**	treat_img.c.C
*/

void	do_maths(t_point ***pts, t_math *math);
void	treat_img(t_mlx *env);
void	bresenham(t_img *img, t_point pt1, t_point pt2);
void	scale_view(t_point ***pts, t_math *math);
void	center_view(t_point ***pts, t_math *math);

/*
**	image_pixel_put.c
*/

int		image_pixel_put(t_img *img, int x, int y, int colour);

/*
**	fdf_parsing.c
*/

int		fdf_parsing(char *av, t_mlx *env);

/*
**	fdf_init.c
*/

void	fdf_init(t_mlx *env);
void	init_view(t_point ***pts, t_math *math);

/*
**	fdf_utils.c
*/

int		pexit(int exit_value);
void	ft_tpointcpy(t_point ***dst, t_point ***src);
void	put_tpoint(t_point ***pts);//to delete before push

/*
**	ft_*.c
*/

t_point		*ft_t_pointnew(long x, long y, long z);
int			ft_abs(int a);

/*
**	EVENT DEFINITIONS
*/

/*
**	Input Event Masks. Used as event-mask window attribute and as arguments
**	to Grab requests.  Not to be confused with event names.
*/

# define NoEventMask				0L
# define KeyPressMask				(1L<<0)
# define KeyReleaseMask				(1L<<1)
# define ButtonPressMask			(1L<<2)
# define ButtonReleaseMask			(1L<<3)
# define EnterWindowMask			(1L<<4)
# define LeaveWindowMask			(1L<<5)  
# define PointerMotionMask			(1L<<6)  
# define PointerMotionHintMask		(1L<<7)  
# define Button1MotionMask			(1L<<8)  
# define Button2MotionMask			(1L<<9)  
# define Button3MotionMask			(1L<<10) 
# define Button4MotionMask			(1L<<11) 
# define Button5MotionMask			(1L<<12) 
# define ButtonMotionMask			(1L<<13) 

/*
**	Event names.  Used in "type" field in XEvent structures.  Not to be
**	confused with event masks above.  They start from 2 because 0 and 1
**	are reserved in the protocol for errors and replies.
*/

# define KeyPress				2
# define KeyRelease				3
# define ButtonPress			4
# define ButtonRelease			5
# define MotionNotify			6
# define EnterNotify			7
# define LeaveNotify			8
# define FocusIn				9
# define FocusOut				10
# define KeymapNotify			11
# define Expose					12
# define GraphicsExpose			13
# define NoExpose				14
# define VisibilityNotify		15
# define CreateNotify			16
# define DestroyNotify			17
# define UnmapNotify			18
# define MapNotify				19
# define MapRequest				20
# define ReparentNotify			21
# define ConfigureNotify		22
# define ConfigureRequest		23
# define GravityNotify			24
# define ResizeRequest			25
# define CirculateNotify		26
# define CirculateRequest		27
# define PropertyNotify			28
# define SelectionClear			29
# define SelectionRequest		30
# define SelectionNotify		31
# define ColormapNotify			32
# define ClientMessage			33
# define MappingNotify			34
# define LASTEvent				35

#endif
