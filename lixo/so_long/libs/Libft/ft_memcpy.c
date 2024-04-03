/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:36 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 18:06:35 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>

// int main(void)
// {
//     unsigned char src[] = "Hello, World!";
//     unsigned char dest[15]; 

//     size_t n = 14;

//     ft_memcpy(dest, src, n);

//     dest[n] = '\0';

//     printf("Copied string: %s\n", dest);

//     return 0;
// }
