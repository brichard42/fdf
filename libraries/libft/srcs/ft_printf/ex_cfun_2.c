/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cfun_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:35:14 by brichard          #+#    #+#             */
/*   Updated: 2019/02/08 13:10:56 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ex_unsi(t_parse *res, va_list *ap)
{
	unsigned long long	nb;

	FSPA = 0;
	FPLU = 0;
	get_length(res, ap, &nb);
	if (nb == 0 && PREC == 0)
		STR = ft_strdup("");
	else if (!(STR = ft_ulltoa_ubase(nb, (CONV == 'b' ? "01" : "0123456789"))))
		return (0);
	NSIZE = ft_strlen(STR);
	if (!(prec(res)))
		return (0);
	if (!(prefix(res)))
		return (0);
	SSIZE = ft_strlen(STR);
	if (!(width(res)))
		return (0);
	return (1);
}

int		ex_hexa(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	get_length(res, ap, &nb);
	if (nb == 0 && CONV != 'p')
		FHAS = 0;
	if (CONV == 'p')
		CONV = 'x';
	else if (CONV == 'P')
		CONV = 'X';
	if (nb == 0 && PREC == 0)
		STR = ft_strdup("");
	else if (!(STR = ft_ulltoa_ubase(nb, (CONV == 'x' ? H_BASE_LOW
						: H_BASE_CAP))))
		return (0);
	NSIZE = ft_strlen(STR);
	if (!(prec(res)))
		return (0);
	if (!(prefix(res)))
		return (0);
	SSIZE = ft_strlen(STR);
	if (!(width(res)))
		return (0);
	return (1);
}

int		ex_point(t_parse *res, va_list *ap)
{
	FHAS = 1;
	if (!(ex_hexa(res, ap)))
		return (0);
	return (1);
}
