/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:12:00 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/12 15:28:51 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_getnextword(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && c == s[i])
		i++;
	return (i);
}

static char	**ft_getsplitted(const char *s, char **matrix, char c, size_t size)
{
	size_t	index;
	size_t	k;

	index = 0;
	while (s[index] && c == s[index])
		index++;
	k = 0;
	while (k < size)
	{
		matrix[k] = ft_substr(s, index, ft_wordlen(&s[index], c));
		if (!matrix[k++])
		{
			while (k > 0)
				free(matrix[--k]);
			free(matrix);
			return (NULL);
		}
		index += ft_getnextword(&s[index], c);
	}
	matrix[k] = NULL;
	return (matrix);
}

char	**ft_split(const char *s, char c)
{
	char	**matrix;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_countword(s, (char) c);
	matrix = (char **) malloc (sizeof(char *) * (size + 1));
	if (!matrix)
		return (NULL);
	return (ft_getsplitted(s, matrix, (char) c, size));
}
