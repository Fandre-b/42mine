/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:30 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 20:12:54 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little && !big)
		return (NULL);
	if (ft_strlen(little) == 0 || big == little)
		return ((char *)(big));
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     const char *big = "Hello, World!";
//     const char *little = "World";
//     size_t len = ft_strlen(big);
//     char *result = ft_strnstr(big, little, len);

//     if (result != NULL)
//     {
//         size_t position = (size_t)(result - big);
//         printf("The sub '%s' was found at position %zu.\n");
//     }
//     else
//         printf("The sub '%s' was not found.\n", little);

//     return 0;
// }
