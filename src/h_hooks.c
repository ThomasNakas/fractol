/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:49:44 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/14 11:53:18 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move_map(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keydata.key == MLX_KEY_UP)
		f->up_down_shift -= f->shift_factor;
	if (keydata.key == MLX_KEY_DOWN)
		f->up_down_shift += f->shift_factor;
	if (keydata.key == MLX_KEY_LEFT)
		f->left_right_shift += f->shift_factor;
	if (keydata.key == MLX_KEY_RIGHT)
		f->left_right_shift -= f->shift_factor;
	if (keydata.key == MLX_KEY_S)
		f->shift--;
	if (keydata.key == MLX_KEY_W)
		f->shift++;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(f->mlx, f->img);
		mlx_terminate(f->mlx);
		exit (0);
	}
	rendering(f, f->ac, f->av);
}

void	zoom_one(double xdelta, double ydelta, void *param)
{
	double		zoom_factor;
	double		range;
	double		mid;
	t_fractol	*f;

	f = (t_fractol *)param;
	zoom_factor = 0.025;
	xdelta = 0;
	range = f->s.new_max - f->s.new_min;
	mid = (f->s.new_max + f->s.new_min) / 2;
	if (ydelta > 0)
	{
		f->s.new_min = mid - range * (1 - zoom_factor) / 2;
		f->s.new_max = mid + range * (1 - zoom_factor) / 2;
	}
	else
	{
		f->s.new_min = mid - range * (1 + zoom_factor) / 2;
		f->s.new_max = mid + range * (1 + zoom_factor) / 2;
	}
	rendering(f, f->ac, f->av);
}
