/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:00:50 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:00:50 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

// #include <stdio.h>
// int main() {
//     int testChar1 = '5';
//     int testChar2 = 'A';

//     if (ft_isalpha(testChar1)) {
//         printf("%c is an alpha.\n", testChar1);
//     } else {
//         printf("%c is not an alpha.\n", testChar1);
//     }

//     if (ft_isalpha(testChar2)) {
//         printf("%c is an alpha.\n", testChar2);
//     } else {
//         printf("%c is not an alpha.\n", testChar2);
//     }

//     return 0;
// }