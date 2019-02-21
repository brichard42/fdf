/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefwp_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:39:25 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 16:43:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			prec(t_parse *res)
{
	if (PREC == -1 || PREC <= (int)NSIZE)
		return (1);
	else if (PREC > (int)NSIZE)
	{
		if (!(STR = ft_realloc(&STR, PREC, PREC - NSIZE)))
			return (0);
		ft_memset(STR, '0', PREC - NSIZE);
		NSIZE = PREC;
	}
	return (1);
}

int			put_neg(t_parse *res)
{
	if (CONV != 'x' && CONV != 'X' && CONV != 'o')
	{
		if (!(STR = ft_realloc(&STR, NSIZE + 1, 1)))
			return (0);
		STR[0] = '-';
	}
	return (1);
}

int			prefix(t_parse *res)
{
	if (NEG == 1)
		put_neg(res);
	else if (FHAS == 1 && (CONV == 'x' || CONV == 'X'))
	{
		if (!(STR = ft_realloc(&STR, NSIZE + 2, 2)))
			return (0);
		STR[0] = '0';
		STR[1] = (CONV == 'x' ? 'x' : 'X');
		NEG = 2;
	}
	else if ((FPLU == 1 && CONV != 'o') || (FSPA == 1 && CONV != 'o')
				|| (CONV == 'o'
				&& FHAS == 1 && STR[0] != '0'))
	{
		if (!(STR = ft_realloc(&STR, NSIZE + 1, 1)))
			return (0);
		if (CONV == 'o' && FHAS == 1)
			STR[0] = '0';
		else
			STR[0] = (FPLU == 1 ? '+' : ' ');
	}
	return (1);
}

int			width(t_parse *res)
{
	int		rea;

	if (WIDTH <= (int)SSIZE)
		return (1);
	rea = (FMIN == 1 ? 0 : WIDTH - SSIZE);
	if (!(STR = ft_realloc(&STR, WIDTH, rea)))
		return (0);
	if (FZER == 1 && FMIN == 0 && (PREC == -1 || CONV == 's'))
	{
		ft_memset(STR, '0', WIDTH - (CONV == 's' ? SSIZE : NSIZE));
		if (NEG == 2 && (STR[0] = '0'))
			STR[1] = (CONV == 'x' ? 'x' : 'X');
		else if (NEG == 1)
			STR[0] = '-';
		else if (FPLU == 1)
			STR[0] = '+';
		else if (FSPA == 1)
			STR[0] = ' ';
	}
	else if (FMIN == 1)
		ft_memset(STR + SSIZE, ' ', WIDTH - SSIZE);
	else
		ft_memset(STR, ' ', WIDTH - SSIZE);
	SSIZE = WIDTH;
	return (1);
}
