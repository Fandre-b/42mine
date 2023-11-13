/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:18:48 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/13 17:33:46 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	odd_nb;
	int	counter;

	counter = 0;
	odd_nb = 1;
	while (nb > 0)
	{
		nb -= odd_nb;
		odd_nb += 2;
		counter++;
	}
	if (0 == nb)
		return (counter);
	return (0);
}
/*
int	main(void)
{
	int	nbr;

	nbr = 100;
	printf("resultado: %d\n", ft_sqrt(nbr));
}*/
