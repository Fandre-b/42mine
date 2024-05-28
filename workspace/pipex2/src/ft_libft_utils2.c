/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:08:07 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/10 11:08:07 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_strshift(void *ptr, int n_shift)
{
	int		i;
	int		len;
	char	*shifted_str;

	if (!ptr)
		return (ptr);
	shifted_str = (char *) ptr;
	i = 0;
	len = ft_strlen(ptr);
	while (shifted_str[i + n_shift])
	{
		shifted_str[i] = shifted_str[n_shift + i];
		i++;
	}
	while (i != len)
		shifted_str[i++] = '\0';
	return (shifted_str);
}

int	ft_strchr_idx(char *str, char ch)
{
	char	*save;

	if (!str || !ch)
		return (-2);
	save = str;
	while (*str != '\0' && *str != ch)
		str++;
	if (!*str)
		return (-1);
	return (str - save);
}

int	ft_strpbrk_idx(char *str, char *chrs)
{
	int	i;
	int	j;

	if (!chrs || !str)
		return (-2);
	j = 0;
	while (str[j] != '\0')
	{
		i = 0;
		while (chrs[i] != '\0')
		{
			if (str[j] == chrs[i++])
				return (j);
		}
		j++;
	}
	return (-1);
}

void	**ft_ptrshift(void **ptr, int n_shift)
{
	int		i;
	void	**shifted_str;

	if (!ptr)
		return (ptr);
	shifted_str = ptr;
	i = -1;
	while (shifted_str[++i + n_shift])
		shifted_str[i] = shifted_str[n_shift + i];
	while (n_shift-- >= 0)
		shifted_str[i++] = NULL;
	return (shifted_str);
}
