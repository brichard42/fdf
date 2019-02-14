/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:58 by brichard          #+#    #+#             */
/*   Updated: 2019/02/14 11:28:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

int		image_pixel_put(t_img *img, int x, int y, int color)
{
	img->data[x + y * img->size_l / 4] = color; // c'est degueulasse, faut soit prendre W_WIDTH, soit prendre data en char *, mais pas mixer .... 
	return (0);
}
