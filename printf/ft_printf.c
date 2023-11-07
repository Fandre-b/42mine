/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:22 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/04 18:04:03 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *ft_call_specifier(char *str_flags, va_list args)
{
    char    type;
    char    *str_formated;
    
    type = str_flags[ft_strlen(str_flags) - 1];
    if (type == 'c')
        str_formated = ft_conv_char(va_arg(args, int), str_flags);
    else if (type == 's')
        str_formated = ft_conv_str(va_arg(args, char *), str_flags);
    else if (type == 'p')
        str_formated = ft_conv_addr(va_arg(args, unsigned long int), str_flags);
    else if (type == 'd' || type == 'i')
        str_formated = ft_conv_num(va_arg(args, int), str_flags);
    else if (type == 'u')
        str_formated = ft_conv_unsigned(va_arg(args, unsigned int), str_flags);
    else if (type == 'x' || type == 'X')
        str_formated = ft_conv_octal(va_arg(args, unsigned int), str_flags, type);
    else
        str_formated = ft_conv_str("", str_flags);
    return (str_formated);
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
      return(0);
    ft_strlcpy(*str_flags, *string, i + 1);
    *string += i;
    return (0);
}

static int ft_parse_format(char *string, va_list args)
{
    char    *str_flags;
    char    *str_formated;
    int     count;

    count = 0;
    while (*string)
    {
        ft_putchar_fd(*string++, 1);
        count++;
        if (*string && *string == '%')
        {
            count += ft_parse_flags(&string, &str_flags);
            if (!str_flags)
                return (0);
            str_formated = ft_call_specifier(str_flags, args);
            if (!str_formated)
                return(0);
            count += ft_strlen(str_formated);
            ft_putstr_fd(str_formated, 1);
            free (str_flags);
            free (str_formated);
        }
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    char    *string;
    int     check;

    if (!format)
		return (0);
    string = ft_strdup(format);
	if (!string)
		return (0);
    va_start(args, format);
        check = ft_parse_format(string, args);
    va_end(args);
    free(string);
    return (check);
}

char    *ft_conv_char(char c, char *str_flags)
{
	char		*argument;
    char        *res;

    if (!c)
        argument = ft_strdup("(null)");
    else
	    argument = (char *) malloc (2 * sizeof(char));
    if (!argument) 
        return (NULL);
    argument[0] = (char) c;
    argument[1] = '\0';
    res = ft_conv_str(argument, str_flags);
    free(argument);
    return(res);
}
/*char    *ft_conv_char(char c, char *str_flags)
{
    char        *accepted_flags;
    t_flags     pross_flags;
	char        *res;
    char *argument

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (str_flags, accepted_flags);
    char *argument = (char *) malloc (2 * sizeof(char));
    if (!argument) 
        return (NULL)
    argument[0] = (char)c;
    argument[1] = '\0';
	if (pross_flags.precision >= 0)
	{    	
    	res = ft_substr(argument, 0, pross_flags.precision);
    	pross_flags.precision = 0;
	}
	else
		res = argument;
    free (argument);
    return(ft_conv_wflags(res, pross_flags));
}*/