/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:59:51 by mpapin            #+#    #+#             */
/*   Updated: 2024/10/22 17:08:44 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *) b;
	i = 0;
	while (i < (int) len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	char str[20] = "Hello, World!";
// 	ft_memset(str, 'X', 5);
// 	printf("%s\n", str);
// 	return (0);
// }