/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_it.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:40:56 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/13 02:56:29 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
//the could be m_int or j_init
void	iterate(t_fractol *f, int argc, char **argv)
{
	double		t;
	int			color_index;
	double		blend;
	uint32_t	color;

	t = 0.0;
	color_index = 0;
	blend = 0.0;
	color = 0x000000;
	init_z_zero_and_c(f, argc, argv);
	while (++f->i < f->iterations)
	{
		if (f->zt.a * f->zt.a + f->zt.b * f->zt.b > 4)
		{
			t = (double)f->i / f->iterations;
			color_index = (int)(t * 24);
			blend = t * 24 - color_index;
			color = interpolate_color(f->c[color_index].color,
					f->c[color_index + 1].color, blend);
			mlx_put_pixel(f->img, f->j, f->z, color);
			break ;
		}
		f->zt = complex_op(complex_sqaure(f->zt), f->ct, add);
		mlx_put_pixel(f->img, f->j, f->z, get_rgba(0, 0, 0, 150 + f->i));
	}
}

void	initialize_colors(t_color	colors[])
{
	colors[0].color = 0xBF00FF;
	colors[1].color = 0x39FF14;
	colors[2].color = 0xFF69B4;
	colors[3].color = 0x7DF9FF;
	colors[4].color = 0x32CD32;
	colors[5].color = 0xFFFF00;
	colors[6].color = 0xFF4500;
	colors[7].color = 0x00FFFF;
	colors[8].color = 0xFF00FF;
	colors[9].color = 0x00BFFF;
	colors[10].color = 0x7FFF00;
	colors[11].color = 0xDC143C;
	colors[12].color = 0xFFD700;
	colors[13].color = 0x40E0D0;
	colors[14].color = 0xEE82EE;
	colors[15].color = 0x8A2BE2;
	colors[16].color = 0x5F9EA0;
	colors[17].color = 0xD2691E;
	colors[18].color = 0xFF7F50;
	colors[19].color = 0x6495ED;
	colors[20].color = 0xFF6347;
	colors[21].color = 0x4682B4;
	colors[22].color = 0x8B0000;
	colors[23].color = 0x20B2AA;
	colors[24].color = 0x000000FF;
}

void	rendering(t_fractol *f, int argc, char **argv)
{
	mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	f->z = -1;
	while (++f->z < HEIGHT)
	{
		f->j = -1;
		while (++f->j < WIDTH)
			iterate(f, argc, argv);
	}
}
