/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:28:12 by brichard          #+#    #+#             */
/*   Updated: 2019/03/03 18:02:02 by brichard         ###   ########.fr       */
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

static int		fill_pts(t_point **pts, t_point **ori, int i, char **line)
{
	int		j;
	int		neg;
	long	res;

	j = 0;
	while (**line)
	{
		if (**line != ' ')
		{
			neg = 1;
			res = 0;
			if (**line == '-' && ++*line)
				neg = -1;
			while (ft_isdigit(**line))
			{
				res = res * 10 + (**line - '0') * neg;
				++*line;
			}
			if (!(pts[j] = ft_t_pointnew(j, i, res))) // FREE
				return (0);
			if (!(ori[j] = ft_t_pointnew(j, i, res)))
				return (0);
			++j;
		}
		if (**line)
			++*line;
	}
	pts[j] = NULL;
	ori[j] = NULL;
	return (1);
}

static int		make_pts(t_list *begin, t_mlx *env, int y_len)
{
	int		i;
	int		x_len;
	char	*line;

	if (!(env->pts = (t_point ***)ft_memalloc(sizeof(t_point **) * (y_len + 1))))
		return (-1);
	if (!(env->ori = (t_point ***)ft_memalloc(sizeof(t_point **) * (y_len + 1))))
	{
		free(env->pts);
		return (-1);
	}
	line = (char *)begin->content;
	x_len = get_x_num(line);
	i = 0;
	while (begin && begin->content)
	{
		line = begin->content;
		if (get_x_num(line) != x_len)
			return (i); //+++++ USAGE INVALID FILE +++++//
		if (!(env->pts[i] = (t_point **)ft_memalloc(sizeof(t_point*) * (x_len + 1))))
			return (i);
		if (!(env->ori[i] = (t_point **)ft_memalloc(sizeof(t_point*) * (x_len + 1))))
			return (i);
		if (!(fill_pts(env->pts[i], env->ori[i], i, &line)))
			return (i);
		begin = begin->next;
		++i;
	}
	env->pts[i] = NULL;
	env->ori[i] = NULL;
	return (-2);
}

static int		line_test(char *line)
{
	while (*line)
	{
		if (*line != ' ' && ft_isdigit(*line) == 0 && *line != '-')
			return (0);
		++line;
	}
	return (1);
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
		if (!(line_test(line)))
		{
			ft_memdel((void **)&line);
			return (-1);
		}
		if (!(new = ft_lstnew((void *)line, ft_strlen(line) + 1)))
		{
			ft_memdel((void **)&line);
			return (-1);
		}
		ft_lstapp(begin, new);
		++num_line;
		ft_memdel((void **)&line);
	}
	if (ret < 0)
		return (-1);
	return (num_line);
}

int				fdf_parsing(char *av, t_mlx *env)
{
	int		fd;
	t_list	*begin;
	int		y_len;

	begin = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	if ((y_len = put_in_lst(fd, &begin)) <= 0)
	{
		ft_lstdel(&begin, ft_del_cont);
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if ((make_pts(begin, env, y_len)) < 0)
	{
		ft_lstdel(&begin, ft_del_cont);
		if (close(fd) == -1)
			return (-1);
		return (-1);
	}
	if (close(fd) == -1)
	{
		ft_lstdel(&begin, ft_del_cont);
		return (-1);
	}
	ft_lstdel(&begin, ft_del_cont);
	return (0);
}
