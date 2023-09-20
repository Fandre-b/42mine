/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:30:04 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/17 12:24:55 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	u;

	i = 0;
	u = 0;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	while (str[i++])
	{
		if (str[i] == (char)c)
			u = i;
	}
		if (u != 0)
			return ((char *)&str[u]);
	return (NULL);
}
