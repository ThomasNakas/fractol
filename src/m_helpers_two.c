/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_formulas_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:39:18 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/12 01:39:35 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	math_init_atod(char *s, t_atod *a)
{
	a->d = 0.0;
	a->f = -1;
	a->sign = 1;
	a->i = 0;
	while (s[a->i] == ' ' || s[a->i] == '\t')
		a->i++;
	if (s[a->i] == '+' || s[a->i] == '-')
	{
		if (s[a->i] == '-')
			a->sign = (-1) * a->sign;
		a->i++;
	}
}

double	atod(char *s)
{
	t_atod	a;

	math_init_atod(s, &a);
	a.i = a.i - 1;
	while (s[++a.i] && ((s[a.i] >= '0' && s[a.i] <= '9')
			|| (s[a.i] == '.' && a.f == -1)))
	{
		if (s[a.i] == '.')
		{
			a.f = a.i;
			continue ;
		}
		a.d = a.d * 10 + (s[a.i] - '0');
	}
	if (s[a.i])
	{
		exit (1);
	}
	if (a.f == -1)
		a.f = a.i - 1;
	return ((a.sign) * a.d * pow(10, -((double)a.i - a.f - 1)));
}
