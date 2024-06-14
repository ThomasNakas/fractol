/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:59:21 by tnakas            #+#    #+#             */
/*   Updated: 2024/03/16 02:40:50 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// c == 'x'
int	ft_puthexa(unsigned long n, char c, t_variables *var)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		if (ft_puthexa(n / 16, c, var) == -1)
			return (-1);
	}
	if (ft_putchar(base[n % 16], var) == -1)
		return (-1);
	return (0);
}

// c == "s"
int	ft_putstr(char *str, t_variables *var)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", var);
		return (-1);
	}
	while (*(str + i))
	{
		if (ft_putchar(*(str + i), var) == -1)
			return (-1);
		i++;
	}
	return (0);
}

// c == 'd' || c == 'i'
int	ft_putnbr(int n, t_variables *var)
{
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648", var) == -1)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		if (ft_putchar('-', var) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10, var) == -1)
			return (-1);
		if (ft_putchar(((n % 10) + '0'), var) == -1)
			return (-1);
	}
	else
		if (ft_putchar((n + '0'), var) == -1)
			return (-1);
	return (0);
}

//c == 'u'
int	ft_putunbr(unsigned int n, t_variables *var)
{
	if (n >= 10)
	{
		if (ft_putunbr(n / 10, var) == -1)
			return (-1);
		if (ft_putchar(((n % 10) + '0'), var) == -1)
			return (-1);
	}
	else
		if (ft_putchar((n + '0'), var) == -1)
			return (-1);
	return (0);
}

// c == 'p'
int	ft_putptr(void *p, t_variables *var)
{
	if (ft_putstr("0x", var) == -1)
		return (-1);
	if (ft_puthexa((unsigned long)p, 'x', var) == -1)
		return (-1);
	return (0);
}
