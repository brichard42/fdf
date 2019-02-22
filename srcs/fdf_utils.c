/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:01 by brichard          #+#    #+#             */
/*   Updated: 2019/02/22 11:42:46 by evogel           ###   ########.fr       */
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
			ft_printf("[%5d %5d %5d] ", pts[i][j]->x, pts[i][j]->y, pts[i][j]->z);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
