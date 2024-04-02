/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:33 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:33 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decimal_counter(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	writestrnumb(char *str, long n2, int i)
{
	while (n2 > 0)
	{
		str[i] = n2 % 10 + '0';
		n2 /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n2;
	int		len;
	int		i;

	n2 = n;
	len = decimal_counter(n2);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
	{
		if (n2 < 0)
		{
			str[0] = '-';
			n2 *= -1;
		}
		i = len - 1;
		writestrnumb(str, n2, i);
	}
	str[len] = '\0';
	return (str);
}

// #include <stdio.h>

// int main() {
//     int num1 = 12345;
//     int num2 = -6789;

//     char *str1 = ft_itoa(num1);
//     char *str2 = ft_itoa(num2);

//     printf("Integer 1: %d, String 1: %s\n", num1, str1);
//     printf("Integer 2: %d, String 2: %s\n", num2, str2);

//     free(str1);
//     free(str2);

//     return 0;
// }