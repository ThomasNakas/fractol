/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_free_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:35:15 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/13 14:15:17 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_message(void)
{
	ft_printf("Invalid input!\n");
	ft_printf("Usage:\n");
	ft_printf("  ./fractol Mandelbrot\n");
	ft_printf("    OR\n");
	ft_printf("  ./fractol Julia value1 value2\n");
	ft_printf("  (where -2.00000000 <= value1");
	ft_printf(", value2 <= 2.00000000)\n");
}

void	error_message_is_valid(void)
{
	error_message();
	exit(1);
}

int	is_valid(char *s)
{
	int	f;
	int	i;

	f = 0;
	i = -1;
	while (s[++i] == ' ' || s[++i] == '\t')
		;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && (('0' <= s[i] && s[i] <= '9') || s[i] == '.') && f <= 1)
	{
		if (s[0] == '.')
			error_message_is_valid();
		if (s[i] == '.')
			f++;
		i++;
	}
	if (s[i] != '\0' || atod(s) < -2.00 || atod(s) > 2.00)
		error_message_is_valid();
	return (1);
}
