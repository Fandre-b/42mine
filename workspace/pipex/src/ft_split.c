/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:39:33 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/27 21:39:33 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_countword(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && c == str[i])
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

char	**ft_getsplitted(char **matrix, char *str, char c, int size)
{
	int		i;
	int		i_words;

	i_words = 0;
	while (*str && i_words < size)
	{
		i = ft_strchr_index(str, c);
		if (i > 0)
		{
			matrix[i_words] = ft_strnjoin(NULL, str, i);
			if (!matrix[i_words])
			{
				while (i_words-- >= 0)
					free(matrix[i_words]);
				free(matrix);
				return (NULL);
			}
			i_words++;
		}
		str = str + i + 1;
	}
	matrix[i_words] = NULL;
	return (matrix);
}

char	**ft_split(char *str, char c)
{
	char	**matrix;
	int		size;

	if (!str)
		return (NULL);
	size = ft_countword(str, c);
	matrix = (char **) malloc (sizeof(char *) * (size + 1));
	if (!matrix)
		return (NULL);
	matrix = ft_getsplitted(matrix, str, c, size);
	return (matrix);
}