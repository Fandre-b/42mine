/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:22 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/07 13:46:06 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char     *ft_call_specifier(char *str_flags, va_list args);
static int      ft_parse_flags(char **string, char **str_flags);
int             ft_parse_format(char *str_format, va_list args);

int ft_printf(const char *format, ...)
{
    va_list     args;
    int         count;
    char        *str_format;
    
    if (!format)
		return (0);
    str_format = ft_strdup(format);
	if (!str_format)
		return (0);
    va_start(args, format);
        count = ft_parse_format(str_format, args);
    va_end(args);
    free (str_format);
    return (count);
}

int ft_parse_format(char *str_format, va_list args)
{
    char    *str_flags;
    char    *str_formated;
    int     count;

    count = 0;
    while(*str_format)
    {
        while (*str_format && *str_format != '%')
        {            
            ft_putchar_fd(*str_format++, 1);
            count++;
        }
        if (*str_format && *str_format == '%')
        {
            count += ft_parse_flags(&str_format, &str_flags);
            str_formated = ft_call_specifier(str_flags, args);
            ft_putstr_fd(str_formated, 1);
            count += ft_strlen(str_formated);
            free (str_flags);
            free (str_formated);
        }
    }
    return (count);
}

static int ft_parse_flags(char **string, char **str_flags)
{
    int  i;
    const char *str1;
    const char *str2;

    str1 = "cspdiuxX";
    str2 = "-0123456789.# +";
    if (*(++(*string)) == '%')
    {
        ft_putchar_fd(*((*string)++), 1);
        *str_flags = strdup("");
        return (1);
    }
    i = 0;
    while (((*string)[i]) && strchr(str2, (*string)[i]))
      i++;
    if (((*string)[i]) && strrchr(str1, (*string)[i]))
      i++;
    *str_flags = (char *) malloc ((i + 1) * sizeof(char));
    if (!*str_flags)
      return(-1);
    ft_strlcpy(*str_flags, *string, i + 1);
    *string += i;
    return (0);
}

static char    *ft_call_specifier(char *str_flags, va_list args)
{
    printf("flags: %s\nindentifier: %s", str_flags, &str_flags[ft_strlen(str_flags) - 1]);
    return (va_arg(args, char *));
}
