/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:40 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 20:14:59 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 && !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	new = ft_calloc(end - start + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], end - start + 1);
	return (new);
}
// #include <stdio.h>

// int main(void)
// {
//     const char *s1 = "   Hello, World!   ";
//     const char *set = " ";
//     char *trimmed = ft_strtrim(s1, set);

//     if (trimmed != NULL)
//     {
//         printf("Trimmed string: \"%s\"\n", trimmed);
//         free(trimmed);
//     }
//     else
//          printf("Failed to trim the string.\n");
//     return 0;
// }
