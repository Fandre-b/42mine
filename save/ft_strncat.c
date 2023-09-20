/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:47:36 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/18 18:15:15 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	u;

	i = 0;
	while (dst[i])
		i++;
	u = 0;
	while (src[u] && u < size - 1)
		dst[i++] = src[u++];
	dst[i] = '\0';
	return (dst);
}
