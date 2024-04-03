/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:37 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 20:35:53 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s)
		return (NULL);
	if (len >= ft_strlen(s)- start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, (const void *)(s + start), len);
	str[len] = '\0';
	return (str);
}
// #include <stdio.h>

// int main(void)
// {
//     const char *s = "This is a sample string.";
//     unsigned int start = 5; 
//     size_t len = 7;

//     char *substring = ft_substr(s, start, len);

//     if (substring != NULL)
//     {
//         printf("Extracted substring: \"%s\"\n", substring);
//         free(substring);
//     }
//     else
//         printf("Failed to extract the substring.\n");
//     return 0;
// }
