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

char	**ft_getsplitted(char **matrix, char *str, char c, int size)
{
	int		i;
	int		i_words;

	i_words = 0;
	while (*str && i_words < size)
	{
		i = ft_strchr_idx(str, c);
		if (i >= -1)
		{
			matrix[i_words] = ft_strnjoin(NULL, str, i);
			if (!matrix[i_words])
			{
				while (i_words-- >= 0)
					free (matrix[i_words]);
				free (matrix);
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
	if (size == 0)
		size = 1;
	matrix = (char **) malloc (sizeof(char *) * (size + 1));
	if (!matrix)
		return (NULL);
	else
		matrix = ft_getsplitted(matrix, str, c, size);
	return (matrix);
}

void	join_rm_quotes(char **arg_cmd, char ch, int idx)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (arg_cmd[i] != NULL)
	{
		temp = ft_strnjoin(temp, " ", 1);
		temp = ft_strnjoin(temp, arg_cmd[i], ft_strlen(arg_cmd[i]));
		free (arg_cmd[i++]);
		if (ft_strchr_idx(&(temp[idx + 2]), ch) >= 0)
			break ;
	}
	if (ft_strchr_idx(&temp[idx + 2], ch) > 0)
	{
		ft_strshift(&(temp[idx + 1]), 1);
		ft_strshift(&temp[ft_strchr_idx(temp, ch)], 1);
	}
	*arg_cmd = temp;
	ft_ptrshift((void **)&arg_cmd[1], i - 1);
	return ;
}

void	rejoin_quoted_args(char **arg_cmd)
{
	int		idx;
	char	ch;

	while ((*arg_cmd != NULL))
	{
		idx = ft_strpbrk_idx(*arg_cmd, "\"\'");
		if (idx >= 0)
		{
			ch = (*arg_cmd)[idx];
			join_rm_quotes(arg_cmd, ch, idx);
		}
		else
			arg_cmd++;
	}
	return ;
}
