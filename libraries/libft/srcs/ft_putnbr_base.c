/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:36:39 by brichard          #+#    #+#             */
/*   Updated: 2018/12/12 15:04:28 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long l, char *base)
{
	int		size;

	size = ft_strlen(base);
	if (l < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (l >= size)
		ft_putnbr_base(l / size, base);
	ft_putchar(base[l % size]);
}
