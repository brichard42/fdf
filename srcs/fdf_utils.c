/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:01 by brichard          #+#    #+#             */
/*   Updated: 2019/02/26 17:31:22 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pexit(int exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
}

int		ft_abs(int a)
{
	return (a > 0 ? a : -a);
}

void	put_tpoint(t_point ***pts)
{
	int i;
	int j;

	i = 0;
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
			ft_printf("[%5d] ", pts[i][j]->z);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_tpointcpy(t_point ***dst, t_point ***src)
{
	int i;
	int j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dst[i][j]->x = src[i][j]->x;
			dst[i][j]->y = src[i][j]->y;
			dst[i][j]->z = src[i][j]->z;
			j++;
		}
		i++;
	}
}
