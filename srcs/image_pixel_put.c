/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 17:02:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_pixel_put(t_img *img, int x, int y, int colour)
{
	if ((x + y  * img->size_l / 4) > img->data_size)
		return (0);
	img->data[x + y * img->size_l / 4 ] = colour;
	return (0);
}
