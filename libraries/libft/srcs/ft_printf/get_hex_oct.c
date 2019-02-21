/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <brichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:33:37 by brichard          #+#    #+#             */
/*   Updated: 2019/01/21 16:33:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ullong	get_hex_oct(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	if (CONV != 'p')
		nb = va_arg(*ap, unsigned int);
	else
		nb = (t_ullong)va_arg(*ap, t_ullong);
	return (nb);
}

t_ullong	get_hh_hex_oct(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	if (CONV != 'p')
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else
		nb = va_arg(*ap, t_ullong);
	return (nb);
}

t_ullong	get_h_hex_oct(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	if (CONV != 'p')
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else
		nb = va_arg(*ap, t_ullong);
	return (nb);
}

t_ullong	get_l_hex_oct(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	if (CONV != 'p')
		nb = va_arg(*ap, unsigned long);
	else
		nb = va_arg(*ap, t_ullong);
	return (nb);
}

t_ullong	get_ll_hex_oct(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	if (CONV != 'p')
		nb = va_arg(*ap, t_ullong);
	else
		nb = va_arg(*ap, t_ullong);
	return (nb);
}
