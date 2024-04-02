/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:17 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:17 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>

// int main() {
//     int testChar1 = 'A';
//     int testChar2 = 128;
//     int testChar3 = 65; // 'A' in ASCII

//     if (ft_isascii(testChar1)) {
//         printf("%c is a valid ASCII character.\n", testChar1);
//     } else {
//         printf("%c is not a valid ASCII character.\n", testChar1);
//     }

//     if (ft_isascii(testChar2)) {
//         printf("%c is a valid ASCII character.\n", testChar2);
//     } else {
//         printf("%c is not a valid ASCII character.\n", testChar2);
//     }

//     if (ft_isascii(testChar3)) {
//         printf("%c is a valid ASCII character.\n", testChar3);
//     } else {
//         printf("%c is not a valid ASCII character.\n", testChar3);
//     }

//     return 0;
// }
