/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:19:47 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 18:08:58 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
//     unsigned char data[] = "Hello, World!";
//     unsigned char dest[15]; 

//     size_t n = 14;

//     ft_memmove(dest, data, n);

//     dest[n] = '\0';

//     printf("Moved string: %s\n", dest);

//     return 0;
// }
