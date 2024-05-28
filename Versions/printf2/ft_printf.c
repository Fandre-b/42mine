/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:17 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/13 09:12:53 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_print_arg(char *flags, va_list args);
int     ft_parse_format(char *format, va_list args);
void    ft_parse_flags(char **format, char **flags);
int     ft_putstr_free(char *str, int do_free);

int     ft_printf(const char *format, ...)
{
    va_list args;
    char    *str_format;
    int     count;

    if (!format)
        return (-1);
    str_format = ft_strdup(format);
    if (!str_format)
        return(-1);
    va_start(args, format);
    count = ft_parse_format(str_format, args);
    va_end(args);
    free (str_format);
    return (count);
}

int	ft_parse_format(char *format, va_list args)
{
    char    *flags;
	int	    count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += write(1, format++, 1);
			else if (*(format))
            {
                ft_parse_flags(&format, &flags);
                count += ft_print_arg(flags, args);
                free (flags);
            }
		}
		else
			count += write(1, format++, 1);
	}
	return (count);
}

void    ft_parse_flags(char **format, char **flags)
{
    char    *specifiers;
    char    *used_flags;
    int     i;

    i = 0;
    specifiers = "cspdiuxX";
    used_flags = "-0123456789.# +";
    while (((*format)[i]) && ft_strchr(used_flags, (*format)[i]))
      i++;
    if (((*format)[i]) && ft_strrchr(specifiers, (*format)[i]))
      i++;
    *flags = ft_substr(*format, 0, i);
    *format += i;
    return ;
}

int     ft_print_arg(char *str_flags, va_list args)
{
	int		count;
    char    type;

    while (*str_flags)
        type = *str_flags++;
    count = 0;
    if (type == 'c')
        count += ft_conv_char(va_arg(args, int), str_flags);
    else if (type == 's')
        count +=  ft_conv_str(va_arg(args, char *), str_flags);
    else if (type == 'd' || type == 'i')
        count += ft_conv_itoa(va_arg(args, int), str_flags);
    else if (type == 'u')
        count += ft_conv_utoa(va_arg(args, unsigned), str_flags, type);
    else if (type == 'x' || type == 'X')
		count += ft_conv_utoa(va_arg(args, unsigned int), str_flags, type);
	else if (type == 'p')
        count += ft_conv_adress(va_arg(args, void *), str_flags, type);
    else
        count += ft_conv_str("", str_flags);
	return (count);
}
