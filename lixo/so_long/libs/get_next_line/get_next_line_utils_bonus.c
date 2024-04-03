/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:41:50 by mpais-go          #+#    #+#             */
/*   Updated: 2023/11/23 20:16:25 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		new[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

void	ft_clean_buff(char *buffer, int *flag, int *flag2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buffer[i])
	{
		if (*flag2 == 1 && *flag == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (*flag2 == 1 && buffer[i] == '\n')
			*flag = 1;
		buffer[i] = 0;
		i++;
	}
}
