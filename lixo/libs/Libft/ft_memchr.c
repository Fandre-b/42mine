/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:09:44 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 21:05:59 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			return ((void *)s);
		}
		s++;
		n--;
	}
	return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     const char *str = "Hello, World!";
//     char target = 'W';
//     size_t n = strlen(str);

//     void *result = ft_memchr(str, target, n);

//     if (result != NULL)
//     {
//         size_t position = (size_t)(result - str);

//         printf("Char '%c' was found at position %zu.\n", target, position);
//     }
//     else
//     {
//         printf("Char '%c' was not found in the string.\n", target);
//     }

//     return 0;
// }