/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:39 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:39 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>

// int main() {
//     int fd = 1;

//     ft_putchar_fd('H', fd);
//     ft_putchar_fd('e', fd);
//     ft_putchar_fd('l', fd);
//     ft_putchar_fd('l', fd);
//     ft_putchar_fd('o', fd);

//     return 0;
// }