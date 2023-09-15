/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:23:04 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/08 16:28:25 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main()
{
	char	str1[] = "ab";
	char	str2[] = "aba";

	printf("strcmp(str1, str2) = %d\n", ft_strcmp(str1, str2));
	printf("strcmp(str1, str2) = %d\n", strcmp(str1, str2));
	return (0);
}*/
