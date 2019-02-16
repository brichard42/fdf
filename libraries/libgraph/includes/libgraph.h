/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:14:26 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 16:20:48 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# include "graph_structs.h"

/*
**	IMAGE_PIXEL_PUT.C
*/

int		image_pixel_put(t_img *img, int x, int y, int colour);

/*
**	GET_COLOUR_BIT.C
*/

int		get_red_bit(int colour);
int		get_green_bit(int colour);
int		get_blue_bit(int colour);

/*
**	SCALE STUFF
*/

void	apply_scale_on_point(t_point *pt, int scale);

#endif
