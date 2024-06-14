/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_helpers_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:19:54 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/13 13:52:08 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	add(double d1, double d2)
{
	return (d1 + d2);
}

double	substract(double d1, double d2)
{
	return (d1 - d2);
}

t_complex	complex_op(t_complex x, t_complex w, double (*f)(double, double))
{
	t_complex	z;

	z.a = f(x.a, w.a);
	z.b = f(x.b, w.b);
	return (z);
}

t_complex	complex_sqaure(t_complex x)
{
	t_complex	z;

	z.a = pow(x.a, 2) - pow(x.b, 2);
	z.b = 2 * x.a * x.b;
	return (z);
}
//z = a +bi
// z^2 = (a+ bi)^2 = a^2 -b^2 + 2 *a * b * i
