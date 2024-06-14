/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:13:51 by tnakas            #+#    #+#             */
/*   Updated: 2024/03/18 01:44:39 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	t_variables	*var;
	va_list		args;
	int			character_printed;

	if (!input)
		return (-1);
	va_start(args, input);
	var = malloc(sizeof(t_variables));
	if (!var)
		return (-1);
	var->cp = 0;
	var->error = 0;
	ft_datatype(input, args, var);
	va_end(args);
	character_printed = var->cp;
	if (var->error < 0)
	{
		free(var);
		return (-1);
	}
	free(var);
	return (character_printed);
}
