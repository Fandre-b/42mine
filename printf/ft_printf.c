/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:22 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/28 17:48:34 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void ft_printf(const char *string, ...)
{
    char    *flags;
    char    *conv;
    va_list args;

    va_start(args, string);
    while (*str)
    {
        ft_putchar(*str++);
        if (*string++ == '%' && get_flags(&flags, &string) == 1)
            conv = ft_call_convert(args, flags);
        if (flags)
            free (flags);
        flags = NULL;
    //Se conv for retornado aqui dar free
        ft_putstr(conv);
        free (conv);
    }
    va_end(args);
}

int get_flags(const char **string, char **flags)
{
    int  i;
    const char *str1;
    const char *str2;

    str1 = "cspdiuxX";
    str2 = "-0123456789.# +";
    i = 0;
    if (*string == '%')
    {
        ft_putchar(*string++);
        return (0);
    }
    while (((*string)[i]) && strchr(str2, (*string)[i]))
    {
        if (strrchr(str1, (*string)[++i]))
            i++;
    }
    *flags = (char *) malloc ((i + 1) * sizeof(char));
    if (!*flags)
      return(0);
    strlcpy(*flags, *string, i);
    *string += i;
    return (1);
}

char    *ft_call_convert(va_list args, char *flags)
{
    char    type;
    char    *conv;
    
    i = 0;
    while (flags[i++])
        type = flags[i];
    if (type == 'c')
        ft_conv_char(va_arg(args, char), flags);
    if (type == 's')
        ft_conv_str(va_arg(args, (char *)), flags);
    if (type == 'p')
        ft_conv_addr(va_arg(args, uintptr_t), flags);
    if (type == 'd' || type == 'i')
        ft_conv_num(va_arg(args, int), flags);
    if (type == 'u')
        ft_conv_unsigned(va_arg(args, unsigned int), flags);
    if (type == 'x' || type == 'X')
        ft_conv_octal(va_arg(args, unsigned int), flags, type);
    else
        ft_conv_str("", flags);
    return (conv);
}

char    *ft_conv_char(char c, flags)
{
	char		*argument[2];

	argument[0] = c;
	argument[1] = '\0';
    return(ft_conv_str(argument, flags););
}
