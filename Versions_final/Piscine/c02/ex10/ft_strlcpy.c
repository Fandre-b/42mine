/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:53:32 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 22:07:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len;
	int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if ((size - dest_len - 1) >= src_len)
	{
		ft_strcat(dest, src);
		return (dest_len + src_len);
	}
	else
		return (size + src_len);
}

/*
int	main(void)
{
	char	src[] = "Hello World";
	char	dest[20] = {"nnnnnnnnnnnnnnnnnnnn"};
	int	val;

	printf("Dest Original: '%s' <--- \n", dest);
	val = ft_strlcat (dest, src, 8);
	printf("Dest pos oper: '%s' <--- \n", dest);
	printf("output: '%d' <--- \n", val);
	return (0);
}*/