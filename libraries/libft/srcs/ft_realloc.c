/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:35:39 by brichard          #+#    #+#             */
/*   Updated: 2019/01/15 17:53:26 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_realloc(char **s, size_t len, int start)
{
	char	*tmp;

	if (!(tmp = ft_strnew(len)))
		return (NULL);
	if (*s != NULL)
	{
		ft_strcpy(tmp + start, *s);
		ft_memdel((void **)s);
	}
	return (tmp);
}
