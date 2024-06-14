/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:39:57 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/14 11:59:32 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//f->s, &f->in.a, &f->in.b, f->j, f->z
void	remap(t_fractol *f)
{
	double	shift_x;
	double	shift_y;

	shift_x = (f->s.new_max - f->s.new_min) * f->left_right_shift;
	shift_y = (f->s.new_max - f->s.new_min) * f->up_down_shift;
	f->in.a = ((double)f->j - f->s.old_min) / (f->s.old_max - f->s.old_min)
		* (f->s.new_max - f->s.new_min) + f->s.new_min + shift_x;
	f->in.b = ((double)f->z - f->s.old_min) / (f->s.old_max - f->s.old_min)
		* (f->s.new_min - f->s.new_max) + f->s.new_max + shift_y;
}

// void	init_m(t_fractol *f, int x, int y)
// {
// }

void	init_j(t_fractol *f, int argc, char **argv)
{
	f->ct.a = -0.56;
	f->ct.b = 0.53;
	if (argc == 4)
	{
		f->ct.a = atod(argv[2]);
		f->ct.b = atod(argv[3]);
	}
}

void	init_z_zero_and_c(t_fractol *f, int argc, char **argv)
{
	remap(f);
	f->s_radius = f->s.new_max * f->s.new_max;
	if (argc == 4 || (argc == 2 && argv[1][0] == 'J'))
	{
		f->zt.a = f->in.a;
		f->zt.b = f->in.b;
	}
	else
	{
		f->ct.a = f->in.a;
		f->ct.b = f->in.b;
		f->zt.a = 0;
		f->zt.b = 0;
	}
	f->i = abs(-1 + f->shift);
}

void	init_fractol(t_fractol *f, int argc, char **argv)
{
	initialize_colors(f->c);
	f->img = NULL;
	f->mlx = NULL;
	f->j = 0;
	f->z = 0;
	f->i = 0;
	f->shift = 5;
	f->iterations = 250;
	f->s.old_max = 800;
	f->s.old_min = 0;
	f->s.new_max = 2;
	f->s.new_min = -2;
	f->ac = argc;
	f->av = argv;
	f->up_down_shift = 0;
	f->left_right_shift = 0;
	f->shift_factor = 0.01;
}
