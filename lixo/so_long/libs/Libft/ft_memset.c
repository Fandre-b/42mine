/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:18:11 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 18:11:10 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

// #include <stdio.h>

// int main(void)
// {
//     unsigned char data[10];
//     ft_memset(data, 0xAA, sizeof(data));

//     printf("Memory block contents after ft_memset:\n");
//     for (size_t i = 0; i < sizeof(data); i++)
//     {
//         printf("%02X ", data[i]);
//     }
//     printf("\n");

//     return 0;
// }
