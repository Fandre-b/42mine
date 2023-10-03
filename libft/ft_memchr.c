/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:17:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/03 14:26:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memchr(const void *str, int c, size_t size)
{
	const char	*chr_str;
	size_t	i;

	chr_str = (char *) str;
	while (chr_str && i < size - 1)
	{
		if (chr_str[i] == (char) c)
			return (str + i);
	}
	return (NULL);
}

