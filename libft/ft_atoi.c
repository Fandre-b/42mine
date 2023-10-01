/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:02:13 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/01 15:21:04 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi(const char *str)
{
	int	nbr;
	int	sign;

	sign = 1;
	nbr = 0;
	while (*str > 8 && *str < 14 && *str == 32)
		str++;
	while (*str == 43 || *str == 45)
	{
		if(*str == 45)
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (sign >= 0)
			nbr = (nbr * 10) + *str;
		else
			nbr = (nbr * 10) - *str;
	}
}
