/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:21:14 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 11:53:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length(t_parse *res, va_list *ap, t_ullong *nb)
{
	if (LEN == 4)
		*nb = get_ll_hex_oct(res, ap);
	else if (LEN == 1)
		*nb = get_hh_hex_oct(res, ap);
	else if (LEN == 2)
		*nb = get_h_hex_oct(res, ap);
	else if (LEN == 3)
		*nb = get_l_hex_oct(res, ap);
	else
		*nb = get_hex_oct(res, ap);
}

void	get_lint(t_parse *res, va_list *ap, long long *nb)
{
	if (LEN == 4)
		*nb = get_ll_int(res, ap);
	else if (LEN == 1)
		*nb = get_hh_int(res, ap);
	else if (LEN == 2)
		*nb = get_h_int(res, ap);
	else if (LEN == 3)
		*nb = get_l_int(res, ap);
	else
		*nb = get_int(res, ap);
}

void	get_lflop(t_parse *res, va_list *ap, long double *lf)
{
	if (LEN == 5)
		*lf = get_l_flop(res, ap);
	else
		*lf = get_flop(res, ap);
}
