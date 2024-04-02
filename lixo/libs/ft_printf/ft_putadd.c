/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:53:01 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/19 12:58:29 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long int nbr)
{
	int	count;

	if (!nbr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthexa(nbr, 0);
	return (count);
}
