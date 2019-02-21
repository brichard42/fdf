/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:57:44 by brichard          #+#    #+#             */
/*   Updated: 2018/11/27 16:55:38 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	while (i < len)
		s2[i++] = s[start++];
	return (s2);
}
