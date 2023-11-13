/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:34:15 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/14 16:17:11 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nbr)
{
	if (nbr < 0)
		return (0);
	if (nbr == 1 || nbr == 0)
		return (1);
	else
		return (nbr * ft_recursive_factorial(nbr - 1));
}
/*
int	main(void)
{
	int	nbr;

	nbr = -10;
	printf("resultado: %d\n", ft_recursive_factorial(nbr));
}*/
