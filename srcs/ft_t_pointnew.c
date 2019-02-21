/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_pointnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:17:34 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 16:43:03 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_t_pointnew(int x, int y, int z)
{
	t_point		*pts;

	if (!(pts = ft_memalloc(sizeof(t_point))))
		return (NULL);
	pts->x = x;
	pts->y = y;
	pts->z = z;
	return (pts);
}
