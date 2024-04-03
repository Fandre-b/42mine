/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:22 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:36:14 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dlen;
	size_t		slen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size < dlen)
		return (slen + size);
	if (dlen < size - 1 && size > 0)
	{
		while (dlen + i < size - 1 && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	return (dlen + slen);
}
// #include <stdio.h>

// int main(void)
// {
//     char dest[20] = "Hello, ";
//     const char *src = "world!";
//     size_t size = sizeof(dest);

//     printf("Original destination string: %s\n", dest);

//     size_t result = ft_strlcat(dest, src, size);

//     printf("Concatenated string: %s\n", dest);
//     printf("Return value of ft_strlcat: %zu\n", result);

//     return 0;
// }
