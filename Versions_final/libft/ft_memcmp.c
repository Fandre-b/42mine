/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:05:32 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:32:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*chr_s1;
	const char	*chr_s2;

	if (n == 0)
		return (0);
	chr_s1 = (char *) s1;
	chr_s2 = (char *) s2;
	i = 0;
	while (i < n - 1 && chr_s1[i] == chr_s2[i])
		i++;
	return ((unsigned char) chr_s1[i] - (unsigned char) chr_s2[i]);
}
