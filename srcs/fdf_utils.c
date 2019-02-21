/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:01 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 17:52:45 by brichard         ###   ########.fr       */
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
