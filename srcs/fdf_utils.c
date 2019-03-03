/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:01 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 17:20:33 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(t_point ***tab, int size)
{
	if (tab == NULL)
		return ;
	while (--size >= 0)
		ft_memdel((void **)&(tab[size]));
	ft_memdel((void **)tab);
}

int		ft_abs(int a)
{
	return (a > 0 ? a : -a);
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
