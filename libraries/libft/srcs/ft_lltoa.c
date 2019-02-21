/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:17:49 by brichard          #+#    #+#             */
/*   Updated: 2019/02/08 11:17:51 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa(long long l)
{
	int					i;
	int					size;
	char				*s;
	unsigned long long	ul;

	i = (l < 0 ? 1 : 0);
	ul = (l < 0 ? -l : l);
	size = (ft_get_num_size(ul, 10) + i);
	if (!(s = ft_strnew(size)))
		return (NULL);
	if (l < 0)
		s[0] = '-';
	while (size > i)
	{
		s[size - 1] = ul % 10 + '0';
		ul /= 10;
		size--;
	}
	return (s);
}
