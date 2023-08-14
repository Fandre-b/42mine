/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:28:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 17:59:35 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if (val >= 65 && val <= 90)
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
	char	dest[] = "HELLOWORLD";

	printf("str1: '%s' <--- \n", src);
	printf("test str1: '%d' <--- \n", ft_str_is_uppercase(src));
	printf("str2: '%s' <--- \n", dest);
	printf("test1: '%d' <--- \n", ft_str_is_uppercase(dest));
	return (0);
}*/
