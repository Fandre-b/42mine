/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:19:49 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 18:18:28 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if (val >= 48 && val <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char	src[] = "Hello World";
	char	dest[] = "456798034";

	printf("str1: '%s' <--- \n", src);
	printf("test str1: '%d' <--- \n", ft_str_is_numeric(src));
	printf("str2: '%s' <--- \n", dest);
	printf("test str2: '%d' <--- \n", ft_str_is_numeric(dest));
	return (0);
}*/
