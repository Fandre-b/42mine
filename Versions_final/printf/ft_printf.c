/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:11:06 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/11 15:58:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_call_next(const char *format, va_list args);
static int	ft_specifier(const char type, va_list args);
int			ft_putstr(char *str, int do_free);
static int	ft_putchar(int c);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (0);
	va_start(args, format);
	count = ft_call_next(format, args);
	va_end(args);
	return (count);
}

static int	ft_call_next(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += write(1, format++, 1);
			else if (*(format))
				count += ft_specifier(*format++, args);
		}
		else
			count += write(1, format++, 1);
	}
	return (count);
}

static int	ft_specifier(const char type, va_list args)
{
	char	*str_argument;
	int		count;

	str_argument = NULL;
	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *), 0);
	else if (type == 'u')
		str_argument = ft_htoa(va_arg(args, unsigned), type, 10);
	else if (type == 'd' || type == 'i')
		str_argument = ft_itoa(va_arg(args, int), 10);
	else if (type == 'p')
		count += ft_put_adress (va_arg(args, void *));
	else if (type == 'x' || type == 'X')
		str_argument = ft_htoa(va_arg(args, unsigned int), type, 16);
	else
		count += ft_putchar (type);
	if (str_argument)
		count += ft_putstr (str_argument, 1);
	return (count);
}

int	ft_putstr(char *str, int do_free)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	if (do_free)
		free(str);
	return (i);
}

static int	ft_putchar(int c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
}
