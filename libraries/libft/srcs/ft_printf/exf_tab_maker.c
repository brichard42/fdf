/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exf_tab_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:40:19 by brichard          #+#    #+#             */
/*   Updated: 2019/01/22 13:18:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		exf_tab_filler(t_exfst *exf_tab, char c, t_exf exf)
{
	exf_tab->c = c;
	exf_tab->exf = exf;
}

void		exf_tab_maker(t_exfst *exf_tab)
{
	exf_tab_filler(&(exf_tab[0]), 's', &ex_stri);
	exf_tab_filler(&(exf_tab[1]), 'c', &ex_char);
	exf_tab_filler(&(exf_tab[2]), 'd', &ex_ints);
	exf_tab_filler(&(exf_tab[3]), 'i', &ex_ints);
	exf_tab_filler(&(exf_tab[4]), 'o', &ex_octo);
	exf_tab_filler(&(exf_tab[5]), 'u', &ex_unsi);
	exf_tab_filler(&(exf_tab[6]), 'x', &ex_hexa);
	exf_tab_filler(&(exf_tab[7]), 'X', &ex_hexa);
	exf_tab_filler(&(exf_tab[8]), 'f', &ex_flop);
	exf_tab_filler(&(exf_tab[9]), 'p', &ex_point);
	exf_tab_filler(&(exf_tab[10]), '%', &ex_char);
	exf_tab_filler(&(exf_tab[11]), 'F', &bonus_f_cap);
	exf_tab_filler(&(exf_tab[12]), 'D', &bonus_d_cap);
	exf_tab_filler(&(exf_tab[13]), 'I', &bonus_d_cap);
	exf_tab_filler(&(exf_tab[14]), 'O', &bonus_o_cap);
	exf_tab_filler(&(exf_tab[15]), 'U', &bonus_u_cap);
	exf_tab_filler(&(exf_tab[16]), 'b', &ex_unsi);
	exf_tab_filler(&(exf_tab[17]), '@', NULL);
}
