/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:44:55 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/26 18:44:55 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)(big));
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr_idx(char *str, char ch)
{
	char *save;

	if (!str)
		return (-2);
	save = str;
	while(*str != '\0' && *str != ch)
		str++;
	if (!*str)
		return (-1);
	return (str - save);
}

char	*ft_strnjoin(char *old_str, char *str_add, int size)//this
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	while (old_str && old_str[len])
		len++;
	i = 0;
	while (str_add && str_add[i])
		i++;
	if (i < size || size == -1)
		size = i;
	new_str = (char *) malloc (size + len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (old_str && ++i < len)
		new_str[i] = old_str[i];
	i = -1;
	while (str_add && ++i < size)
		new_str[len + i] = str_add[i];
	new_str[len + i] = '\0';
	free(old_str);
	return (new_str);
}

int ft_strpbrk_idx(char *str, char *chrs)
{
	int i;
	char *save;
	
	if (!chrs || !str)
		return (-2);
	save = str;
	i = 0;
	while(*str)
	{
		i = -1;
		while (chrs[++i])
		{
			if (*str == chrs[i])
				return (str - save);
		}
		str++;
	}
	return (-1);
}

void	**ft_ptrshift(void **ptr, int n_shift)
{//ft_ptrshift
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

void	*ft_strshift(void *ptr, int n_shift)
{
	int		i;
	char	*shifted_str;

	if (!ptr)
		return (ptr);
	shifted_str = (char *) ptr;
	i = -1;
	while (shifted_str[++i + n_shift])
		shifted_str[i] = shifted_str[n_shift + i];
	while (n_shift-- >= 0)
		shifted_str[i++] = '\0';
	return (shifted_str);
}