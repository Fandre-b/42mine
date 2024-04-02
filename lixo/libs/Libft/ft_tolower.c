/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:42 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:03:42 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

// #include <stdio.h>

// int main(void)
// {
//     int uppercaseChar = 'H';
// 	int lowercaseChar = ft_tolower(uppercaseChar);

//     printf("Uppercase character: %c\n", (char)uppercaseChar);
//     printf("Lowercase character: %c\n", (char)lowercaseChar);

//     return 0;
// }