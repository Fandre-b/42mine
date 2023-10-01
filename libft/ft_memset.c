/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:54:20 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 20:12:29 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *str, int c, size_t size)
{
	char	*char_str;

	char_str = (char *) str;
	while (size > 0)
		char_str[--size] = (char) c;
	return (str);
}
