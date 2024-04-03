/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:57:40 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 18:57:40 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// #include <stdio.h>

// int main() {
//     const char *str1 = "12345";
//     const char *str2 = "-6789";
//     const char *str3 = " 42 is the answer.";

//     int result1 = ft_atoi(str1);
//     int result2 = ft_atoi(str2);
//     int result3 = ft_atoi(str3);

//     printf("Result 1: %d\n", result1);
//     printf("Result 2: %d\n", result2);
//     printf("Result 3: %d\n", result3);

//     return 0;
// }
