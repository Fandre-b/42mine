/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:14 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:33:43 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(s);
	dst = (char *) malloc (sizeof(char) * (src_len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, src_len + 1);
	return (dst);
}
