/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:16 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 18:01:54 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*aux1 != *aux2)
			return (*aux1 - *aux2);
		aux1++;
		aux2++;
		n--;
	}
	return (0);
}
// #include <stdio.h>

// int main(void)
// {
//     unsigned char block1[] = {0x41, 0x42, 0x43, 0x44, 0x45};
//     unsigned char block2[] = {0x41, 0x42, 0x43, 0x44, 0x46};
//     size_t n = 5; 
//     int result = ft_memcmp(block1, block2, n);

//     if (result < 0)
//     {
//         printf("Block 1 is less than Block 2.\n");
//     }
//     else if (result > 0)
//     {
//         printf("Block 1 is greater than Block 2.\n");
//     }
//     else
//     {
//         printf("Block 1 is equal to Block 2.\n");
//     }

//     return 0;
// }
