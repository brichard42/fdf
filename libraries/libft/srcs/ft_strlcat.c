/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:24:33 by brichard          #+#    #+#             */
/*   Updated: 2018/11/14 14:34:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	max;
	size_t	s_src;
	size_t	s_dst;

	s_src = ft_strlen(src);
	s_dst = ft_strlen(dst);
	max = size - s_dst - 1;
	if (size <= s_dst)
		return (s_src + size);
	else
		ft_strncat(dst, src, max);
	return (s_dst + s_src);
}
