/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_pointnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:17:34 by brichard          #+#    #+#             */
/*   Updated: 2019/02/26 14:22:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_t_pointnew(long x, long y, long z)
{
	t_point		*pts;

	if (!(pts = ft_memalloc(sizeof(t_point))))
		return (NULL);
	pts->x = x;
	pts->y = y;
	pts->z = z;
	return (pts);
}
