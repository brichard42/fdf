/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_ubase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:16:41 by brichard          #+#    #+#             */
/*   Updated: 2019/02/08 11:16:51 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_ubase(unsigned long long ul, char *base)
{
	int					size;
	int					b_size;
	char				*s;

	b_size = ft_strlen(base);
	size = (ft_get_num_size(ul, b_size));
	if (!(s = ft_strnew(size)))
		return (NULL);
	while (size > 0)
	{
		s[size - 1] = base[ul % b_size];
		ul /= b_size;
		size--;
	}
	return (s);
}
