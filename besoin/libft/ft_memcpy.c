/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:59:42 by mpapin            #+#    #+#             */
/*   Updated: 2024/10/22 17:02:16 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src && n > 0)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst[20];

// 	ft_memcpy(dst, src, 13);
// 	dst[13] = '\0';
// 	printf("%s\n", dst);
// 	return (0);
// }
