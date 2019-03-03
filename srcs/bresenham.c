/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <brichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 10:43:36 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 11:21:45 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bres_dey(t_img *img, t_point *pt1, t_vect *e, t_vect *incr)
{
	t_vect	d;
	t_vect	de;

	d.x = 2 * e->x;
	d.y = 2 * e->y;
	de.x = e->x;
	de.y = e->y;
	while (0 <= de.y)
	{
		image_pixel_put(img, pt1, pick_color(pt1->z));
		--de.y;
		pt1->y += incr->y;
		e->y -= d.x;
		if (e->y < 0)
		{
			pt1->x += incr->x;
			e->y += d.y;
		}
	}
}

static void	bres_dex(t_img *img, t_point *pt1, t_vect *e, t_vect *incr)
{
	t_vect	d;
	t_vect	de;

	d.x = 2 * e->x;
	d.y = 2 * e->y;
	de.x = e->x;
	de.y = e->y;
	while (0 <= de.x)
	{
		image_pixel_put(img, pt1, pick_color(pt1->z));
		--de.x;
		pt1->x += incr->x;
		e->x -= d.y;
		if (e->x < 0)
		{
			pt1->y += incr->y;
			e->x += d.x;
		}
	}
}

void		bresenham(t_img *img, t_point pt1, t_point pt2)
{
	t_vect	e;
	t_vect	incr;

	e.x = ft_abs(pt2.x - pt1.x);
	e.y = ft_abs(pt2.y - pt1.y);
	incr.x = (pt1.x > pt2.x ? -1 : 1);
	incr.y = (pt1.y > pt2.y ? -1 : 1);
	if (e.x >= e.y)
		bres_dex(img, &pt1, &e, &incr);
	else
		bres_dey(img, &pt1, &e, &incr);
}
