/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:55:18 by brichard          #+#    #+#             */
/*   Updated: 2019/03/01 16:39:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_left(t_math *math)
{
	math->x_move -= 7 * (math->dif.dx / math->dif.dy + 1);
}

void	move_right(t_math *math)
{
	math->x_move += 7 * (math->dif.dx / math->dif.dy + 1);
}

void	move_down(t_math *math)
{
	math->y_move += 7 * (math->dif.dx / math->dif.dy + 1);
}

void	move_up(t_math *math)
{
	math->y_move -= 7 * (math->dif.dx / math->dif.dy + 1);
}

void	move_center(t_math *math)
{
	math->bol_center = 1;
}
