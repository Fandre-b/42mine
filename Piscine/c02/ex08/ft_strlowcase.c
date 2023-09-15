/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:57:19 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 18:12:57 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if (val >= 65 && val <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	src[] = "Hello World";

	printf("str1: '%s' <--- \n", src);
	printf("test str1: '%s' <--- \n", ft_strlowcase(src));
	return (0);
}*/
