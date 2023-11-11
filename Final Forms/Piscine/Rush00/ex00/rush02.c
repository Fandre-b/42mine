/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:29:08 by fandre-b          #+#    #+#             */
/*   Updated: 2023/07/30 16:53:31 by jinhchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

char	check_if(int x, int y, int i, int j)
{
	char	letter;

	if ((i == 0 || i == x - 1) && (j == 0 || j == y - 1))
	{
		if (j == 0)
		{
			letter = 'A';
		}
		else
		{
			letter = 'C';
		}
	}
	else if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
	{
		letter = 'B';
	}
	else
	{
		letter = ' ';
	}
	return (letter);
}

void	compile_line(int x, int y, int j)
{
	char	letter;
	int		i;

	i = 0;
	while (i < x)
	{
		letter = check_if(x, y, i, j);
		ft_putchar(letter);
		i++;
	}
}

void	rush(int x, int y)
{
	char	line;
	int		j;

	line = '\n';
	j = 0;
	while (j < y)
	{
		compile_line(x, y, j);
		ft_putchar(line);
		j++;
	}
}
