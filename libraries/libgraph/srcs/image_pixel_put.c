/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/02/14 20:11:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"
#include "../../libft/includes/libft.h"

int		my_bit_colour(char c, int colour)
{
	if (c == 'R')
		return ((colour & 0xFF0000) >> 16);
	else if (c == 'G')
		return ((colour & 0x00FF00) >> 8);
	else
		return ((colour & 0x0000FF));
}

int		image_pixel_put(t_img *img, int x, int y, int colour)
{
	img->data[x * 4 + y * img->size_l + 2] = my_bit_colour('R', colour);
	img->data[x * 4 + y * img->size_l + 1] = my_bit_colour('G', colour);
	img->data[x * 4 + y * img->size_l + 0] = my_bit_colour('B', colour);
	return (0);
}
