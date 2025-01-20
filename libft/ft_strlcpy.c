/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:00:35 by mpapin            #+#    #+#             */
/*   Updated: 2024/10/22 17:22:25 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	source;

	source = ft_strlen(src);
	i = 0;
	if (dstsize <= 0)
		return (source);
	while (i < dstsize - 1)
	{
		if (src[i] == '\0')
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (source);
}

// int	main(void)
// {
// 	char dest[20];
// 	const char *src = "Hello, World!";
// 	size_t result = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Copied: %s, Length: %zu\n", dest, result);
// 	return (0);
// }
