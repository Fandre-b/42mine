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

static int ft_get_precision(char *str_flags)
{
    int len;
    int res;

    len = ft_strlen(str_flags);
    res = -1;
    while (len >= 0 && str_flags[len] != '.')
        len--;
    if (str_flags[len] == '.')
    {
        res = 0;
        while(str_flags[++len] && ft_isdigit(str_flags[len]))
            res = (res * 10 + (str_flags[len] - '0'));
    }
    return (res);
}

static int ft_get_width(char *str_flags)
{
    int len;
    int res;

    len = ft_strlen(str_flags);
    res = 0;
    while (len >= 0)
    {
        while (len >= 0 && !ft_isdigit(str_flags[len]))
            len--;
        while (len >= 0 && ft_isdigit(str_flags[len]))
            len--;
        if(str_flags[len] && str_flags[len] != '.')
        {
            if(str_flags[len + 1] != '0')
              break;
        }
    }
    while(str_flags[++len] && ft_isdigit(str_flags[len]))
      res = res * 10 + (str_flags[len] - '0');
    return (res);
}

t_flags ft_process_flags(char *str_flags, char *accepted_flags)
{
	t_flags	flags;
    int i;

    memset(&flags, 0, sizeof(t_flags));
    flags.width = ft_get_width(str_flags);
    i = 0;
    while(str_flags[i]) 
    {
        if (strrchr(accepted_flags, str_flags[i]))
        {
            if (str_flags[i] == '0' && !ft_isdigit(str_flags[i - 1]) && !strchr(str_flags, '-') && !strchr(str_flags, '.'))
                flags.zero = 1;
            if (str_flags[i] == '-')
                flags.left = 1;
            if (str_flags[i] == ' ' && !strchr(str_flags, '+'))
                flags.space = 1;
            if (str_flags[i] == '+')
                flags.plus = 1;
            if (str_flags[i] == '#')
                flags.hash = 1;
            if (str_flags[i] == '.')
                flags.precision = ft_get_precision(str_flags);
        }
    }
    return (flags);
}
