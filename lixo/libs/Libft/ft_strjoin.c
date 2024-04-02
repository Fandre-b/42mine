/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:19 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/04 14:26:55 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1len;
	int		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = ft_calloc(s1len + s2len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memmove((void *)(new), s1, s1len);
	ft_memmove((void *)(new + s1len), s2, s2len);
	new[s1len + s2len] = '\0';
	return (new);
}
// #include <stdio.h>

// int main(void)
// {
//     const char *s1 = "Hello, ";
//     const char *s2 = "World!";

//     char *result = ft_strjoin(s1, s2);

//     if (result != NULL)
//     {
//         printf("Concatenated string: %s\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("Failed to concatenate the strings.\n");
//     }

//     return 0;
// }
