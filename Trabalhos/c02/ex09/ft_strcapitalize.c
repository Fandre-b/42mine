/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 22:05:45 by fandre-b         ###   ########.fr       */
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

char	*ft_strcapitalize(char *str)
{
	char	val;
	int		i;
	int		space_det;

	ft_strlowcase(str);
	i = 0;
	space_det = 1;
	while (str[i] != '\0')
	{
		val = str[i];
		if (str[i] == 32)
			space_det = 1;
		else if (space_det == 1 && val >= 97 && val <= 122)
		{
			str[i] -= 32;
			space_det = 0;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	src[] = "he1EP1*@llo W23or ld";

	printf("Dest Original: '%s' <--- \n", src);
	ft_strcapitalize(src);
	printf("Dest pos oper: '%s' <--- \n", src);
	return (0);
}*/
