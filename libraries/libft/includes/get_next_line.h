/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:42:22 by brichard          #+#    #+#             */
/*   Updated: 2018/12/07 14:55:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4095
# define CURR_CONT (char *)current->content
# define P_CURR_CONT (char *)(*current)->content
# define P_CURR_FD (int)(*current)->content_size

int	get_next_line(const int fd, char **line);

#endif
