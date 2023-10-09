/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:22:41 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/06 22:33:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(str);
	if (start > len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	new_str = (char *) malloc (sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, &str[start], size + 1);
	return (new_str);
}
