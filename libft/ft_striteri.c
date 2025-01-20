/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:00:23 by mpapin            #+#    #+#             */
/*   Updated: 2024/10/21 15:19:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}

// void print_char(unsigned int index, char *c)
// {
//     printf("Character at index %u: %c\n", index, *c);
// }

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	ft_striteri(str, print_char);
// 	return (0);
// }
