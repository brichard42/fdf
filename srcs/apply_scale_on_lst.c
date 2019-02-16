/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_scale_on_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:46:19 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 16:23:05 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_scale_on_lst(t_list *lst, int scale)
{
	while (lst != NULL)
	{
		apply_scale_on_point(((t_point *)lst->content), scale);
		lst = lst->next;
	}
}
