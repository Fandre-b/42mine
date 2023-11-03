/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/03 10:41:42 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flags *ft_process_flags(char *str, char *accepted_flags)
{
	t_flags	flags; //maybe allocate if fails to set values

    memset(&flags, 0, sizeof(t_flags)); //flags = {0};
    flags.width = ft_get_width(str);
    while(str[i]) 
    {
        if (strrchr(accepted_flags, str[i]))
        {
            if (str[i] == '0' && !ft_isdigit(str[i - 1]) && !strchr(str, '-') && !strchr(str, '.'))
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
