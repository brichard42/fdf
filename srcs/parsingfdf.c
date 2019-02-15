/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:49:36 by brichard          #+#    #+#             */
/*   Updated: 2019/02/15 20:49:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	parsingfdf(const int fd, t_list **begin)
{
	t_list	*new;
	char	*line;
	size_t	i;
	int		ret;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0) // gnl a reverifier == leaks
	{
		if (!(new = ft_lstnew((void *)line, ft_strlen(line) + 1)))
		{
			ft_lstdel(begin, ft_del_cont);
			free(line);
			return (-1);
		}
		ft_lstapp(begin, new);
		i++;
		free(line);
	}
	if (ret < 0)
	{
		ft_lstdel(begin, ft_del_cont);
		free(line);
		return (-1);
	}
	return (i);
}

int		get_file(int ac, char **av)
{
	t_list	*begin;
	size_t	num_lines;
	int		fd;

	begin = NULL;
	if (ac < 2)
		return (-1);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		num_lines = parsingfdf(fd, &begin);
		if (close(fd) == -1)
			return (-1);
	}
	while (begin != NULL)
	{
		ft_printf("GET_FILE | begin->content = [%s]\tnum_lines = {%d}\n", (char *)begin->content, num_lines);
		begin = begin->next;
	}
	return (0);
}
