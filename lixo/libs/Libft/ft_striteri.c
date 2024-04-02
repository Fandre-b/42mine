/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:02:16 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:02:16 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}

// #include <stdio.h>

// void print_index_char(unsigned int index, char *character)
// {
//     printf("Index: %u, Character: %c\n", index, *character);
// }

// int main(void)
// {
//     char str[] = "Hello, World!";

//     ft_striteri(str, print_index_char);
//     return 0;
// }
