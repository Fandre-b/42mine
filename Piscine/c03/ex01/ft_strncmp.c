/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:57:20 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/12 17:53:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	str1[] = "1234567";
	char	str2[] = "123456789";

	printf("strcmp(str1, str2) = %d\n", ft_strncmp(str1, str2, 0));
	printf("strcmp(str1, str2) = %d\n", strncmp(str1, str2, 0));
	return (0);
}*/
