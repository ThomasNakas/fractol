/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:12:17 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/14 15:46:09 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int32_t	main(int argc, char **argv)
{
	t_fractol	f;

	init_fractol(&f, argc, argv);
	if ((argc == 2 && (!ft_strcmp(argv[1], "Mandelbrot")
				|| (!ft_strcmp(argv[1], "Julia"))))
		|| (argc == 4 && !ft_strcmp(argv[1], "Julia")
			&& is_valid(argv[2]) && is_valid(argv[3])))
	{
		init_j(&f, argc, argv);
		f.mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot-Julia", true);
		if (!f.mlx)
			error_message_is_valid();
		f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
		if (!f.img || (mlx_image_to_window(f.mlx, f.img, 0, 0) < 0))
			error_message_is_valid();
		rendering(&f, argc, argv);
		mlx_key_hook(f.mlx, &move_map, &f);
		mlx_scroll_hook(f.mlx, &zoom_one, &f);
		mlx_loop(f.mlx);
		mlx_terminate(f.mlx);
	}
	else
		error_message_is_valid();
	return (0);
}
