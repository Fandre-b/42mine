/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:36:11 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:28 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	u;

	i = 0;
	while (dst[i])
		i++;
	u = 0;
	while (src[u])
		 dst[i++] = src[u++];
	 dst[i] = '\0';
	return ( dst);
}
