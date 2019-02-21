/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:38:49 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 14:09:41 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wild_card(t_parse *res, va_list *ap)
{
	if (PREC == -1)
	{
		if ((WIDTH = va_arg(*ap, int)) < 0)
		{
			WIDTH = -WIDTH;
			FMIN = 1;
		}
	}
	else
	{
		if ((PREC = va_arg(*ap, int)) < 0)
			PREC = -1;
	}
}

int		bonus_f_cap(t_parse *res, va_list *ap)
{
	LEN = 5;
	CONV += 32;
	if (!(ex_flop(res, ap)))
		return (0);
	return (1);
}

int		bonus_d_cap(t_parse *res, va_list *ap)
{
	if (LEN == 3)
		LEN = 4;
	else
		LEN = 3;
	CONV += 32;
	if (!(ex_ints(res, ap)))
		return (0);
	return (1);
}

int		bonus_o_cap(t_parse *res, va_list *ap)
{
	if (LEN == 3)
		LEN = 4;
	else
		LEN = 3;
	CONV += 32;
	if (!(ex_octo(res, ap)))
		return (0);
	return (1);
}

int		bonus_u_cap(t_parse *res, va_list *ap)
{
	if (LEN == 3)
		LEN = 4;
	else
		LEN = 3;
	CONV += 32;
	if (!(ex_unsi(res, ap)))
		return (0);
	return (1);
}
