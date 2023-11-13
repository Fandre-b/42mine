/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:29:01 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:32:12 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*chr_dst;
	const char	*chr_src;

	if (!dest && !src)
		return (NULL);
	chr_dst = (char *) dest;
	chr_src = (char *) src;
	while (n-- > 0)
		chr_dst[n] = chr_src[n];
	return (dest);
}
