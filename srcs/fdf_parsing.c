/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:28:12 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 20:39:07 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		put_in_point(t_list **begin, char *line,
								t_point *pt, size_t num_line)
{
	int		i;
	t_list	*new;

	i = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			pt->x = i;
			pt->y = num_line;
			pt->z = ft_atoi(line);
			if (!(new = ft_lstnew((void *)pt, sizeof(t_point))))
				return (0);
			ft_lstadd(begin, new);
			while (*line && ft_isdigit(*line))
				++line;
			++i;
		}
		++line;
	}
	return (1);
}

static int		put_in_lst(const int fd, t_list **begin)
{
	t_point	pt;
	char	*line;
	int		num_line;
	int		ret;

	line = NULL;
	num_line = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(put_in_point(begin, line, &pt, num_line)))
		{
			ft_lstdel(begin, ft_del_cont);
			ft_memdel((void **)&line);
			return (-1);
		}
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

int				fdf_parsing(char *av, t_list **begin)
{
	int		num_lines;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	if ((num_lines = put_in_lst(fd, begin)) == -1)
			return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
