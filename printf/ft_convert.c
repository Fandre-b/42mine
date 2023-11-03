/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:52:25 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/03 10:52:27 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char    *ft_conv_str(char *argument, char *flags)
{
    char        *accepted_flags;
    t_flags     *pross_flags;
	char        *res;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (flags, accepted_flags);
	if (pross_flags->precision >= 0)
	{    	
    	res = ft_substr(argument, pross_flags->precision);
    	pross_flags->precision = 0;
	}
	else
		res = argument;
    return(ft_conv_flag(res, pross_flags));
}

ft_conv_addr(uintptr_t argument, char *flags)
{
    char        *accepted_flags;
    t_flags     *pross_flags;
	int		argument;

    accepted_flags = "-0.#";
    pross_flags = ft_process_flags (flags, accepted_flags);
    return(ft_conv_flag("not working still"))
}

char   *ft_conv_num(int argument, char *flags)
{
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0. +";
    pross_flags = ft_process_flags (flags, accepted_flags);
    if (argument <= 0)
    {
        pross_flags->plus = 0;
        pross_flags->space = 0;
    }
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    return(ft_conv_wflags(ft_itoa(argument), pross_flags));
}

char    *ft_conv_unsigned(unsigned int argument, char *flags)
{
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (flags, accepted_flags);
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    return(ft_conv_wflags(ft_utoa(argument), pross_flags));
}

char    *ft_conv_octal(unsigned int argument, char *flags, char type)
{
    char    *accepted_flags;
    t_flags *pross_flags;

    accepted_flags = "-0.";
    pross_flags = ft_process_flags (flags, accepted_flags);
    if (pross_flags->precision >= 0)
	    pross_flags->zero = 0;
    return(ft_conv_wflags(ft_htoa(argument, type), pross_flags));
}
