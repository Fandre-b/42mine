/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:17:57 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/11 11:44:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_conv_char(int c)
{
    char    *str_char;
    char    *new_str;

    str_char = (char *)malloc(sizeof(char) * 2);
    str_char[0] = (char)(c);
    str_char[1] = '\0';
    new_str = ft_conv_str (str_char);
    free(str_char);
    return (new_str);
}

char    *ft_conv_str(char *argument)
{
    char    *new_str;
    //char    *accepted_flags;
    //t_flags pross_flags;

    //accepted_flags = "-0.";
    //pross_flags = ft_process_flags (flags, accepted_flags);
    if (!argument)
        new_str = ft_strdup("(nill)");
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
    char    *apaga;
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
    if (type == 'p')
    {    
        apaga = ft_strjoin("0x", new_str);//apagar
        free(new_str); //apagar
    }
    /*
        pross_flags->hash = 1;
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    new_str = ft_apply_flags(new_str);*/
    return (new_str);
}

//regras a add.
////se tiver side zero=0
////
