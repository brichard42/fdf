/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:28:12 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 11:12:29 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_x_num(char *line, int *count)
{
	*count = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			++*count;
			while (*line && ft_isdigit(*line))
				++line;
		}
		if (*line && !(ft_isdigit(*line)))
			++line;
	}
}

static int		**put_in_tab(t_list *begin, int num_line)
{
	int		i;
	int		j;
	char	*line;
	int		count;
	int		**file;

	if (!(file = ft_memalloc((num_line + 1) * sizeof(int *))))
		return (NULL);
	i = 0;
	while (begin && begin->content)
	{
		line = (char *)begin->content;
		get_x_num(line, &count);
		if (!(file[i] = ft_memalloc((count) * 4)))
		{
			//+++++++ TABDEL ICI SINON LEAKS ++++++++
			return (NULL);
		}
		j = 0;
		while (*line)
		{
			if (ft_isdigit(*line))
			{
				file[i][j] = ft_atoi(line);
				while (*line && ft_isdigit(*line))
					++line;
				++j;
			}
			if (*line && !(ft_isdigit(*line)))
				++line;
		}
		begin = begin->next;
		++i;
	}
	return (file);
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

int				fdf_parsing(char *av, int ***file)
{
	int		fd;
	t_list	*begin;
	int		num_line;

	begin = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	if ((num_line = put_in_lst(fd, &begin)) == -1)
	{
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if (!(*file = put_in_tab(begin, num_line)))
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
