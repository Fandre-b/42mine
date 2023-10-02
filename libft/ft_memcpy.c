/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:29:01 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 21:04:50 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char	*char_dst;
	const char	*char_src;
	
	char_dst = (char *) dst;
	char_src = (char *) src;
	while (size-- > 0)
		char_dst[size] = char_src[size];
	return (dst);
}
