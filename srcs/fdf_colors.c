/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:20:05 by brichard          #+#    #+#             */
/*   Updated: 2019/03/01 15:20:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pick_color(t_math math, double z)
{
/*	z = z / math.dif.dz;
	if (z <= 0.0)
		return (BLUE);
	else if (z > 0.0 && z <= 0.1)
		return (GREEN);
	else if (z >= 0.1 && z <= 0.4)
		return (YELLOW);
	else if (z >= 0.4 && z <= 0.7)
		return (RED);
	else
		return (WHITE);*/
	(void)math;
	if (z <= 0.0)
		return (BLUE);
	else if (z > 0.0 && z <= 10.0)
		return (GREEN);
	else if (z >= 10.0 && z <= 50.0)
		return (YELLOW);
	else if (z >= 50.0 && z <= 80.0)
		return (RED);
	else
		return (WHITE);
}
