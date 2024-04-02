/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:51 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/06 11:17:28 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		words;
	int		i;
	size_t	start;
	size_t	end;

	words = count_words(s, c);
	new = (char **)malloc((words + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	end = 0;
	while (i < words)
	{
		while (s[end] == c && s[end])
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		new[i] = ft_substr(s, start, end - start);
		i++;
	}
	new[i] = NULL;
	return (new);
}

// int main(int argc, char **argv)
// {
// 	char	**split;
// 	int		i;

// 	if (argc == 2)
// 	{
// 		split = ft_split(argv[1], ' ');
// 			printf("%s ", split[0]);
// 		i = 1;
// 		while (split[i] != 0)
// 		{
// 			printf("%s ", split[i]);
// 			i++;
// 		}
// 		printf("%s", split[i]);
// 	}
// 	printf("\n");
//     return (0);
// }
