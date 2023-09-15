/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:32:32 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 18:17:35 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if (val >= 32 && val != 127)
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
	char	dest[] = "HelloWorld!";

	printf("str1: '%s' <--- \n", src);
	printf("test str1: '%d' <--- \n", ft_str_is_printable(src));
	printf("str2: '%s' <--- \n", dest);
	printf("test1: '%d' <--- \n", ft_str_is_printable(dest));
	return (0);
}*/
