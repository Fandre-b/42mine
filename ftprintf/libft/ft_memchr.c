/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:17:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/17 19:05:20 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*chr_str;
	size_t		i;

	chr_str = (char *) s;
	i = 0;
	while (i < n)
	{
		if (chr_str[i] == (char) c)
			return ((void *) &chr_str[i]);
		i++;
	}
	return (NULL);
}
