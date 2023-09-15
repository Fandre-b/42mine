/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:52:06 by fandre-b          #+#    #+#             */
/*   Updated: 2023/07/30 13:52:45 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int val)
{
	char	letter;

	if (val < 0)
	{
		letter = 'N';
	}
	else
	{
		letter = 'P';
	}
	ft_putchar(letter);
}
/*
int	main(void)
{
	int val;
	val = -10;
	ft_is_negative(val);
	return (0);
}
*/
