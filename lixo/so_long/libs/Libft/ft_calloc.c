/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:07:04 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 21:07:04 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

// #include <stdlib.h>
// #include <stdio.h>

// int main() {
//     size_t nmemb = 5;
//     size_t size = 10;

//     void *ptr = ft_calloc(nmemb, size);

//     if (ptr) {
//         printf("Memory allocation successful!\n");

//         free(ptr);
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }