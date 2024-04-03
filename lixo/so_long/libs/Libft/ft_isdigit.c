/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:28 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:28 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

// #include <stdio.h>
// int main() {
//     int testChar1 = '5';
//     int testChar2 = 'A';

//     if (ft_isdigit(testChar1)) {
//         printf("%c is a digit.\n", testChar1);
//     } else {
//         printf("%c is not a digit.\n", testChar1);
//     }

//     if (ft_isdigit(testChar2)) {
//         printf("%c is a digit.\n", testChar2);
//     } else {
//         printf("%c is not a digit.\n", testChar2);
//     }

//     return 0;
// }