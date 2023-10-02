/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:21:31 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 19:21:44 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*dst;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	dst = (char *) malloc (sizeof(char) * (str1_len + str2_len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, str1, str1_len + 1);
	ft_strlcat(dst, str2, str1_len + str2_len + 1);
	dst[str1_len + str2_len + 1] = '\0';
	return (dst);
}
