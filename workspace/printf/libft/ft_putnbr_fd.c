/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:35:15 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/09 09:56:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr_fd("-2", fd);
		ft_putnbr_fd (147483648, fd);
	}
	else if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		ft_putnbr_fd (-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	else
		i += ft_putchar_fd(n % 10 + '0', fd);
	return (i);
}
