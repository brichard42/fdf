/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:28:12 by brichard          #+#    #+#             */
/*   Updated: 2019/02/21 13:51:46 by evogel           ###   ########.fr       */
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

static void		fill_pts(t_point **pts, int i, char **line)
{
	int j;
	int neg;

	neg = 1;
	j = 0;
	while (**line)
	{
		if (**line != ' ')
		{
			(*pts)[j].x = j;
			(*pts)[j].y = i;
			if (**line == '-' && ++*line)
				neg = -1;
			while (ft_isdigit(**line))
				(*pts)[j].z = (*pts)[j].z * 10 + (**line - '0') * neg;
			++j;
		}
		if (**line)
			++*line;
	}
}

static int		make_pts(t_list *begin, t_file *file)
{
	int		i;
	int		count;
	char	*line;

	if (!(file->pts = (t_point **)ft_memalloc(sizeof(t_point *) * (file->y_len + 1))))
		return (-1);
	i = 0;
	while (begin && begin->content)
	{
		line = (char *)begin->content;
		if ((count = get_x_num(line)) > file->x_len)
			file->x_len = count; //if the count is bigger than current x_len, save new max x_len//
		if (!(file->pts[i] = (t_point *)ft_memalloc(sizeof(t_point) * (file->x_len + 1))))
		{
			//+++++++ TABDEL ICI SINON LEAKS ++++++++//
			return (-1);
		}
		fill_pts(&(file->pts[i]), i, &line);
		begin = begin->next;
		++i;
	}
	file->pts[i] = NULL;
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
	if ((make_pts(begin, file)) < 0)
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
