/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:17:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/06 22:37:45 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	const char	*chr_str;
	size_t		i;

	chr_str = (char *) str;
	i = 0;
	while (i < size)
	{
		if (chr_str[i] == (char) c)
			return ((void *) &chr_str[i]);
		i++;
	}
	return (NULL);
}
