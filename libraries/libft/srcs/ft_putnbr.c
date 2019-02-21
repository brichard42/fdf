/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:08:53 by brichard          #+#    #+#             */
/*   Updated: 2018/12/12 17:16:58 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long l)
{
	unsigned long long	ul;

	ul = (l < 0 ? -l : l);
	if (l < 0)
		ft_putchar('-');
	if (ul > 9)
		ft_putnbr(ul / 10);
	ft_putchar(ul % 10 + '0');
}
