/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/02/16 16:45:41 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "libgraph.h"
# include "mlx.h"
# include "fdf_errors.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define W_HEIGHT 900
# define W_WIDTH 1600

int		fdf_parsing(char *av, t_list **begin);
void	apply_scale_on_lst(t_list *lst, int scale);

#endif
