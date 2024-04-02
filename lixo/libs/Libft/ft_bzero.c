/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:00:18 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:00:18 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char testString[] = "Hello, World!";

//     printf("Original String: %s\n", testString);
//     ft_bzero(testString, 5);
//     printf("Modified String: %s\n", testString);

//     return 0;
// }