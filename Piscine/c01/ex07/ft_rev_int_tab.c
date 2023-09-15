/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:21:57 by fandre-b          #+#    #+#             */
/*   Updated: 2023/07/31 18:22:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;
	int	temp;

	counter = 0;
	while (counter < size - counter)
	{
		temp = tab[counter];
		tab[counter] = tab[size - 1 - counter];
		tab[size - 1 - counter] = temp;
		counter++;
	}
}
/*
int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6};
	int	*array = arr;

	ft_rev_int_tab(array, 6);
	return (0);
}
*/
