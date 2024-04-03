/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:54 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:54 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *str = "Hello, World!";
//     char target = 'o';

//     char *result = ft_strchr(str, target);

//     if (result != NULL)
//     {
//         size_t position = (size_t)(result - str);

//         printf("The character '%c' was found at %zu.\n", target, position);
//     }
//     else
//     {
//         printf("The character '%c' was not found in the string.\n", target);
//     }

//     return 0;
// }
