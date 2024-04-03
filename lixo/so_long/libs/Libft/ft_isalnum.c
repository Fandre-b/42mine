/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:46 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 18:51:46 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}

// #include <stdio.h>

// int main() {
//     int testChar1 = 'A';
//     int testChar2 = '5';
//     int testChar3 = '#';

//     if (ft_isalnum(testChar1)) {
//         printf("%c is an alphanumeric character.\n", testChar1);
//     } else {
//         printf("%c is not an alphanumeric character.\n", testChar1);
//     }

//     if (ft_isalnum(testChar2)) {
//         printf("%c is an alphanumeric character.\n", testChar2);
//     } else {
//         printf("%c is not an alphanumeric character.\n", testChar2);
//     }

//     if (ft_isalnum(testChar3)) {
//         printf("%c is an alphanumeric character.\n", testChar3);
//     } else {
//         printf("%c is not an alphanumeric character.\n", testChar3);
//     }

//     return 0;
// }