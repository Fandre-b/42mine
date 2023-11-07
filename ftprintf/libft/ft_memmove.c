/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:24:55 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:32:11 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*chr_dst;
	char	*chr_src;

	chr_dst = (char *) dest;
	chr_src = (char *) src;
	if (dest == src)
		return (dest);
	if (chr_src < chr_dst)
	{
		while (n--)
			chr_dst[n] = chr_src [n];
	}
	else
	{
		while (n--)
			*chr_dst++ = *chr_src++;
	}
	return (dest);
}
