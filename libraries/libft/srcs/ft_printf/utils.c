/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:41:51 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 13:20:14 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conv(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'f' || c == 's' || c == 'p' || c == '%'
			|| c == 'F' || c == 'D' || c == 'O' || c == 'U' || c == 'b');
}

void	ini_res(t_parse *res)
{
	FMIN = 0;
	FPLU = 0;
	FSPA = 0;
	FZER = 0;
	FHAS = 0;
	WIDTH = -1;
	PREC = -1;
	LEN = 0;
	CONV = '0';
	STR = NULL;
	SSIZE = 0;
	NSIZE = 0;
	NEG = 0;
}

void	skip_param(const char **s)
{
	while (**s && !(check_conv(**s)))
		++(*s);
	++*s;
}
