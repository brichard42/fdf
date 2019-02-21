/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <brichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:48:09 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 16:33:56 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstapp(t_list **alst, t_list *lst)
{
	t_list	*tmp;

	if (alst == NULL)
		return ;
	tmp = NULL;
	if (*alst != NULL)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lst;
	}
	else
		*alst = lst;
	if (lst != NULL)
		lst->next = NULL;
}
