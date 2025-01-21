/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:43:28 by mpapin            #+#    #+#             */
/*   Updated: 2024/09/17 14:43:28 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	nb_caracter;

	nb_caracter = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		nb_caracter += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		nb_caracter += ft_putnbr(n / 10);
	nb_caracter += ft_putchar((n % 10) + '0');
	return (nb_caracter);
}
