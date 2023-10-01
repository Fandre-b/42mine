/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:19:16 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 19:24:15 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_ele, size_t size)
{
	void	*dst;

	dst = (void *) malloc (size * n_ele);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size * n_ele);
	return (dst);
}
