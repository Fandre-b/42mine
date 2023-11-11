/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:17 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/11 13:24:06 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_free(char *str, int do_free);
int     ft_parse_format(char *format, va_list args);
void    ft_parse_flags(char **format, char **flags);
int     ft_print_arg(char *flags, va_list args, char type);

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

int     ft_parse_format(char *format, va_list args)
{   
    char    *flags;
    int     count;
    char    type;

    count = 0;
    while (*format)
    {
        if (*format == '%' && *(++format) != '%')
        {
            format ++;
            ft_parse_flags(&format, &flags);
            count += ft_print_arg(flags, args, type);
            free (flags);
        }
        if (*format)
            count += ft_putchar_fd(*format++, 1);
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

int     ft_print_arg(char *flags, va_list args, char type)
{
    char    *str_argument;
	int		count;

    count = 0;
	str_argument = NULL;
    type = flags[ft_strlen(flags) - 1];
    if (type == 'c')
        str_argument = ft_conv_char(va_arg(args, int));//
    else if (type == 's')
        str_argument =  ft_conv_str(va_arg(args, char *));//
    else if (type == 'u')
        str_argument = ft_conv_utoa(va_arg(args, unsigned), type);//
    else if (type == 'd' || type == 'i')
        str_argument = ft_conv_itoa(va_arg(args, int));//
	else if (type == 'p')
        str_argument = ft_conv_utoa((unsigned long long)va_arg(args, void *), type);
    else if (type == 'x' || type == 'X')
		str_argument = ft_conv_utoa(va_arg(args, unsigned int), type);
    else
        str_argument = ft_conv_str("");
	if (str_argument)
		count += ft_putstr_free(str_argument, 1);
	return (count);
}

static int	ft_putstr_free(char *str, int do_free)
{
	int	i;
    int count;

	i = 0;
    count = 0;
	if (!str)
        return (write(1, "(null)", 6));
	while (str[i])
		count += write(1, &str[i++], 1);
	if (do_free)
		free(str);
	return (count);
}
