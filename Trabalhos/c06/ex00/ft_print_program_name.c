/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:35:46 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/13 14:27:57 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i++], 1);
	}
}

void	ft_print_program_name(char *str)
{
	put_str(str);
}

int	main(int argc, char **argv)
{
	if (argc)
		ft_print_program_name(argv[0]);
	return (0);
}
