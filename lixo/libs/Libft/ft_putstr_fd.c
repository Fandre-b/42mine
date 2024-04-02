/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:48 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:48 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

// #include <stdio.h>

// int main() {
//     int fd = 1;

//     ft_putstr_fd("Hello, ", fd);
//     ft_putstr_fd("World!\n", fd);

//     return 0;
// }
