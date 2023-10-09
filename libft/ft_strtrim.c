/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:02:59 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/06 22:31:44 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	while (j > 0 && ft_strchr(set, str[j]))
		j--;
	return (ft_substr(str, i, j - i + 1));
}
