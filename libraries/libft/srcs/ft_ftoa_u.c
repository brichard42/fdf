/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:47:01 by brichard          #+#    #+#             */
/*   Updated: 2019/02/08 13:14:50 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_afterpoint(long double lf, char *s, int prec, size_t size)
{
	if (prec != 0)
		s[size++] = '.';
	while (prec > 0)
	{
		lf *= 10.0;
		s[size++] = (int)lf + '0';
		lf -= (int)lf;
		--prec;
	}
}

char		*ft_ftoa_u(long double lf, int prec)
{
	char		*s;
	size_t		size;

	if (prec == 0 && (((lf - (t_ullong)lf) == 0.5 && (t_ullong)lf % 2 == 1)
		|| lf - (t_ullong)lf > 0.5))
		lf += 1.0;
	else if (prec != 0)
		lf += 0.5 / ft_pow_ldo(10.0, prec);
	if (!(s = ft_ulltoa_ubase((t_ullong)lf, "0123456789")))
		return (NULL);
	size = ft_strlen(s);
	if (!(s = ft_realloc(&s, size + prec + (prec != 0 ? 1 : 0), 0)))
		return (NULL);
	ft_afterpoint(lf - (t_ullong)lf, s, prec, size);
	return (s);
}
