/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:24:55 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/09 19:45:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char	*chr_dst;
	char	*chr_src;

	chr_dst = (char *) dst;
	chr_src = (char *) src;
	//if (!chr_src || 0 == size)
	if (dst == src)
		return (dst);
	if (chr_src < chr_dst)
	{
		while (size--)
			chr_dst[size] = chr_src [size];
	}
	else
	{
		while (size--)
			*chr_dst++ = *chr_src++;
	}
	return (dst);
}
