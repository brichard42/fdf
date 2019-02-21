/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ffun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:45:11 by brichard          #+#    #+#             */
/*   Updated: 2018/12/18 15:09:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_minu(t_parse *res)
{
	res->f_minus = 1;
	return (1);
}

int		p_plus(t_parse *res)
{
	res->f_plus = 1;
	return (1);
}

int		p_spac(t_parse *res)
{
	res->f_space = 1;
	return (1);
}

int		p_zero(t_parse *res)
{
	res->f_zero = 1;
	return (1);
}

int		p_hash(t_parse *res)
{
	res->f_hash = 1;
	return (1);
}
