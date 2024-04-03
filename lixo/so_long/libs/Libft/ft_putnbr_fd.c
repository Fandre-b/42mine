/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:01:44 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/02 19:01:44 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb_new;

	nb_new = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb_new = -nb_new;
	}
	if (nb_new >= 10)
	{
		ft_putnbr_fd(nb_new / 10, fd);
		nb_new %= 10;
	}
	ft_putchar_fd(nb_new + '0', fd);
}

// int main(void)
// {
//     int fd = 1;
//     int num = 42;

//     ft_putnbr_fd(num, fd);
//     ft_putchar_fd('\n', fd);

//     return 0;
// }