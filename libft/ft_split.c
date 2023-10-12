/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:12:00 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/10 11:21:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_countword(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (c == str[i])
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}	

static int	ft_getnextword(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	while (c == str[i])
		i++;
	return(i);
}

static char	**ft_getsplitted (const char *str, char **matrix, char c, size_t size)
{
	size_t	index;
	size_t	k;

	index = 0;
	while (c == str[index])
		index++;
	k = 0;
	while (k < size)
	{
		matrix[k] = ft_substr(str, index, ft_wordlen(&str[index], c));
		if (!matrix[k++])
			return (NULL);
		index += ft_getnextword(&str[index], c);
	}
	matrix[k] = NULL;
	return(matrix);
}

char	**ft_split(const char *str, char c)
{
	char	**matrix;
	size_t	size;
	
	if (!str)
        	return (NULL);
	size = ft_countword(str, c);
	matrix = (char **) malloc (sizeof (char *) * (size + 1));
	if (!matrix)
		return (NULL);
	return (ft_getsplitted (str, matrix, c, size));
}