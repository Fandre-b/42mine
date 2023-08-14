/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:05:10 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/12 15:37:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	con;

	con = 0;
	while (str[con] != '\0')
	{
		con++;
	}
	return (con);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	res;
	
	i = 0;
	res = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	j = len_dest;
	if (size > len_dest)
		res = len_src + len_dest;
	else
		res = len_src + size; //cheack if i can concat
	while (src[i] != '\0' && i < (size - len_dest - 1))
	{
		dest[j++] = src[i++];
	}
	dest[j] = '\0';
	return (res);
}
/*
int main (void)
{
	char src[] = "Born to live";
	char dest[] = "2024 42";

	printf("%d \n", ft_strlcat(dest, src, 13));
	printf("%s \n", dest);
}*/
