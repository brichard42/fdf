/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:20:05 by brichard          #+#    #+#             */
/*   Updated: 2019/03/01 15:54:14 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pick_color(double z)
{
	if (z <= 0.0)
		return (BLUE);
	else if (z > 0.0 && z <= 15.0)
		return (GREEN);
	else if (z >= 15.0 && z <= 60.0)
		return (YELLOW);
	else if (z >= 60.0 && z <= 90.0)
		return (RED);
	else
		return (WHITE);
}
