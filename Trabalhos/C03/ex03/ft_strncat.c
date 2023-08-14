/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:18:59 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/08 16:33:54 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	n = i;
	while (src[i - n] != '\0' && (i - n < nb))
	{
		dest[i] = src[i - n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	dest[20] = "123456789";
	char	src[] = "123456789";

	printf("ft_strncat(dest, src) = %s\n", ft_strncat(dest, src, 3));
	return (0);
}*/
