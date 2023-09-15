/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:43:50 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/08 16:31:29 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	n = i;
	while (src[i - n] != '\0')
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
	char	dest[20] = "";
	char	src[] = "asdasfa";

	printf("ft_strcat(dest, src) = %s\n", ft_strcat(dest, src));
	return (0);
}*/
