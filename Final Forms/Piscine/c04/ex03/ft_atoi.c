/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:54:44 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/12 17:23:27 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi(char *str)
{
	int	res;
	int	sig;
	int	i;

	sig = 1;
	res = 0;
	i = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
	{
		str++;
	}
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sig *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sig == 1)
			res = res * 10 + (str[i++] - 48);
		else
			res = res * 10 - (str[i++] - 48);
	}
	return (res);
}
/*
int	main(void)
{
	char	str[] = "          ---+--178783Isto vai ser ignorado42cccc";

	printf("%d\n", ft_atoi(str));
	return (0);
}*/
