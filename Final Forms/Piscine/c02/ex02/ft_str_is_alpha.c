/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:42:36 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 17:28:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122) || val == 32)
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
	char	dest[] = "mjjsdiuaj^@123T#Y&#Hnjn";

	printf("str1: '%s' <--- \n", src);
	printf("test str1: '%d' <--- \n", ft_str_is_alpha(src));
	printf("str2: '%s' <--- \n", dest);
	printf("test str2: '%d' <--- \n", ft_str_is_alpha(dest));
	return (0);
}*/
