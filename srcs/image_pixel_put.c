/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/03/01 17:10:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_pixel_put(t_img *img, int x, int y, int colour)
{
	if (((x + y * W_WIDTH) > W_HEIGHT * W_WIDTH) || (x + y  * W_WIDTH) < 0 || x < 0 || y < 0 || y >= W_HEIGHT || x >= W_WIDTH)
		return (0);
	img->data[x + y * W_WIDTH] = colour;
	return (1);
}
