/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:22:32 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/03 15:04:36 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memmove(void *dst, const void *src, size_t size)
{
	void	*temp;

	if (!dst || !src)
		return(NULL);
	temp = (void *) malloc ((size) * sizeof (char));
	if (!temp)
		return (NULL);
	ft_memcpy (temp, src, size);
	ft_memcpy (dst, temp, size);
	free(temp);
	temp = NULL;
	return (dst);
}
