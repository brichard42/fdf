/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:49:36 by brichard          #+#    #+#             */
/*   Updated: 2019/02/15 22:42:10 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	put_in_lst(const int fd, t_list **begin)
{
	t_list	*new;
	char	*line;
	size_t	i;
	int		ret;

	line = NULL;
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
		ft_memdel((void **)&line);
	}
	if (ret < 0)
	{
		ft_lstdel(begin, ft_del_cont);
		return (-1);
	}
	return (i);
}

/*int				*convert_map(char *array)
{
	int		*map;
	int		i;

	i = 0;
	if (array == NULL)
		return (NULL);
	while (array[i])
	{
		if (ft_isdigit(array[i]))
			map = ft_atoi(array[i]); // il manque 1000 etapes ... genre, foutre le (int*)map a la bonne taille .. entre autre
		i++;
	}
	return (map);
}*/

int				get_file(int ac, char **av)
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
		num_lines = put_in_lst(fd, &begin);
		if (close(fd) == -1)
			return (-1);
	}
	while (begin != NULL)
	{
		ft_printf("GET_FILE | begin->content = \t[%s]\n", (char *)begin->content);
		begin = begin->next;
	}
	return (0);
}
