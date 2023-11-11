/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:29:08 by fandre-b          #+#    #+#             */
/*   Updated: 2023/07/30 13:35:57 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	letter;

	letter = 48;
	while (letter <= 57) 
	{
		ft_putchar(letter);
		letter++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
