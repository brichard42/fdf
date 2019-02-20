/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:28:12 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 22:18:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_x_num(char *line)
{
	int count;

	count = 0;
	while (*line)
	{
		if (*line != ' ')
		{
			++count;
			while (*line && *line != ' ')
				++line;
		}
		if (*line)
			++line;
	}
	return (count);
}

static int		put_in_tab(t_list *begin, t_file *file)
{
	int		i;
	int		j;
	char	*line;

	if (!(file->tab = (int **)ft_memalloc((file->y_len + 1) * sizeof(int *))))
		return (-1);
	i = 0;
	line = (char *)begin->content;
	file->x_len = get_x_num(line);
	while (begin && begin->content)
	{
		line = (char *)begin->content;
		if (get_x_num(line) != file->x_len)
			return (-2); //+++++++ADD USAGE "INVALID FILE" HERE+++++++//
		if (!(file->tab[i] = (int *)ft_memalloc(file->x_len * 4)))
		{
			//+++++++ TABDEL ICI SINON LEAKS ++++++++//
			return (-1);
		}
		j = 0;
		while (*line)
		{
			if (*line != ' ')
			{
				file->tab[i][j] = ft_atoi(line);
				while (*line != ' ' && *line)
					++line;
				++j;
			}
			if (*line)
				++line;
		}
		begin = begin->next;
		++i;
	}
	return (0);
}

static int		put_in_lst(const int fd, t_list **begin)
{
	char	*line;
	int		num_line;
	int		ret;
	t_list	*new;

	line = NULL;
	num_line = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(new = ft_lstnew((void *)line, ft_strlen(line))))
		{
			ft_lstdel(begin, ft_del_cont);
			ft_memdel((void **)&line);
			return (-1);
		}
		ft_lstapp(begin, new);
		++num_line;
		ft_memdel((void **)&line);
	}
	if (ret < 0)
	{
		ft_lstdel(begin, ft_del_cont);
		return (-1);
	}
	return (num_line);
}

int				fdf_parsing(char *av, t_file *file)
{
	int		fd;
	t_list	*begin;

	begin = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	if ((file->y_len = put_in_lst(fd, &begin)) == -1)
	{
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if ((put_in_tab(begin, file)) < 0)
	{
		ft_lstdel(&begin, ft_del_cont);
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
