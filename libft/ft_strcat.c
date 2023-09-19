/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:36:11 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:28 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strcat(char *restrict dst, const char *restrict src);
{
	size_t	i;
	size_t	u;

	while(dest[i])
		i++;
	u = 0;
	while(src[u])
		dest[i++]=src[u++];
	dest[i]	= '\0';
	return (dest);
}
