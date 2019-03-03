/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 12:29:58 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_pixel_put(t_img *img, t_point *pt, int colour)
{
	if (((pt->x + pt->y * W_WIDTH) > W_HEIGHT * W_WIDTH)\
			|| (pt->x + pt->y  * W_WIDTH) < 0 || pt->x < 0 || pt->y < 0\
			|| pt->y >= W_HEIGHT || pt->x >= W_WIDTH)
		return (0);
	if (pt->x < 155 && pt->y < 200)
		return (0);
	img->data[(int)pt->x + (int)pt->y * W_WIDTH] = colour;
	return (1);
}
