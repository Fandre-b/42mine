/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:25:40 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/19 12:43:32 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long int nbr, int isup)
{
	unsigned long int	aux;
	int					count;

	aux = nbr;
	if (nbr >= 16)
		ft_puthexa(nbr / 16, isup);
	if (isup)
		ft_putchar(HEX_UPPER[nbr % 16]);
	else
		ft_putchar(HEX_LOWER[nbr % 16]);
	count = 0;
	while (aux >= 16)
	{
		aux /= 16;
		count++;
	}
	count++;
	return (count);
}
