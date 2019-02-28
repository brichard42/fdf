/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:06:48 by brichard          #+#    #+#             */
/*   Updated: 2019/02/28 15:01:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_math *math)
{
	math->zoom += 0.1;
}

void	zoom_out(t_math *math)
{
	if (math->zoom > 1)
		math->zoom -= 0.1;
}

void	depth_inc(t_math *math)
{
	math->depth += 0.1;
}

void	depth_dec(t_math *math)
{
	math->depth -= 0.1;
}

void	center_scale(t_math *math)
{
	math->bol_center = 1;
	math->bol_scale = 1;
}
