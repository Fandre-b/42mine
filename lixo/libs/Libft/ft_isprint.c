/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:30 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:30 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>

// int main() {
//     int testChar1 = 'A';
//     int testChar2 = '\t';  // Tab character
//     int testChar3 = 127;   // Del character (not printable)
//     int testChar4 = '1';

//     if (ft_isprint(testChar1)) {
//         printf("%c is a printable character.\n", testChar1);
//     } else {
//         printf("%c is not a printable character.\n", testChar1);
//     }

//     if (ft_isprint(testChar2)) {
//         printf("%c is a printable character.\n", testChar2);
//     } else {
//         printf("%c is not a printable character.\n", testChar2);
//     }

//     if (ft_isprint(testChar3)) {
//         printf("%c is a printable character.\n", testChar3);
//     } else {
//         printf("%c is not a printable character.\n", testChar3);
//     }

//     if (ft_isprint(testChar4)) {
//         printf("%c is a printable character.\n", testChar4);
//     } else {
//         printf("%c is not a printable character.\n", testChar4);
//     }

//     return 0;
// }
