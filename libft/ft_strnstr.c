/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:15:09 by fandre-b          #+#    #+#             */
/*   Updated: 2023/09/17 22:15:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*srtnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	if (!to_find)
		return ((char *)(str));
	i = 0;
	while (str[i] && i < size - 1)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
