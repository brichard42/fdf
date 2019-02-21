/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:42:41 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 13:04:01 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		get_flop(t_parse *res, va_list *ap)
{
	long double lf;

	lf = va_arg(*ap, double);
	if (lf < 0)
	{
		lf *= -1;
		NEG = 1;
	}
	return (lf);
}

long double		get_l_flop(t_parse *res, va_list *ap)
{
	long double lf;

	lf = va_arg(*ap, long double);
	if (lf < 0)
	{
		lf *= -1;
		NEG = 1;
	}
	return (lf);
}
