/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:59:46 by mpapin            #+#    #+#             */
/*   Updated: 2024/10/22 17:10:08 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*source;
	unsigned char		*dest;

	source = (const unsigned char *) src;
	dest = (unsigned char *) dst;
	if (dest == source)
		return (dst);
	if (dest > source)
		while (len--)
			dest[len] = source[len];
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	ft_memmove(str + 7, str, 5);
// 	printf("%s\n", str);
// 	return (0);
// }