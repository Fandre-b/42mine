/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/13 00:02:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags *ft_flag_intialize(void);
static int ft_get_precision(char *str_flags);
static int ft_get_width(char *str_flags);

t_flags     *ft_process_flags(char *str_flags, char *accepted_flags)
{
	t_flags     *flags;
    int         i;

    flags = ft_flag_intialize();
    flags->precision = ft_get_precision(str_flags);
    flags->width = ft_get_width(str_flags);
    i = 0;
    while(str_flags[i]) 
    {
        if (ft_strrchr(accepted_flags, str_flags[i]))
        {
            if (str_flags[i] == '0' && !ft_isdigit(str_flags[i - 1]))
                flags->zero = 1;
            else if (str_flags[i] == '-')
                flags->left = 1;
            else if (str_flags[i] == ' ' && !ft_strchr(str_flags, '+'))
                flags->space = 1;
            else if (str_flags[i] == '+')
                flags->plus = 1;
            else if (str_flags[i] == '#')
                flags->hash = 1;    
        }
        i++;
    }
    return (flags);
}

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
        if(len == -1  || str_flags[len] != '.')
        {
            if(str_flags[len + 1] != '0')
              break;
        }
    }
    while(str_flags[++len] && ft_isdigit(str_flags[len]))
      res = res * 10 + (str_flags[len] - '0');
      
    return (res);
}

static t_flags *ft_flag_intialize(void)
{
    t_flags *flags;

    flags = (t_flags *)malloc(sizeof(t_flags));
    if (!flags)
        return (NULL);
    flags->width = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->precision = 0;
	flags->zero = 0;
	flags->left = 0;
    flags->print_null = 0;
    return (flags);
}

