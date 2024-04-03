/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:03:48 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:03:48 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

// #include <stdio.h>

// int main(void)
// {
//     char lowercaseChar = 'h';
//     int uppercaseChar = ft_toupper(lowercaseChar);

//     printf("Original character: %c\n", lowercaseChar);
//     printf("Uppercase character: %c\n", (char)uppercaseChar);
//     return 0;
// }
