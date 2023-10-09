/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:38 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/06 22:36:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numsize(int num)
{
	size_t	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	size_t	size;
	char	*str;

	size = ft_numsize(num);
	str = (char *) malloc (sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (num < 0)
		str[0] = '-';
	if (num == 0)
		str[0] = '0';
	str[size] = '\0';
	while (num != 0)
	{
		if (num < 0)
			str[--size] = (char)(-(num % 10) + '0');
		else
			str[--size] = (char)((num % 10) + '0');
		num /= 10;
	}
	return (str);
}
