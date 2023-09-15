/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:38:15 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 18:09:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	val;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		val = str[i];
		if (val >= 97 && val <= 122)
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	src[] = "Hello World";

	printf("str: '%s' <--- \n", src);
	printf("test str: '%s' <--- \n", ft_strupcase(src));
	return (0);
}*/
