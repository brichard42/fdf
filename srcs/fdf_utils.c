/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:01 by brichard          #+#    #+#             */
/*   Updated: 2019/03/01 12:06:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(void **cont, int size)
{
	char	**tab;

	tab = (char **)*cont;
	while (--size >= 0)
		ft_memdel((void *)&tab[size]);
	free(tab);
	tab = NULL;
}

int		pexit(int exit_value)
{
	perror(strerror(errno));
	exit(exit_value);
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
