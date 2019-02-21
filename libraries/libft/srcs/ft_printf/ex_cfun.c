/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cfun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:28:40 by brichard          #+#    #+#             */
/*   Updated: 2019/02/08 13:09:47 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ex_stri(t_parse *res, va_list *ap)
{
	char	*arg;

	if ((arg = va_arg(*ap, char *)))
		SSIZE = ft_strlen(arg);
	else
		SSIZE = 6;
	if (SSIZE > PREC && PREC != -1)
		SSIZE = PREC;
	if (!(STR = (arg == 0 ? ft_strndup("(null)", SSIZE)
						: ft_strndup(arg, SSIZE))))
		return (0);
	if (!(width(res)))
		return (0);
	return (1);
}

int		ex_char(t_parse *res, va_list *ap)
{
	char	arg;
	char	fill;

	arg = (CONV == '%' ? '%' : (char)va_arg(*ap, int));
	SSIZE = (WIDTH < 1 ? 1 : WIDTH);
	if (!(STR = ft_realloc(&STR, SSIZE, 0)))
		return (0);
	if (WIDTH > 1)
		if (!(STR = ft_realloc(&STR, WIDTH, 0)))
			return (0);
	fill = (FZER == 1 && FMIN == 0 ? '0' : ' ');
	STR = ft_memset((void *)STR, fill, SSIZE);
	if (FMIN == 1)
		*STR = arg;
	else
		STR[SSIZE - 1] = arg;
	return (1);
}

int		ex_ints(t_parse *res, va_list *ap)
{
	unsigned long long	nb;

	get_lint(res, ap, (long long*)&nb);
	if (!(STR = (ft_ulltoa_ubase(nb, "0123456789"))))
		return (0);
	if (nb == 0 && PREC != -1)
		STR = ft_strdup("");
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

int		ex_octo(t_parse *res, va_list *ap)
{
	t_ullong	nb;

	get_length(res, ap, &nb);
	if (nb == 0)
	{
		if (PREC == 0)
			STR = ft_strdup("");
		else
		{
			FHAS = 0;
			STR = ft_strdup("0");
		}
	}
	else if (!(STR = ft_ulltoa_ubase(nb, "01234567")))
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
