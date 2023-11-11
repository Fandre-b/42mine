/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:06:36 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/15 17:44:39 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strmatrixlen(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i++]);
	}
	len += ft_strlen(sep) * size - 2 + 1;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	if (dest[0])
	{
		while (dest[i] != '\0')
		{
			i++;
		}
	}
	n = i;
	while (src[i - n] != '\0')
	{
		dest[i] = src[i - n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		len;
	int		i;

	if (sep == NULL)
		return (NULL);
	len = ft_strmatrixlen(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * len);
	if (!(dest))
		return (NULL);
	dest[0] = '\0';
	i = 0;
	while (i < size)
	{
		dest = ft_strcat(dest, strs[i++]);
		if (i < size)
			dest = ft_strcat(dest, sep);
	}
	return (dest);
}
/*
int	main(void)
{
	char	*strs[] = {"isfsf", "sfsfa", "sfdf"};
	char	*sep = ", ,";
	char	*dest;
	int	size = 3;

	dest = ft_strjoin(size, strs, sep);
	printf("%s\n", dest);
	free(dest);
	dest = NULL;
	return (0);
}*/
