/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:13:24 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/12 17:26:45 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0')
	{
	}
	return (i - 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenbase;
	int	resto;

	lenbase = str_len(base);
	if (nbr < 0)
	{
		resto = (nbr % lenbase) * (-1);
		nbr = (nbr / lenbase) * (-1);
		write (1, "-", 1);
	}
	else
	{
		resto = (nbr % lenbase);
		nbr = (nbr / lenbase);
	}
	if (0 == nbr && 0 == resto)
	{
		return ;
	}
	write (1, &base[resto], 1);
	ft_putnbr_base(nbr, base);
}
/*
int	main(void)
{
	int		nbr = -2147483648;
	char	*base = "0123456789ABCDEF";

	ft_putnbr_base(nbr, base);
	return (0);
}*/
