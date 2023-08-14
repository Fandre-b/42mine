/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:06:36 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/14 19:06:39 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*res;

	if (min >= max)
	{
		res = NULL;
		return (0);
	}
	if(!(res = (int *)malloc(sizeof(int) * (max - min))))
		return (-1);
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (i);
}
/*
int	main(void)
{
	int	*array;
	int	min = -3;
	int	max = 20;
	int	i;

	printf("Numero de elem no array: %d\n", ft_ultimate_range(&array, min, max));
	i = 0;
	while (i < max - min)
		printf("%d,", array[i++]);
	free (array);
	return (0);
}*/
