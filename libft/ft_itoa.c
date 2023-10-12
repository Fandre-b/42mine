/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:38 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:28:47 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numsize(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = ft_numsize(n);
	str = (char *) malloc (sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n != 0)
	{
		if (n < 0)
			str[--size] = (char)(-(n % 10) + '0');
		else
			str[--size] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}
