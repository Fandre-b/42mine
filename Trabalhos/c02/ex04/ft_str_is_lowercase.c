/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:24:52 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 17:56:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if (val >= 97 && val <= 122)
			i++;
		else
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char	src[] = "HelloWorld";
	char	dest[] = "helloworld";

	printf("str1: '%s' <--- \n", src);
	printf("test str1: '%d' <--- \n", ft_str_is_lowercase(src));
	printf("str2: '%s' <--- \n", dest);
	printf("test str2: '%d' <--- \n", ft_str_is_lowercase(dest));
	return (0);
}*/
