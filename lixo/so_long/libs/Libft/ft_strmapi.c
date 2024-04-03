/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:28 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:03:28 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (len > 0)
	{
		len--;
		new[len] = f(len, s[len]);
	}
	return (new);
}

// #include <stdio.h>

// char custom_function(unsigned int index, char character)
// {
//     return character + (char)index;
// }

// int main(void)
// {
//     const char *str = "Hello, World!";

//     char *result = ft_strmapi(str, custom_function);

//     if (result != NULL)
//     {
//         printf("Transformed string: %s\n", result);
//         free(result);
//     }
//     else
//         printf("Failed to transform the string.\n");
//     return 0;
// }
