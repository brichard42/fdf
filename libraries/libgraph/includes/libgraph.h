/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:14:26 by brichard          #+#    #+#             */
/*   Updated: 2019/02/14 18:50:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# include "graph_structs.h"

int		image_pixel_put(t_img *img, int x, int y, int colour);

/*
** masques d'extraction des couleurs bitwise .. pitetre que j'dois les diviser en pitites fonctions
*/

int		my_bit_colour(char c, int colour);

#endif
