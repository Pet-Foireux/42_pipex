/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:42:39 by mpapin            #+#    #+#             */
/*   Updated: 2024/09/17 14:42:39 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnsigned(unsigned int n)
{
	int	nb_caracter;

	nb_caracter = 0;
	if (n > 9)
		nb_caracter += ft_putnsigned(n / 10);
	nb_caracter += ft_putchar((n % 10) + '0');
	return (nb_caracter);
}
