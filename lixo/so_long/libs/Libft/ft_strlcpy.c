/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:25 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 18:44:16 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>

// int main(void)
// {
//     const char *src = "Hello, World!";
//     char dst[13]; 

//     size_t size = sizeof(dst); 
//     size_t result = ft_strlcpy(dst, src, size);

//     printf("Copied string: %s\n", dst);
//     printf("Return value of ft_strlcpy: %zu\n", result);

//     return 0;
// }
