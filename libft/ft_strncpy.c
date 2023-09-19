/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:47:36 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/19 03:16:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strncpy(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;

	i = 0;
	while(src[i] && i < size - 1)
		dst[i++] = src[i++];
	dest[i] = '\0';
	return (dest);
}
