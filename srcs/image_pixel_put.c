/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/02/22 21:04:00 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_pixel_put(t_img *img, int x, int y, int colour)
{
	if (((x * 4 + y  * img->size_l) > W_HEIGHT * img->size_l) || (x * 4 + y  * img->size_l) < 0)
		return (0);
	img->data[x + y * img->size_l / 4 ] = colour;
	return (0);
}
