/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:20:05 by brichard          #+#    #+#             */
/*   Updated: 2019/03/01 18:40:19 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pick_color(double z)
{
	if (z <= 0.0 && z > -10.0)
		return (0x3366FF);
	else if (z < -10.0 && z >= -20.0)
		return (0x0000FF);
	else if (z < -20.0 && z >= -30.0)
		return (0x0000CC);
	else if (z < -30.0 && z >= -40.0)
		return (0x000099);
	else if (z < -40.0)
		return (0x000066);
	else if (z > 0.0 && z <= 15.0)
		return (GREEN);
	else if (z >= 15.0 && z <= 60.0)
		return (YELLOW);
	else if (z >= 60.0 && z <= 90.0)
		return (RED);
	else
		return (WHITE);
}
