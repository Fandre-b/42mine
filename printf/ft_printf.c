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

void ft_printf(const char *string, ...)
{
    char    *flags;
    char    *conv;
    va_list args;

    va_start(args, string);
    i = 0;
    while (*str)
    {
        ft_putchar(*str++);
        if (*string++ == '%' && get_flags(&flags, &string) == 1)

            conv = ft_convert(args, flags);
        if (flags)
            free (flags);
        flags = NULL;
    }
    va_end(args);
}//16

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
}//23

char    *ft_convert(va_list args, char *flags)
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
        ft_conv_addr(va_arg(args, (char *)), flags);
    if (type == 'd' || type == 'i')
        ft_conv_num(va_arg(args, (int)), flags);
    if (type == 'u')
        ft_conv_unsigned(va_arg(args, (unsigned int)), flags);
    if (type == 'x' || type == 'X')
        ft_conv_octal(va_arg(args, (int)), flags, type);
    else
        ft_conv_null(flags);
    return (conv);
}//20

t_flags *ft_process_flags(char *str, char *accepted_flags)
{
	t_flags	flags;

    memset(&flags, 0, sizeof(t_flags));
    flags.width = ft_get_width(str);
    while(str[i]) 
    {
        if (strrchr(accepted_flags, str[i]))
        {
            if (str[i] == '0' && !ft_isdigit(str[i - 1]) && !strchr(str, '-'))
                flags.zero = 1;
            if (str[i] == '-')
                flags.left = 1;
            if (str[i] == ' ' && !strchr(str, '+'))
                flags.space = 1;
            if (str[i] == '+')
                flags.plus = 1;
            if (str[i] == '#')
                flags.hash = 1;
            if (str[i] == '.')
                flags.precision = ft_get_precision(str);
        }
    }
    return (flags);
}

int ft_get_precision(char *str)
{
    int len;
    int res;

    len = ft_strlen(str);
    res = 0;
    while (len >= 0 && str[len] != '.')
        len--;
    if (str[len] != '.')
    {
        while(str[++len] && ft_isdigit(str[len]))
            res *= res * 10 + ((str[len]) - 48);
    }
    return (res);
}

int ft_get_width(char *str)
{
    int len;
    int res;

    len = ft_strlen(str);
    res = 0;
    while (len >= 0 && !ft_isdigit(str[len--]))
    {
        while (len >= 0 && ft_isdigit(str[len]))
            len--;
        if(str[len] != '.')
        {
            while(str[++len] && ft_isdigit(str[len]))
               res *= res * 10 + ((str[len]) - 48);
        }
    }
    return (res);
}
//fazer daqui para a frente//
char    *ft_conv_char(char str, flags)
{
    char        *accepted_flags;
    t_flags     *pross_flags;

    accepted_flags = "-0";
    pross_flags = ft_process_flags (flags, accepted_flags);
    return(ft_conv_flag(char, pross_flags));
}

char    *ft_conv_str(va_arg(args, (char *)), flags)
{//tenho de dar free
    char        *accepted_flags;
    t_flags     *pross_flags;
    char        *little;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (flags, accepted_flags);
    little = (char *) malloc (sizeof(char) * (pross_flags->precision + 1));
    if (!little)
        return (NULL);
        //i can do precison =2
    ft_strnstr(str, little, pross_flags->precision);
    pross_flags->precision = 0;
    return(ft_conv_flag(little, pross_flags));
}

ft_conv_addr(va_arg(args, (char *)), flags)
{
    char        *accepted_flags;
    t_flags     *pross_flags;

    accepted_flags = "-0";
    pross_flags = ft_process_flags (flags, accepted_flags);
    return(ft_conv_flag(str, pross_flags))
}

char   *ft_conv_num(va_arg(args, (int)), flags)
{//dar free
    char    *accepted_flags;
    t_flags *pross_flags;
    char    *convertida;

    accepted_flags = "-0. +";
    pross_flags = ft_process_flags (flags, accepted_flags);
    if (num < 0)
    {
        pross_flags->plus = 0;
        pross_flags->space = 0;
    }
    if (pross_flags->precision > 0)
	    pross_flags->zero = 0;
    convertida = ft_strjoin(ft_padd('0', size), ft_atoi(num));
    //change pad to accept string and do join and chose side, and signal
    //order sign-pad (.), pad(0), pad(-), 
    pross_flags->precision = 0;
    return(ft_conv_flag(ft_atoi(num), pross_flags));
}

char    *ft_conv_unsigned(va_arg(args, (unsigned int)), flags)
{
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (flags, accepted_flags);

    //same as num
    return(ft_conv_flag(ft_atoi(num), pross_flags));

}

char    *ft_conv_octal(va_arg(args, (int)), flags, type)
{}

char    *ft_conv_null(flags)
{
    char        *accepted_flags;
    t_flags     *pross_flags;
    //add if type # is 1 or 2
    accepted_flags = "-0";
    pross_flags = ft_process_flags (flags, accepted_flags);
    return(ft_conv_flag("", pross_flags));
}
