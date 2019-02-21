/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:56:00 by brichard          #+#    #+#             */
/*   Updated: 2019/01/17 13:04:58 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_num_size(unsigned long long ul, size_t b_size)
{
	int		i;

	i = 1;
	while (ul > b_size - 1)
	{
		ul /= b_size;
		i++;
	}
	return (i);
}
