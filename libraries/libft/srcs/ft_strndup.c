/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:39:01 by brichard          #+#    #+#             */
/*   Updated: 2019/01/21 13:46:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t len)
{
	char	*s2;
	int		i;

	if (!(s2 = (char*)ft_strnew(len)))
		return (0);
	i = 0;
	while (len > 0 && s1[i])
	{
		s2[i] = s1[i];
		++i;
		--len;
	}
	return (s2);
}
