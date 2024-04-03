/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:39:12 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/13 17:39:12 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int n)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = n;
	if (tmp == 0)
		return (1);
	if (tmp < 0)
	{
		tmp *= -1;
		len++;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	nb_new;
	int		count;

	nb_new = n;
	count = ft_numlen(n);
	if (n < 0)
	{
		ft_putchar('-');
		nb_new = -nb_new;
	}
	if (nb_new >= 10)
	{
		ft_putnbr(nb_new / 10);
		nb_new %= 10;
	}
	ft_putchar(nb_new + 48);
	return (count);
}
