/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:21:04 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/13 14:16:20 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# define WIDTH 800
# define HEIGHT 800
//=============STRUCTS====================
//-----COMPLEX_RELATED-------
typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;
//-----CHECKER_RELATED-------
typedef struct s_atod
{
	int		i;
	double	d;
	int		sign;
	int		f;	
}	t_atod;
//----REMAPPING_RELATED-------
typedef struct s_scaler
{
	double	new_max;
	double	new_min;
	double	old_max;
	double	old_min;
}	t_scaler;

typedef struct s_remmap
{
	t_scaler	s_x;
	t_scaler	s_y;
	int			x;
	int			y;
	double		*new_x;
	double		*new_y;
}	t_remmap;
//-------COLOR_STRUCTs------------
typedef struct s_color
{
	uint32_t	color;
	uint8_t		r1;
	uint8_t		g1;
	uint8_t		b1;
	uint8_t		r2;
	uint8_t		g2;
	uint8_t		b2;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}	t_color;

//-------FRACTAL_RELATED---------
typedef struct s_fractol
{
	int			i;
	int			j;
	int			z;
	int			shift;
	t_scaler	s;
	int			s_radius;
	t_complex	zt;
	t_complex	ct;
	t_complex	in;
	t_color		c[25];
	int			iterations;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			ac;
	char		**av;
	double		up_down_shift;
	double		left_right_shift;
	double		shift_factor;
}	t_fractol;

//=============FRACTAL_INIT=====================
void		remap(t_fractol *f);
void		init_z_zero_and_c(t_fractol *f, int argc, char **argv);
void		init_j(t_fractol *f, int argc, char **argv);
void		init_fractol(t_fractol *f, int argc, char **argv);
//=============FRACTAL_ITERATION================
void		iterate(t_fractol *f, int argc, char **argv);
void		initialize_colors(t_color	colors[]);
void		rendering(t_fractol *f, int argc, char **argv);
//=============FREE_ERROR_HANDLING==============
void		error_message(void);
void		error_message_is_valid(void);
int			is_valid(char *s);
//================HOOK_HANDLING=================
void		move_map(mlx_key_data_t keydata, void *param);
void		zoom_one(double xdelta, double ydelta, void *param);
// void		zoom_map(double xdelta, double ydelta, void *param);
//===============MATH_HELPERS_ONE===============
double		add(double d1, double d2);
double		substract(double d1, double d2);
t_complex	complex_op(t_complex x, t_complex w,
				double (*f)(double, double));
t_complex	complex_sqaure(t_complex x);
//===============MATH_HELPER_TWO================
void		math_init_atod(char *s, t_atod *a);
double		atod(char *s);
//===============IMAGE_HELPERS==================
int			get_rgba(int r, int g, int b, int a);
uint32_t	interpolate_color(uint32_t color1, uint32_t color2, double t);
#endif