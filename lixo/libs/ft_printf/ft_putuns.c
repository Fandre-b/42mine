/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:43:54 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/18 10:42:32 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	int				count;
	unsigned int	aux;

	aux = n;
	if (n >= 10)
	{
		ft_putuns(n / 10);
		n %= 10;
	}
	ft_putchar(n + 48);
	count = 0;
	while (aux >= 10)
	{
		aux /= 10;
		count++;
	}
	count++;
	return (count);
}
