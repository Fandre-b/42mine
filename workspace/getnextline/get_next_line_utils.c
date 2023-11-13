/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:09:00 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/13 21:21:27 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *ft_strnjoin(char *old_str, char *str_add, int size)
{
    char    *new_str;
    int        i;

    i = 0;
    while (old_str[i])
        i++;
    new_str = (char *)malloc(sizeof(char) * (i + size + 1));
    if (!new_str)
        return (NULL);
    new_str[i + size] = '\0';
    while (size-- >= 0)
        new_str[i + size] = str_add[size];
    while (--i >= 0)
        new_str[i] = old_str[i];
    return (new_str);
}

char	*ft_strchr(char *str, char c)
{
    int		i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    if (str[i] == '\0')
        return (&str[i]);
    return (&str[i + 1]);
}

char	*ft_clearbuffer(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && i != (BUFFER_SIZE + 1))
		str[i++] = '\0';
	return (str);
}
