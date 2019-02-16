/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_scale_on_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:43:59 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 15:46:55 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	apply_scale_on_point(t_point *pt, int scale)
{
	pt->x *= scale;
	pt->y *= scale;
	pt->z *= scale;
}
