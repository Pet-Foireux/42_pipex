/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:36:17 by mpapin            #+#    #+#             */
/*   Updated: 2024/09/16 23:36:17 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int	ft_formats(va_list args, const char format)
{
	int	nb_caracter;

	nb_caracter = 0;
	if (format == 'c')
		nb_caracter += ft_putchar(va_arg(args, int));
	else if (format == 's')
		nb_caracter += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		nb_caracter += ft_putptr(va_arg(args, unsigned long long), 1);
	else if (format == 'd' || format == 'i')
		nb_caracter += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		nb_caracter += ft_putnsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		nb_caracter += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		nb_caracter += ft_putpercent();
	return (nb_caracter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		nb_caracter;

	i = 0;
	nb_caracter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			nb_caracter += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			nb_caracter += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (nb_caracter);
}
