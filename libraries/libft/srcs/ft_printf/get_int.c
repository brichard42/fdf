/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:32:39 by brichard          #+#    #+#             */
/*   Updated: 2019/01/21 18:33:13 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		get_int(t_parse *res, va_list *ap)
{
	long long	nb;

	nb = va_arg(*ap, int);
	if (nb < 0)
	{
		nb *= -1;
		NEG = 1;
	}
	return (nb);
}

long long		get_hh_int(t_parse *res, va_list *ap)
{
	long long	nb;

	nb = (char)va_arg(*ap, int);
	if (nb < 0)
	{
		nb *= -1;
		NEG = 1;
	}
	return (nb);
}

long long		get_h_int(t_parse *res, va_list *ap)
{
	long long	nb;

	nb = (short)va_arg(*ap, int);
	if (nb < 0)
	{
		nb *= -1;
		NEG = 1;
	}
	return (nb);
}

long long		get_l_int(t_parse *res, va_list *ap)
{
	long long	nb;

	nb = va_arg(*ap, long);
	if (nb < 0)
	{
		nb *= -1;
		NEG = 1;
	}
	return (nb);
}

long long		get_ll_int(t_parse *res, va_list *ap)
{
	long long	nb;

	nb = va_arg(*ap, long long);
	if (nb < 0)
	{
		nb *= -1;
		NEG = 1;
	}
	return (nb);
}
