/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:13:47 by brichard          #+#    #+#             */
/*   Updated: 2019/02/15 11:14:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_red_bit(int colour)
{
	return ((colour & 0xFF0000) >> 16);
}

int		get_green_bit(int colour)
{
	return ((colour & 0x00FF00) >> 8);
}

int		get_blue_bit(int colour)
{
	return ((colour & 0x0000FF));
}
