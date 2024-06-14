/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:16 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/18 01:44:58 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_variables
{
	int		cp;
	int		error;
}	t_variables;

int	ft_printf(const char *input, ...);
int	ft_datatype(const char *input, va_list args, t_variables *var);
int	ft_printf_check(char c, va_list args, t_variables *var);
int	ft_putchar(char c, t_variables *var);
int	ft_putstr(char *str, t_variables *var);
int	ft_putnbr(int n, t_variables *var);
int	ft_putunbr(unsigned int n, t_variables *var);
int	ft_puthexa(unsigned long n, char c, t_variables *var);
int	ft_putptr(void *p, t_variables *var);

#endif
