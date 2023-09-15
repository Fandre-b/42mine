/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:52:40 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/15 17:17:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_countsplit(char *str, char *charset, int mode)
{
		int i;
		int	j;
		counter;
		index;
	
	i = 0;
	j = 0;
	index = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (charset[j] != '\0')
		{
			if (mode = 1 && charset[j] == str[i] && (i - index > 1))
				
			else if (mode = 0 && charset[j] == str[i])
				counter++;
			j++;
		}
		index = i++;
	}
	return (counter);
}

int	*ft_srtindex(char *str, char *charset)
{
		int i;
		int	j;
	
	index = (int *)malloc(sizeof(int) * (str, charset, 0))
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (charset[j] != '\0')
		{
			if (charset[j] == *str)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

char	*ft_dupn(char *matrix, char *str , int index)
{
	int		i;

	i = 0;
	while (*str != '\0' && i < index)
	{
		matrix [i] = str[i];
		i++;
	}
	matrix [i] = '\0';
	return matrix;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**matrix = NULL;
	int		index;

	i = 0;
	while (ft_cmpchar(str, charset) > -1)
	{
		index = ft_cmpchar(str, charset);
		matrix[i] = NULL;
		matrix[i] = (char *)malloc(sizeof(char) * (index + 1));
		if (!matrix[i])
			return (NULL);
		ft_dupn(&matrix[i][0], &str[0] , index);
		i++;
	}
		return (matrix);
}

int	main(void)
{
	char	*str = "vamos, ver,.se isto@funciona";
	char 	*sep = ",.";
	char	**dest;
	int		i = 0;
	int		j = 0;

	dest = ft_split(str, sep);
	while (dest[i])
	{
		while(dest[i][j] != '\0')
			write (1, &dest[i][j++], 1);
		i++;
	}
}
