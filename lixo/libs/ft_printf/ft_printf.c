/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:45:14 by mpais-go          #+#    #+#             */
/*   Updated: 2023/11/16 11:35:52 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_spec(char s, va_list args)
{
	int	count;

	count = -1;
	if (s == 'c')
		count = ft_putchar(va_arg(args, int));
	if (s == 's')
		count = ft_putstr(va_arg(args, char *));
	if (s == 'p')
		count = ft_putadd(va_arg(args, unsigned long int));
	if (s == 'd' || s == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (s == 'u')
		count = ft_putuns(va_arg(args, unsigned int));
	if (s == 'x')
		count = ft_puthexa(va_arg(args, unsigned int), 0);
	if (s == 'X')
		count = ft_puthexa(va_arg(args, unsigned int), 1);
	if (s == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += check_spec(str[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// int main ()
// {
// 	char *ptr = "sou a marta";
// 	int num = 42;
// 	int i;
// 	int j;
// 	i = ft_printf(" %s e %d\n ", "ola", 42);
// 	printf("%c",'\n');
// 	j = printf(" %s e %d\n ", ptr, num);
// 	printf("%c",'\n');
// 	printf("%i",i);
// 	printf("%c",'\n');
// 	printf("%i",j);
// 	return (0);
// }