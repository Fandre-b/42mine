/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bublesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:23:45 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/02 15:30:20 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*a;
	int	*b;
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - j)
		{
			a = &tab[i];
			b = &tab[i + 1];
			if (tab[i] > tab[i + 1])
				ft_swap(a, b);
			i++;
		}
		j++;
	}
}
/*
void	print_array(int *array, int n)
{
	int	i;

	printf("{%d,", array[0]);
	i = 1;
	while (i < n)
	{
		printf("%d,", array[i]);
		i++;
	}
	printf("%d}\n", array[i]);
}

int	main(void)
{
	int	arr[] = {6, 4, 2, 1, 9, 10};
	int	*array = arr;

	printf("original array: ");
	print_array(arr, 6);
	ft_sort_int_tab(array, 6);
	printf("sorted array: ");
	print_array(arr, 6);
	return (0);
}
*/
