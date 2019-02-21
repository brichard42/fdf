/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:55:02 by brichard          #+#    #+#             */
/*   Updated: 2018/11/08 15:46:25 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*pos;

	i = 0;
	len = ft_strlen(s);
	pos = NULL;
	while (i <= len)
	{
		if (s[i] == (char)c)
			pos = (char*)&s[i];
		i++;
	}
	return (pos);
}
