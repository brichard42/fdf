/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:28:32 by brichard          #+#    #+#             */
/*   Updated: 2019/02/15 20:49:41 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = NULL;
	if (size == 0)
		return (s);
	if (!(s = (void*)malloc(size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
