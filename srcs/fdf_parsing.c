/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:28:12 by brichard          #+#    #+#             */
/*   Updated: 2019/02/23 13:37:23 by brichard         ###   ########.fr       */
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
	int	res;

	neg = 1;
	j = 0;
	while (**line)
	{
		if (**line != ' ')
		{
			res = 0;
			if (**line == '-' && ++*line)
				neg = -1;
			while (ft_isdigit(**line))
			{
				res = res * 10 + (**line - '0') * neg;
				++*line;
			}
			pts[j] = ft_t_pointnew(j, i, res);
			++j;
		}
		if (**line)
			++*line;
	}
	pts[j] = NULL;
}

static int		make_pts(t_list *begin, t_point ****pts, int y_len)
{
	int		i;
	int		x_len;
	char	*line;

	if (!(*pts = (t_point ***)ft_memalloc(sizeof(t_point **) * (y_len + 1))))
		return (-1);
	line = (char *)begin->content;
	x_len = get_x_num(line);
	i = 0;
	while (begin && begin->content)
	{
		line = begin->content;
		if (get_x_num(line) != x_len)
			return (-1); //+++++ USAGE INVALID FILE +++++//
		if (!((*pts)[i] = (t_point **)ft_memalloc(sizeof(t_point*) * (x_len + 1))))
		{
			//+++++++ TABDEL ICI SINON LEAKS ++++++++//
			return (-1);
		}
		fill_pts((*pts)[i], i, &line);
		begin = begin->next;
		++i;
	}
	(*pts)[i] = NULL;
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
		if (!(new = ft_lstnew((void *)line, ft_strlen(line) + 1)))
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

int				fdf_parsing(char *av, t_point ****pts)
{
	int		fd;
	t_list	*begin;
	int		y_len;

	begin = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	if ((y_len = put_in_lst(fd, &begin)) == -1)
	{
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if ((make_pts(begin, pts, y_len)) < 0)
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
