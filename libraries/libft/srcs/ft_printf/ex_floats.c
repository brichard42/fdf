/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:41:12 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 13:03:36 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ex_flop(t_parse *res, va_list *ap)
{
	long double		lf;

	if (PREC == -1)
		PREC = 6;
	get_lflop(res, ap, &lf);
	if (!(STR = (ft_ftoa_u(lf, PREC))))
		return (0);
	NSIZE = ft_strlen(STR);
	if (!(prefix(res)))
		return (0);
	SSIZE = ft_strlen(STR);
	if (!(width(res)))
		return (0);
	return (1);
}
