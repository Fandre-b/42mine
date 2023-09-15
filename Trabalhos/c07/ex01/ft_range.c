/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:06:36 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/14 19:07:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int N;
    int i;
    int *range;

	if (min >= max)
		return (NULL);
	N = max - min;
	if(!(range = (int *)malloc(sizeof(int) * (N))))
		return (NULL);
	i = 0;
	while (i < N)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
int main(void)
{
	int	*array;
	int	min = -10;
	int	max = 20;
	int	i;

	array = ft_range(min, max);
	i = 0;
	while (i < max - min)
		printf("%d,", array[i++]);
	free (array);
	return (0);
}*/
