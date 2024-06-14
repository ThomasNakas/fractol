/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_related.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:30:34 by tnakas            #+#    #+#             */
/*   Updated: 2024/03/18 02:09:51 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// datatype initialization
int	ft_datatype(const char *in, va_list args, t_variables *var)
{
	size_t	i;

	i = 0;
	while (*(in + i))
	{
		if (*(in + i) == '%' && *(in + i + 1))
		{
			i++;
			ft_printf_check(*(in + i), args, var);
		}
		else
			ft_putchar(*(in + i), var);
		i++;
		if (var->error < 0)
			return (-1);
	}
	return (0);
}

// type statements
int	ft_printf_check(char c, va_list args, t_variables *var)
{
	if (c == '%')
		ft_putchar('%', var);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), var);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), var);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), var);
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), var);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(args, unsigned int), c, var);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), var);
	else
		var->error = -1;
	return (var->error);
}

// c == "c"
int	ft_putchar(char c, t_variables *var)
{
	int	out;

	out = write(1, &c, 1);
	if (out < 0)
	{
		var->error = -1;
		return (-1);
	}
	var->cp++;
	return (1);
}
