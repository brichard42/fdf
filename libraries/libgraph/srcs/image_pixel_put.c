/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 20:39:06 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

int		image_pixel_put(t_img *img, int x, int y, int colour)
{
	if ((x * 4 + y * img->size_l + 2) > img->data_size)
		return (0);
	img->data[x * 4 + y * img->size_l + 2] = get_red_bit(colour);
	img->data[x * 4 + y * img->size_l + 1] = get_green_bit(colour);
	img->data[x * 4 + y * img->size_l + 0] = get_blue_bit(colour);
	return (0);
}
