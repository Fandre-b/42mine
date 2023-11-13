/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:17:57 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/12 23:55:48 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_conv_char(int argument, char *str_flags)
{
    char    *new_str;
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (str_flags, accepted_flags);
    new_str = (char *)malloc(sizeof(char) * 2);
    if (!new_str)
        return (-1);
    new_str[0] = (char)argument;
    new_str[1] = '\0';
    if (pross_flags->precision == 0)
        pross_flags->print_null = 0;
    else if (argument == 0)
        pross_flags->print_null = 1;
    return (ft_print_wflags (new_str, pross_flags));
}

int     ft_conv_str(char *argument, char *str_flags)
{
    char    *new_str;
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (str_flags, accepted_flags);
    if (!argument)
        new_str = ft_strdup("(null)");
    else if (pross_flags->precision >= 0)
	{
    	new_str = ft_substr(argument, 0, pross_flags->precision);
    	pross_flags->precision = -1;
	}
    else
        new_str = ft_strdup(argument);
    return (ft_print_wflags (new_str, pross_flags));
}

int     ft_conv_itoa(long long argument, char *str_flags)
{
    char    *new_str;
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0. +";
    pross_flags = ft_process_flags (str_flags, accepted_flags);
    if (!argument)
        new_str = ft_strdup("0");
    else
        new_str = ft_itoa_base(argument, 10);
    if (argument <= 0)
    {
        pross_flags->plus = 0;
        pross_flags->space = 0;
    }
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    return (ft_print_wflags (new_str, pross_flags));
}

int     ft_conv_utoa(unsigned long long argument, char *str_flags, char type)
{
    char    *new_str;
    char    *accepted_flags;
    t_flags *pross_flags;
    
    accepted_flags = "-0.#";
    pross_flags = ft_process_flags (str_flags, accepted_flags);
    if (!argument)
        new_str = ft_strdup("0");
    else if (ft_strchr("xX", type))
        new_str = ft_utoa_base(argument, type, 16);
    else
    {
        new_str = ft_utoa_base(argument, type, 10);
        pross_flags->hash = 0;
    }
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    return (ft_print_wflags (new_str, pross_flags));
}

int     ft_conv_adress(void *argument, char *str_flags, char type)
{
    char    *new_str;
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (str_flags, accepted_flags);
    if (!argument)
    {    
        new_str = ft_strdup("(nil)");
        //new_str = ft_strdup("0x0");
    }
    else
        new_str = ft_utoa_base((unsigned long long)argument, type, 16);
    pross_flags->hash = 1;
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    return (ft_print_wflags (new_str, pross_flags));
}
