/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:16:39 by brichard          #+#    #+#             */
/*   Updated: 2019/02/15 14:15:58 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	parsing(const int fd, t_list **begin)
{
//	t_list	*new;
	char	*line;
//	size_t	i;
	int		ret;

//	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0) // gnl a reverifier == leaks
	{
		/*if (!(new = ft_lstnew((void *)line, i++)))
		{
			ft_lstdel(begin, ft_del_cont);
			free(line);
			return (-1);
		}
		ft_lstapp(begin, new);*/
		ft_printf("[%s]", line);
	}
	if (ret < 0)
	{
		ft_lstdel(begin, ft_del_cont);
		free(line);
		return (-1);
	}
	return (/*i*/0);
}

int		get_file(int ac, char **av)
{
	t_list	*begin;
	size_t	num_lines;
	int		fd;

	begin = NULL;
	if (ac < 2)
		num_lines = parsing(0, &begin);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		num_lines = parsing(fd, &begin);
		if (close(fd) == -1)
			return (-1);
	}
	return (0);
}
