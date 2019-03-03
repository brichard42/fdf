/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:01 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 19:24:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_test(char *line)
{
	while (*line)
	{
		if (*line != ' ' && ft_isdigit(*line) == 0 && *line != '-')
			return (0);
		++line;
	}
	return (1);
}

void	malo_exit(void)
{
	ft_putendl("Error: Malloc crash.");
	close(3);
	exit(-1);
}

void	file_exit(void)
{
	ft_putendl("Error: Invalid file.");
	close(3);
	exit(-2);
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
			++j;
		}
		++i;
	}
}
