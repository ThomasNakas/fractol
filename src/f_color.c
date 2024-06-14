/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:38:06 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/13 04:08:30 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint32_t	interpolate_color(uint32_t color1, uint32_t color2, double t)
{
	t_color	c;

	c.r1 = (color1 >> 16) & 0xFF;
	c.g1 = (color1 >> 8) & 0xFF;
	c.b1 = color1 & 0xFF;
	c.r2 = (color2 >> 16) & 0xFF;
	c.g2 = (color2 >> 8) & 0xFF;
	c.b2 = color2 & 0xFF;
	c.r = (uint8_t)(c.r1 + t * (c.r2 - c.r1));
	c.g = (uint8_t)(c.g1 + t * (c.g2 - c.g1));
	c.b = (uint8_t)(c.b1 + t * (c.b2 - c.b1));
	return ((c.r << 16) | (c.g << 8) | c.b);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
