/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:53:34 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:58 by fandre-b         ###   ########.fr       */
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

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	if (nb != 5 && nb % 5 == 0)
		return (0);
	i = 1;
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_is_prime(nb) == 0)
	{
		while (nb++)
		{
			if (ft_is_prime(nb))
				return (nb);
		}
	}
	return (nb);
}
/*
int	main(void)
{
	int	nbr = -2147483648;

	printf("Next prime: %d\n", ft_find_next_prime(nbr));
}*/
