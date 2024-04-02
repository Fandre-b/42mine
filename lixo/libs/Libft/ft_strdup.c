/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:02:11 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:02:11 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src);
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, src, len);
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *src = "Hello, World!";
//     char *duplicate = ft_strdup(src);

//     if (duplicate != NULL)
//     {
//         printf("Duplicated string: %s\n", duplicate);
//         free(duplicate);
//     }
//     else
//     {
//         printf("Failed to duplicate the string.\n");
//     }

//     return 0;
// }
