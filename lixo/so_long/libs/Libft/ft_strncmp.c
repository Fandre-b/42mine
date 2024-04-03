/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:31 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:03:31 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *str1 = "Hello, World!";
//     const char *str2 = "Hello, People!";
//     size_t n = 5;

//     int result = ft_strncmp(str1, str2, n);

//     if (result == 0)
//         printf("The first %zu char of the strings are equal.\n", n);
//     else if (result < 0)
//         printf("The first %zu char of str1 are less than str2.\n", n);
//     else
//         printf("The first %zu char of str1 are greater than str2.\n", n);
//     return 0;
// }
