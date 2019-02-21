/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:34:49 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 14:48:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	task_manag(t_parse *res, char **tmp, va_list *ap, t_exfst *exf_tab)
{
	int			i;

	if (!(parsing(ap, res, tmp)))
		return (0);
	i = 0;
	while (i < TAB_SIZE && exf_tab[i].c != CONV)
		i++;
	if (i == TAB_SIZE)
		return (0);
	else if (!(exf_tab[i].exf(res, ap)))
		return (-1);
	write(1, STR, SSIZE);
	if (STR)
		ft_memdel((void **)&STR);
	return (1);
}

static int	pre_task(const char **format, va_list *ap, t_exfst *exf_tab)
{
	t_parse		res;
	int			ret;

	ini_res(&res);
	++*format;
	if ((ret = task_manag(&res, (char **)format, ap, exf_tab)) == -1)
	{
		va_end(*ap);
		return (-1);
	}
	else if (ret == 0)
		return (0);
	++*format;
	return (res.str_size);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		count;
	t_exfst		exf_tab[TAB_SIZE];
	int			ret;

	va_start(ap, format);
	count = 0;
	exf_tab_maker(exf_tab);
	while (*format)
	{
		ret = 0;
		if (*format != '%')
		{
			++count;
			write(1, format, 1);
			++format;
		}
		else if ((ret = pre_task(&format, &ap, exf_tab)) == -1)
			return (-1);
		count += ret;
	}
	va_end(ap);
	return (count);
}
