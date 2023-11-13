/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:17:57 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/12 20:43:49 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_conv_char(va_list args)
{
    char    *str_char;
    char    *new_str;
    int     argument;
    int     count;

    count = 0;
    argument = va_arg(args, int);
    str_char = (char *)malloc(sizeof(char) * 2);
    if (argument == 0)
        count += write(1, "", 1);
    str_char[0] = (char)argument;
    str_char[1] = '\0';
    new_str = ft_conv_str (str_char);
    count += ft_putstr_free(new_str, 1);
    free(str_char);
    return (count);
}

char    *ft_conv_str(char *argument)
{
    char    *new_str;
    //char    *accepted_flags;
    //t_flags pross_flags;

    //accepted_flags = "-0.";
    //pross_flags = ft_process_flags (flags, accepted_flags);
    if (argument == NULL)
        new_str = ft_strdup("(null)");
    /*
    else if (pross_flags->precision >= 0)
	{
    	new_str = ft_substr(argument, 0, pross_flags->precision);
    	pross_flags->precision = 0;
	}*/
    else
        new_str = ft_strdup(argument);
    //new_str = ft_apply_flags(new_str);
    return (new_str);
}

char    *ft_conv_itoa(long long argument)
{
    char    *new_str;
    //char    *accepted_flags;
    //t_flags *pross_flags;

    //accepted_flags = "-0. +";
    //pross_flags = ft_process_flags (flags, accepted_flags);
    if (!argument)
        new_str = ft_strdup("0");
    else
        new_str = ft_itoa_base(argument, 10);
    /*
    if (argument <= 0)
    {
        pross_flags->plus = 0;
        pross_flags->space = 0;
    }
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    new_str = ft_apply_flags(new_str);*/
    return(new_str);
}

char    *ft_conv_utoa(unsigned long long argument, char type)
{
    char    *new_str;
    //char    *accepted_flags;
    //t_flags *pross_flags;
    
    //accepted_flags = "-0.#";
    //pross_flags = ft_process_flags (flags, accepted_flags);
    if (!argument)
        new_str = ft_strdup("0");
    else if (ft_strchr("xXp", type))
        new_str = ft_utoa_base(argument, type, 16);
    else
    {
        new_str = ft_utoa_base(argument, type, 10);
        //pross_flags->hash = 0;
    }
    /*
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    new_str = ft_apply_flags(new_str);*/
    return (new_str);
}

char    *ft_conv_adress(void *argument, char type)
{
    char    *new_str;
    char    *apaga;

    //accepted_flags = "-0.";
    //pross_flags = ft_process_flags (flags, accepted_flags);
    if (!argument)
    {    
        //new_str = ft_strdup("(nil)");
        new_str = ft_strdup("0x0");
        return (new_str);
    }
    apaga = ft_utoa_base((unsigned long long)argument, type, 16);
    new_str = ft_strjoin("0x", apaga);
    free(apaga);
    /*
    pross_flags->hash = 1;
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    new_str = ft_apply_flags(new_str);*/
    return (new_str);
}
