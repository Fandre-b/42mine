/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:14 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 16:38:35 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(src);
	dst = (char *) malloc (sizeof(char) * (src_len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, src_len + 1);
	return (dst);
}